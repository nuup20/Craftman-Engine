#include <assert.h>

#include "dqVector4.h"
#include "dqVector2.h"
#include "dqVector3.h"
#include "dqPlatformMath.h"

#define Math PlatformBaseMath

namespace dqEngineSDK
{
  Vector4::Vector4()
  {
    *this = 0.0f;
  }

  Vector4::Vector4(DEF_INIT::E)
  {
    //TODO: Hago una evaluación primero, o una igualación.
  }

  Vector4::Vector4(const Vector4 & vec)
  {
    this->x = vec.x; 
    this->y = vec.y; 
    this->z = vec.z; 
    this->w = vec.w;
  }

  Vector4::Vector4(const Vector2 & vec)
  {
    this->x = vec.x; 
    this->y = vec.y; 
    this->z = 0.0f; 
    this->w = 1.0f;
  }

  Vector4::Vector4(const Vector3 & vec)
  {
    this->x = vec.x; 
    this->y = vec.y; 
    this->z = vec.z; 
    this->w = 1.0f;
  }

  Vector4::Vector4(float x, float y, float z, float w)
  {
    this->x = x; 
    this->y = y; 
    this->z = z; 
    this->w = w;
  }

  Vector4::~Vector4()
  {
  }

  Vector4 
    Vector4::operator+(const Vector4 & vec) const
  {
    return Vector4
    (
      this->x + vec.x, 
      this->y + vec.y, 
      this->z + vec.z, 
      this->w + vec.w
    );
  }

  Vector4 
    Vector4::operator-(const Vector4 & vec) const
  {
    return Vector4
    (
      this->x - vec.x, 
      this->y - vec.y, 
      this->z - vec.z, 
      this->w - vec.w
    );
  }

  Vector4 
    Vector4::operator*(const Vector4 & vec) const
  {
    return Vector4
    (
      this->x * vec.x, 
      this->y * vec.y, 
      this->z * vec.z, 
      this->w * vec.w
    );
  }

  Vector4 
    Vector4::operator*(const float & escalar) const
  {
    return Vector4
    (
      this->x * escalar, 
      this->y * escalar, 
      this->z * escalar, 
      this->w * escalar
    );
  }

  Vector4 
    Vector4::operator/(const Vector4 & vec) const
  {
    return Vector4
    (
      this->x / vec.x, 
      this->y / vec.y, 
      this->z / vec.z, 
      this->w / vec.w
    );
  }

  Vector4 
    Vector4::operator/(const float & divi) const
  {
    return Vector4
    (
      this->x / divi, 
      this->y / divi, 
      this->z / divi, 
      this->w / divi
    );
  }

  Vector4 & 
    Vector4::operator+=(const Vector4 & vec)
  {
    this->x += vec.x; 
    this->y += vec.y; 
    this->z += vec.z; 
    this->w += vec.w;
    return *this;
  }

  Vector4 & 
    Vector4::operator-=(const Vector4 & vec)
  {
    this->x -= vec.x; 
    this->y -= vec.y; 
    this->z -= vec.z; 
    this->w -= vec.w;
    return *this;
  }

  Vector4 & 
    Vector4::operator*=(const Vector4 & vec)
  {
    this->x *= vec.x; 
    this->y *= vec.y; 
    this->z *= vec.z; 
    this->w *= vec.w;
    return *this;
  }

  Vector4 & 
    Vector4::operator*=(const float & escalar)
  {
    this->x *= escalar;
    this->y *= escalar;
    this->z *= escalar;
    this->w *= escalar;
    return *this;
  }

  Vector4 & 
    Vector4::operator/=(const Vector4 & vec)
  {
    this->x /= vec.x; 
    this->y /= vec.y; 
    this->z /= vec.z; 
    this->w /= vec.w;
    return *this;
  }

  Vector4 & 
    Vector4::operator/=(const float & divi)
  {
    this->x /= divi;
    this->y /= divi;
    this->z /= divi;
    this->w /= divi;
    return *this;
  }

  Vector4 & 
    Vector4::operator=(const Vector4 & _vector)
  {
    this->x = _vector.x;
    this->y = _vector.y;
    this->z = _vector.z;
    this->w = _vector.w;
    return *this;
  }

  Vector4 & 
    Vector4::operator=(const float & number)
  {
    this->x = number;
    this->y = number;
    this->z = number;
    this->w = number;
    return *this;
  }

  Vector4 & 
    Vector4::equalTo(const Vector3 & _vector, const float & w_value)
  {
    this->x = _vector.x;
    this->y = _vector.y;
    this->z = _vector.z;
    this->w = w_value;
    return *this;
  }

  Vector4 & 
    Vector4::Normalize()
  {
    return *this /= Magnitude();
  }

  float 
    Vector4::operator[](const int32 & i) const
  {
    assert(i < 4 && i > -1);
    return (&x)[i];
  }

  float 
    Vector4::operator|(const Vector4 & vec) const
  {
    return 
      (this->x * vec.x) + 
      (this->y * vec.y) + 
      (this->z * vec.z) + 
      (this->w * vec.w);
  }

  Vector4 
    Vector4::Normalized() const
  {
    return *this / Magnitude();
  }

  float 
    Vector4::Magnitude() const
  {
    return Math::Sqrt
    (
      Math::Pow(this->x, 2.0f)
      + Math::Pow(this->y, 2.0f)
      + Math::Pow(this->z, 2.0f)
      + Math::Pow(this->w, 2.0f)
    );
  }

  float 
    Vector4::HalfMagnitude() const
  {
    return this->Magnitude() * 0.5f;
  }

  float 
    Vector4::RadiansBetween(const Vector4 & vec) const
  {
    return Math::Acos
    (
      (*this | vec) / (this->Magnitude() * vec.Magnitude())
    );
  }

  float 
    Vector4::DegreesBetween(const Vector4 & vec) const
  {
    return this->RadiansBetween(vec) * 180.0f / Math::PI;
  }

}

