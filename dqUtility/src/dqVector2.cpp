#include <assert.h>

#include "dqVector2.h"
#include "dqVector2i.h"
#include "dqPlatformMath.h"

#define Math PlatformBaseMath

namespace dqEngineSDK
{
  Vector2::Vector2()
  {
  }
  Vector2::Vector2(DEF_INIT::E)
  {
    //TODO: Hago una evaluación primero, o una igualación.
  }
  Vector2::Vector2(const Vector2 & vec)
  {
    this->x = vec.x; this->y = vec.y;
  }
  Vector2::Vector2(const Vector2i & vec)
  {
    this->x = static_cast<float>(vec.x);
    this->y = static_cast<float>(vec.y);
  }
  Vector2::Vector2(float x, float y)
  {
    this->x = x; this->y = y;
  }
  Vector2::~Vector2()
  {
  }
  Vector2 Vector2::operator+(const Vector2 & vec) const
  {
    return Vector2(this->x + vec.x, this->y + vec.y);
  }
  Vector2 Vector2::operator-(const Vector2 & vec) const
  {
    return Vector2(this->x - vec.x, this->y - vec.y);
  }
  Vector2 Vector2::operator*(const Vector2 & vec) const
  {
    return Vector2(this->x * vec.x, this->y * vec.y);
  }
  Vector2 Vector2::operator*(const float & escalar) const
  {
    return Vector2(this->x * escalar, this->y * escalar);
  }
  Vector2 Vector2::operator/(const Vector2 & vec) const
  {
    return Vector2(this->x / vec.x, this->y / vec.y);
  }
  Vector2 Vector2::operator/(const float & divi) const
  {
    return Vector2(this->x / divi, this->y / divi);
  } 
  Vector2 & Vector2::operator+=(const Vector2 & vec)
  {
    this->x += vec.x; this->y += vec.y;
    return *this;
  }
  Vector2 & Vector2::operator-=(const Vector2 & vec)
  {
    this->x -= vec.x; this->y -= vec.y;
    return *this;
  }
  Vector2 & Vector2::operator*=(const Vector2 & vec)
  {
    this->x *= vec.x; this->y *= vec.y;
    return *this;
  }
  Vector2 & Vector2::operator*=(const float & escalar)
  {
    this->x *= escalar;
    this->y *= escalar;    
    return *this;
  }
  Vector2 & Vector2::operator/=(const Vector2 & vec)
  {
    this->x /= vec.x; this->y /= vec.y;
    return *this;
  }
  Vector2 & Vector2::operator/=(const float & divi)
  {
    this->x /= divi;
    this->y /= divi;    
    return *this;
  }

  Vector2 & Vector2::Normalize()
  {
    return *this /= Magnitude();
  }
  float Vector2::operator[](const int32 & i) const
  {
    assert(i < 2 && i > -1);
    return (&x)[i];
  }
  float Vector2::operator|(const Vector2 & vec) const
  {
    return (this->x * vec.x) + (this->y * vec.y);
  }
  Vector2 Vector2::Normalized() const
  {
    return *this / Magnitude();
  }
  Vector2 Vector2::CrossProduct() const
  {
    return Vector2(this->x, -this->y);
  }
  float Vector2::Magnitude() const
  {
    return Math::Sqrt(Math::Pow(this->x, 2.0f) + Math::Pow(this->y, 2.0f));
  }
  float Vector2::HalfMagnitude() const
  {
    return this->Magnitude() * 0.5f;
  }
  float Vector2::RadiansBetween(const Vector2 & vec) const
  {
    return Math::Acos((*this | vec) / (this->Magnitude() * vec.Magnitude()));
  }
  float Vector2::DegreesBetween(const Vector2 & vec) const
  {
    return this->RadiansBetween(vec) * 180.0f / Math::PI;
  }
}