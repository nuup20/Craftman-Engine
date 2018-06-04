#pragma once

#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct Vector2;
  struct Vector4;

  struct DQ_UTILITY_EXPORT Vector3
  {
    float x, y, z;
    
    Vector3();
    Vector3(DEF_INIT::E);
    Vector3(const Vector3&);
    explicit Vector3(const Vector2&);
    explicit Vector3(const Vector4&);
    Vector3(float x, float y, float z);
    ~Vector3();

    Vector3   operator+ (const Vector3&) const;
    Vector3   operator- (const Vector3&) const;
    Vector3   operator* (const Vector3&) const;
    Vector3   operator* (const float&) const;
    Vector3   operator/ (const Vector3&) const;
    Vector3   operator/ (const float&) const;
    Vector3   operator^ (const Vector3&) const;
    float     operator| (const Vector3&) const;
    float     operator[] (const int32&) const;    
    Vector3&  operator+= (const Vector3&);
    Vector3&  operator-= (const Vector3&);
    Vector3&  operator*= (const Vector3&);
    Vector3&  operator*= (const float&);
    Vector3&  operator/= (const Vector3&);    
    Vector3&  operator/= (const float&);
    Vector3&  operator^= (const Vector3&);
    Vector3&  operator= (const Vector3& _vector);
    Vector3&  operator= (const float& number);
    
    Vector3   Normalized() const;
    float     Magnitude() const;
    float     HalfMagnitude() const;
    float     RadiansBetween(const Vector3&) const;
    float     DegreesBetween(const Vector3&) const;
    Vector3&  Normalize();
  };
}
