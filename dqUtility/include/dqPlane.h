#pragma once
#include "dqVector3.h"
#include "dqModule.h"

namespace dqEngineSDK
{
  class DQ_UTILITY_EXPORT dqPlane
  {
  public:
    Vector3 vA, vB;

    dqPlane();
    dqPlane(const dqPlane&);
    dqPlane(const Vector3& A, const Vector3& B);
    ~dqPlane();
  };
}