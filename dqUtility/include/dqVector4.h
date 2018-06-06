#pragma once

#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct Vector2;
  struct Vector3;

  struct DQ_UTILITY_EXPORT Vector4
  {
    float x, y, z, w;

    Vector4();
    Vector4(DEF_INIT::E);
    Vector4(const Vector4&);
    Vector4(const Vector2&);
    explicit Vector4(const Vector3&);
    Vector4(float x, float y, float z, float w);
    ~Vector4();

    Vector4   operator+ (const Vector4&) const;
    Vector4   operator- (const Vector4&) const;
    Vector4   operator* (const Vector4&) const;
    Vector4   operator* (const float&) const;
    Vector4   operator/ (const Vector4&) const;
    Vector4   operator/ (const float&) const;
    float     operator| (const Vector4&) const;
    float     operator[] (const int32&) const;
    Vector4&  operator+= (const Vector4&);
    Vector4&  operator-= (const Vector4&);
    Vector4&  operator*= (const Vector4&);
    Vector4&  operator*= (const float&);
    Vector4&  operator/= (const Vector4&);
    Vector4&  operator/= (const float&);
    Vector4&  operator= (const Vector4& _vector);
    Vector4&  operator= (const float& number);

    Vector4&  equalTo(const Vector3& _vector, const float& w_value);
    Vector4   Normalized() const;
    float     Magnitude() const;
    float     HalfMagnitude() const;
    float     RadiansBetween(const Vector4&) const;
    float     DegreesBetween(const Vector4&) const;
    Vector4&  Normalize();

    //TODO Orthonormalize static function
  };
}