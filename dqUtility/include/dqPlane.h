#pragma once
#include "dqVector3.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT dqPlane
  {
    Vector3 vA, vB;

    dqPlane();
    dqPlane(const dqPlane&);
    dqPlane(const Vector3& A, const Vector3& B);
    ~dqPlane();
  };
}