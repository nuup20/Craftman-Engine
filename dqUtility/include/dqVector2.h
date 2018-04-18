#pragma once

#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct Vector2i;

  struct DQ_UTILITY_EXPORT Vector2
  {
    float x, y;

    Vector2();
    Vector2(DEF_INIT::E);
    Vector2(const Vector2&);
    explicit Vector2(const Vector2i&);
    Vector2(float x, float y);
    ~Vector2();

    Vector2   operator+ (const Vector2&) const;
    Vector2   operator- (const Vector2&) const;
    Vector2   operator* (const Vector2&) const;
    Vector2   operator* (const float&) const;
    Vector2   operator/ (const Vector2&) const;
    Vector2   operator/ (const float&) const;
    float     operator| (const Vector2&) const;
    float     operator[] (const int32&) const;
    Vector2&  operator+= (const Vector2&);
    Vector2&  operator-= (const Vector2&);
    Vector2&  operator*= (const Vector2&);
    Vector2&  operator*= (const float&);
    Vector2&  operator/= (const Vector2&);
    Vector2&  operator/= (const float&);

    Vector2   Normalized() const;
    Vector2   CrossProduct() const;
    float     Magnitude() const;
    float     HalfMagnitude() const;
    float     RadiansBetween(const Vector2&) const;
    float     DegreesBetween(const Vector2&) const;
    Vector2&  Normalize();
  };
}