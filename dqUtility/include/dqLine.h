#pragma once
#include "dqVector3.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Line
  {
    Vector3 vA, vB;

    Line();
    Line(const Line&);
    Line(const Vector3& A, const Vector3& B);
    ~Line();
  };
}