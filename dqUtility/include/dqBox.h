#pragma once
#include "dqVector3.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Box
  {
    Vector3 vA, vB;

    Box();
    Box(const Box&);
    Box(const Vector3& A, const Vector3& B);
    ~Box();
  };
}