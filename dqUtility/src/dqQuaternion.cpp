#include "dqQuaternion.h"

#include "dqVector4.h"
#include "dqMatrix4x4.h"
#include "dqMath.h"

namespace dqEngineSDK
{
  Quaternion::Quaternion()
  {

  }
  Quaternion::Quaternion(DEF_INIT::E)
  {

  }
  Quaternion::Quaternion(const Quaternion & quat)
  {
    this->w = quat.w; this->x = quat.x; this->y = quat.y; this->z = quat.z;
  }
  Quaternion::Quaternion(float w, float x, float y, float z)
  {
    this->w = w; this->x = x; this->y = y; this->z = z;
  }
  Quaternion::~Quaternion()
  {
  }
  bool Quaternion::operator==(const Quaternion & rhs) const
  {
    return (this->w == rhs.w && this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
  }
  bool Quaternion::operator!=(const Quaternion & rhs) const
  {
    return !(this->w == rhs.w && this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);;
  }
  Quaternion Quaternion::operator*(const Quaternion & quat) const
  {
    Quaternion _q;
    _q.w = (this->w * quat.w) - (this->x * quat.x) - (this->y * quat.y) - (this->z * quat.z);
    _q.x = (this->w * quat.x) + (this->x * quat.w) + (this->y * quat.z) - (this->z * quat.y);
    _q.y = (this->w * quat.y) - (this->x * quat.z) + (this->y * quat.w) + (this->z * quat.x);
    _q.z = (this->w * quat.z) + (this->x * quat.y) - (this->y * quat.x) + (this->z * quat.w);
    return _q;
  }
  Quaternion Quaternion::operator*(const float & mult) const
  {
    return Quaternion(this->w*mult, this->x*mult, this->y*mult, this->z*mult);
  }
  Quaternion Quaternion::operator+(const Quaternion & quat) const
  {    
    return Quaternion(this->w + quat.w, this->x + quat.x, this->y + quat.y, this->z + quat.z);
  }
  Quaternion Quaternion::operator-(const Quaternion & quat) const
  {
    return Quaternion(this->w - quat.w, this->x - quat.x, this->y - quat.y, this->z - quat.z);
  }
  Quaternion Quaternion::operator/(const Quaternion & quat) const
  {   
    Quaternion q;
    q.w = (quat.w * this->w) + (quat.x * this->x) + (quat.y * this->y) + (quat.z * this->z);
    q.x = (quat.w * this->x) - (quat.x * this->w) - (quat.y * this->z) + (quat.z * this->y);
    q.y = (quat.w * this->y) + (quat.x * this->z) - (quat.y * this->w) - (quat.z * this->x);
    q.z = (quat.w * this->z) - (quat.x * this->y) + (quat.y * this->x) - (quat.z * this->w);
    q /= (quat.w * quat.w) + (quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z);
    return q;
  }
  Quaternion & Quaternion::operator=(const Quaternion & quat)
  {
    this->x = quat.x; this->y = quat.y; this->z = quat.z; this->w = quat.w;
    return *this;
  }  
  float Quaternion::operator|(const Quaternion & quat) const
  {
    return (this->w * quat.w) + (this->x * quat.x) + (this->y * quat.y) + (this->z * quat.z);
  }
  Quaternion& Quaternion::operator*=(const Quaternion & quat)
  {
    *this = *this * quat;
    return *this;
  }
  Quaternion& Quaternion::operator+=(const Quaternion & quat)
  {
    this->w += quat.w; this->x += quat.x; this->y += quat.y; this->z += quat.z;
    return *this;
  }
  Quaternion& Quaternion::operator-=(const Quaternion & quat)
  {
    this->w -= quat.w; this->x -= quat.x; this->y -= quat.y; this->z -= quat.z;
    return *this;
  }
  Quaternion& Quaternion::operator/=(const Quaternion & quat)
  {
    *this = *this / quat;
    return *this;
  }
  Quaternion & Quaternion::operator/=(const float & div)
  {
    this->w /= div; this->x /= div; this->y /= div; this->z /= div;
    return *this;
  }
  Quaternion & Quaternion::operator*=(const float & mult)
  {
    this->w *= mult; this->x *= mult; this->y *= mult; this->z *= mult;
    return *this;
  }
  Quaternion Quaternion::Normalized() const
  {
    float mult = Math::Sqrt((this->w * this->w) + (this->x * this->x) 
                + (this->y * this->y) + (this->z * this->z) );
    return Quaternion(this->w / mult, this->x / mult, this->y / mult, this->z / mult);
  }
  Quaternion Quaternion::Conjugated() const
  {
    return Quaternion(this->w, -this->x, -this->y, -this->z);
  }
  Matrix4x4 Quaternion::ToMatrix() const
  {
    //Esto está comentado para evitar warnings.
    /*float sqw = this->w * this->w;
    float sqx = this->x * this->x;
    float sqy = this->y * this->y;
    float sqz = this->z * this->z;
    //float inv = 1.0f / (sqw + sqx + sqy + sqz);
    */
    Matrix4x4 matrix(DEF_INIT::kONE);
    //TODO terminar la función.

    return Matrix4x4();
  }
  Quaternion & Quaternion::Normalize()
  {
    float mult = Math::Sqrt((this->w * this->w) + (this->x * this->x)
      + (this->y * this->y) + (this->z * this->z));
    this->w /= mult; this->x /= mult; this->y /= mult; this->z /= mult;
    return *this;
  }
  Quaternion & Quaternion::SetEulerDegrees(float _x, float _y, float _z)
  {
    _x *= Math::TORADIANS * 0.5f;
    _y *= Math::TORADIANS * 0.5f;
    _z *= Math::TORADIANS * 0.5f;
  
    float sinx = Math::Sin(_x);
    float siny = Math::Sin(_y);
    float sinz = Math::Sin(_z);
    float cosx = Math::Cos(_x);
    float cosy = Math::Cos(_y);
    float cosz = Math::Cos(_z);

    this->w = (cosx * cosy * cosz) + (sinx * siny * sinz);
    this->x = (sinx * cosy * cosz) + (cosx * siny * sinz);
    this->y = (cosx * siny * cosz) + (sinx * cosy * sinz);
    this->z = (cosx * cosy * sinz) + (sinx * siny * cosz);

    return *this;
  }
  Quaternion & Quaternion::SetEulerRadians(float _x, float _y, float _z)
  {
    _x *= 0.5f;
    _y *= 0.5f;
    _z *= 0.5f;

    float sinx = Math::Sin(_x);
    float siny = Math::Sin(_y);
    float sinz = Math::Sin(_z);
    float cosx = Math::Cos(_x);
    float cosy = Math::Cos(_y);
    float cosz = Math::Cos(_z);

    this->w = (cosx * cosy * cosz) + (sinx * siny * sinz);
    this->x = (sinx * cosy * cosz) + (cosx * siny * sinz);
    this->y = (cosx * siny * cosz) + (sinx * cosy * sinz);
    this->z = (cosx * cosy * sinz) + (sinx * siny * cosz);

    return *this;
  }  
}

