#include "dqPlane.h"

namespace dqEngineSDK
{
  dqPlane::dqPlane()
  {
  }
  dqPlane::dqPlane(const dqPlane & P)
  {
    this->vA = P.vA; 
    this->vB = P.vB;
  }
  dqPlane::dqPlane(const Vector3 & A, const Vector3 & B)
  {
    this->vA = A; this->vB = B;
  }
  dqPlane::~dqPlane()
  {
  }
}