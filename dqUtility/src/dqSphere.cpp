#include "dqSphere.h"

namespace dqEngineSDK
{
  Sphere::Sphere()
  {
  }
  Sphere::Sphere(const Sphere & copySphere)
  {
    this->position = copySphere.position; this->radius = copySphere.radius;
  }
  Sphere::Sphere(const Vector3 & Position, const float & Radius)
  {
    this->position = Position; this->radius = Radius;
  }
  Sphere::~Sphere()
  {
  }
}
