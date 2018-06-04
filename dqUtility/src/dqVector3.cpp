#include <assert.h>

#include "dqVector3.h"
#include "dqVector2.h"
#include "dqVector4.h"
#include "dqPlatformMath.h"

#define Math PlatformBaseMath

namespace dqEngineSDK
{
  Vector3::Vector3()
  {
    *this = 0.0f;
  }
  Vector3::Vector3(DEF_INIT::E)
  {
    
  }
  Vector3::Vector3(const Vector3 & vec)
  {
    this->x = vec.x; this->y = vec.y; this->z = vec.z;
  }
  Vector3::Vector3(const Vector2 & vec)
  {
    this->x = vec.x; this->y = vec.y; this->z = 0.0f;
  }
  Vector3::Vector3(const Vector4 & vec)
  {
    this->x = vec.x; this->y = vec.y; this->z = vec.z;
  }
  Vector3::Vector3(float x, float y, float z)
  {
    this->x = x; this->y = y; this->z = z;
  }
  Vector3::~Vector3()
  {
  }

  Vector3 
    Vector3::operator+(const Vector3 & vec) const
  {
    return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
  }

  Vector3 
    Vector3::operator-(const Vector3 & vec) const
  {
    return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
  }

  Vector3 
    Vector3::operator*(const Vector3 & vec) const
  {
    return Vector3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
  }
  Vector3 Vector3::operator*(const float & escalar) const
  {
    return Vector3(this->x * escalar, this->y * escalar, this->z * escalar);
  }
  Vector3 Vector3::operator/(const Vector3 & vec) const
  {
    return Vector3(this->x / vec.x, this->y / vec.y, this->z / vec.z);
  }
  Vector3 Vector3::operator/(const float & divi) const
  {
    return Vector3(this->x / divi, this->y / divi, this->z / divi);
  }
  Vector3 & Vector3::operator+=(const Vector3 & vec)
  {
    this->x += vec.x; this->y += vec.y; this->z += vec.z;
    return *this;
  }
  Vector3 & Vector3::operator-=(const Vector3 & vec)
  {
    this->x -= vec.x; this->y -= vec.y; this->z -= vec.z;
    return *this;
  }
  Vector3 & Vector3::operator*=(const Vector3 & vec)
  {
    this->x *= vec.x; this->y *= vec.y; this->z *= vec.z;
    return *this;
  }
  Vector3 & Vector3::operator*=(const float & escalar)
  {
    this->x *= escalar;
    this->y *= escalar;
    this->z *= escalar;
    return *this;
  }
  Vector3 & Vector3::operator/=(const Vector3 & vec)
  {
    this->x /= vec.x; this->y /= vec.y; this->z /= vec.z;
    return *this;
  }
  Vector3 & Vector3::operator/=(const float & divi)
  {
    this->x /= divi;
    this->y /= divi;
    this->z /= divi;
    return *this;
  }

  Vector3 & Vector3::operator^=(const Vector3 & vec)
  {
    Vector3 cVector(*this);
    this->x = (cVector.y * vec.z) - (cVector.z * vec.y);
    this->y = (cVector.z * vec.x) - (cVector.x * vec.z);
    this->z = (cVector.x * vec.y) - (cVector.y * vec.x);
    return *this;
  }

  Vector3 & Vector3::operator=(const Vector3 & _vector)
  {
    this->x = _vector.x;
    this->y = _vector.y;
    this->z = _vector.z;
    return *this;
  }

  Vector3 & Vector3::operator=(const float & number)
  {
    this->x = number;
    this->y = number;
    this->z = number;
    return *this;
  }

  Vector3 & Vector3::Normalize()
  {    
    return *this /= Magnitude();
  }

  float Vector3::operator[](const int32 & i) const
  {
    assert(i < 3 && i > -1);
    return (&x)[i];
  }

  float Vector3::operator|(const Vector3 & vec) const
  {
    return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
  }
  Vector3 Vector3::operator^(const Vector3 & vec) const
  {
    Vector3 cVector;
    cVector.x = (this->y * vec.z) - (this->z * vec.y);
    cVector.y = (this->z * vec.x) - (this->x * vec.z);
    cVector.z = (this->x * vec.y) - (this->y * vec.x);
    return cVector;
  }
  Vector3 Vector3::Normalized() const
  {
    return *this / Magnitude();
  }
  float Vector3::Magnitude() const
  {
    return Math::Sqrt(Math::Pow(this->x,2.0f) 
                 + Math::Pow(this->y, 2.0f) 
                 + Math::Pow(this->z, 2.0f));
  }
  float Vector3::HalfMagnitude() const
  {
    return this->Magnitude() * 0.5f;
  }
  float Vector3::RadiansBetween(const Vector3 & vec) const
  {
    return Math::Acos((*this | vec) / (this->Magnitude() * vec.Magnitude()));
  }
  float Vector3::DegreesBetween(const Vector3 & vec) const
  {
    return this->RadiansBetween(vec) * 180.0f / Math::PI;
  }
  
}
