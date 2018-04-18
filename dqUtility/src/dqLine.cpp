#include "dqLine.h"

namespace dqEngineSDK
{
  Line::Line()
  {
  }
  Line::Line(const Line & L)
  {
    this->vA = L.vA; this->vB = L.vB;
  }
  Line::Line(const Vector3 & A, const Vector3 & B)
  {
    this->vA = A; this->vB = B;
  }
  Line::~Line()
  {
  }
}