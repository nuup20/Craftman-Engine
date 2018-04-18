#pragma once

#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct Matrix4x4;
  struct Vector4;
  struct Vector3;

  struct DQ_UTILITY_EXPORT Quaternion
  {
    float w, x, y, z;

    Quaternion();
    Quaternion(DEF_INIT::E);
    Quaternion(const Quaternion&);
    Quaternion(float w, float x, float y, float z);
    ~Quaternion();

    bool        operator==(const Quaternion& rhs) const;
    bool        operator!=(const Quaternion& rhs) const;

    Quaternion  operator* (const Quaternion&) const;
    Quaternion  operator* (const float&) const;
    Quaternion  operator+ (const Quaternion&) const;
    Quaternion  operator- (const Quaternion&) const;
    Quaternion  operator/ (const Quaternion&) const;
    Quaternion& operator= (const Quaternion&);
    //TODO: Vector4     operator* (const Vector4&) const;
    float       operator| (const Quaternion&) const;

    Quaternion&  operator *= (const Quaternion&);
    Quaternion&  operator += (const Quaternion&);
    Quaternion&  operator -= (const Quaternion&);
    Quaternion&  operator /= (const Quaternion&);
    Quaternion&  operator /= (const float&);
    Quaternion&  operator *= (const float&);

    Quaternion  Normalized() const;
    Quaternion  Conjugated() const;
    Matrix4x4   ToMatrix() const;

    Quaternion& Normalize();
    Quaternion& SetEulerDegrees(float x, float y, float z);
    Quaternion& SetEulerRadians(float x, float y, float z);
    //TODO: Quaternion& SetLookRotation(const Vector4& lookAt);
    //TODO: Quaternion& SetLookRotation(const Vector4& lookAt, const Vector4& upDirection);
    //TODO: Quaternion& ToAngleAxis(const float& angle, const Vector4& axis);
  };
}