#include <assert.h>

#include "dqVector2.h"
#include "dqVector2i.h"
#include "dqPlatformMath.h"

#define Math PlatformBaseMath

namespace dqEngineSDK
{
  Vector2i::Vector2i()
  {
  }
  Vector2i::Vector2i(DEF_INIT::E)
  {
    //TODO: Hago una evaluación primero, o una igualación.
  }
  Vector2i::Vector2i(const Vector2i & vec)
  {
    this->x = vec.x; this->y = vec.y;
  }

  Vector2i::Vector2i(const Vector2 & vec)
  {
    this->x = static_cast<int32>(vec.x);
    this->y = static_cast<int32>(vec.y);
  }

  Vector2i::Vector2i(int32 x, int32 y)
  {
    this->x = x; this->y = y;
  }
  Vector2i::~Vector2i()
  {
  }
  Vector2i Vector2i::operator+(const Vector2i & vec) const
  {
    return Vector2i(this->x + vec.x, this->y + vec.y);
  }
  Vector2i Vector2i::operator-(const Vector2i & vec) const
  {
    return Vector2i(this->x - vec.x, this->y - vec.y);
  }
  Vector2i Vector2i::operator*(const Vector2i & vec) const
  {
    return Vector2i(this->x * vec.x, this->y * vec.y);
  }
  Vector2i Vector2i::operator*(const float & escalar) const
  {
    int32 _esc = static_cast<int32>(escalar);
    return Vector2i(this->x * _esc, this->y * _esc);
  }
  Vector2i Vector2i::operator*(const int32 & escalar) const
  {
    return Vector2i(this->x * escalar, this->y * escalar);
  }
  Vector2i Vector2i::operator/(const Vector2i & vec) const
  {
    return Vector2i(static_cast<int32>(this->x / vec.x), 
                    static_cast<int32>(this->y / vec.y));
  }
  Vector2i Vector2i::operator/(const float & divi) const
  {
    return Vector2i(static_cast<int32>(this->x / divi), 
                    static_cast<int32>(this->y / divi));
  }
  Vector2i & Vector2i::operator+=(const Vector2i & vec)
  {
    this->x += vec.x; this->y += vec.y;
    return *this;
  }
  Vector2i & Vector2i::operator-=(const Vector2i & vec)
  {
    this->x -= vec.x; this->y -= vec.y;
    return *this;
  }
  Vector2i & Vector2i::operator*=(const Vector2i & vec)
  {
    this->x *= vec.x; this->y *= vec.y;
    return *this;
  }
  Vector2i & Vector2i::operator*=(const float & escalar)
  {
    int32 _esc = static_cast<int32>(escalar);
    this->x *= _esc;
    this->y *= _esc;
    return *this;
  }
  Vector2i & Vector2i::operator*=(const int32 & escalar)
  {
    this->x *= escalar;
    this->y *= escalar;
    return *this;
  }
  Vector2i & Vector2i::operator/=(const Vector2i & vec)
  {
    this->x = static_cast<int32>(this->x / vec.x); 
    this->y = static_cast<int32>(this->y / vec.y);
    return *this;
  }
  Vector2i & Vector2i::operator/=(const float & divi)
  {
    this->x /= static_cast<int32>(divi);
    this->y /= static_cast<int32>(divi);
    return *this;
  }
  Vector2i & Vector2i::Normalize()
  {
    return *this /= Magnitude();
  }
  int32 Vector2i::operator[](const int32 & i) const
  {
    assert(i < 2 && i > -1);
    return (&x)[i];
  }
  int32 Vector2i::operator|(const Vector2i & vec) const
  {
    return (this->x * vec.x) + (this->y * vec.y);
  }
  Vector2i Vector2i::Normalized() const
  {
    return *this * Math::InvSqrt(SquareMagnitude());
  }
  Vector2i Vector2i::CrossProduct() const
  {
    return Vector2i(this->x, -this->y);
  }
  float Vector2i::Magnitude() const
  {
    return Math::Sqrt(Math::Pow(this->x, 2) + Math::Pow(this->y, 2));
  }
  float Vector2i::SquareMagnitude() const
  {
    return Math::Pow(static_cast<float>(this->x), 2.0f) + 
           Math::Pow(static_cast<float>(this->y), 2.0f);
  }
  float Vector2i::RadiansBetween(const Vector2i & vec) const
  {
    return Math::Acos(static_cast<float>(*this | vec) / 
                      (this->Magnitude() * vec.Magnitude()));
  }
  float Vector2i::DegreesBetween(const Vector2i & vec) const
  {
    return this->RadiansBetween(vec) * 180.0f / Math::PI;
  }
}
