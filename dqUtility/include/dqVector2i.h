#pragma once

#include "dqPlatformTypes.h"

struct Vector2;

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Vector2i
  {
    int32 x, y;

    Vector2i();
    Vector2i(DEF_INIT::E);
    Vector2i(const Vector2i&);
    explicit Vector2i(const Vector2&);    
    Vector2i(int32 x, int32 y);
    ~Vector2i();

    Vector2i    operator+ (const Vector2i&) const;
    Vector2i    operator- (const Vector2i&) const;
    Vector2i    operator* (const Vector2i&) const;
    Vector2i    operator* (const float&) const;
    Vector2i    operator* (const int32&) const;
    Vector2i    operator/ (const Vector2i&) const;
    Vector2i    operator/ (const float&) const;
    int32       operator| (const Vector2i&) const;
    int32       operator[] (const int32&) const;
    Vector2i&   operator+= (const Vector2i&);
    Vector2i&   operator-= (const Vector2i&);
    Vector2i&   operator*= (const Vector2i&);
    Vector2i&   operator*= (const float&);
    Vector2i&   operator*= (const int32&);
    Vector2i&   operator/= (const Vector2i&);
    Vector2i&   operator/= (const float&);

    Vector2i    Normalized() const;
    Vector2i    CrossProduct() const;
    float       Magnitude() const;
    float       SquareMagnitude() const;
    float       RadiansBetween(const Vector2i&) const;
    float       DegreesBetween(const Vector2i&) const;   
    Vector2i&   Normalize();
  };
}
