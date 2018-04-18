#pragma once
#include "dqVector3.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Sphere
  {
    Vector3 position;
    float   radius;

    Sphere();
    Sphere(const Sphere&);
    Sphere(const Vector3& Position, const float& Radius);
    ~Sphere();
  };
}
