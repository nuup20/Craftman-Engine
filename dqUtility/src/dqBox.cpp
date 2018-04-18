#include "dqBox.h"

namespace dqEngineSDK
{
  Box::Box()
  {
  }
  Box::Box(const Box & B)
  {
    this->vA = B.vA; this->vB = B.vB;
  }
  Box::Box(const Vector3 & A, const Vector3 & B)
  {
    this->vA = A; this->vB = B;
  }
  Box::~Box()
  {
  }
}