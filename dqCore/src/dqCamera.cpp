#include "dqCamera.h"

namespace dqEngineSDK
{
  void 
    dqCamera::move(Vector3 force)
  {
    this->position += force;
    return;
  }

  void 
    dqCamera::move(float x, float y, float z)
  {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
    return;
  }

  void
    dqCamera::pan(Vector3 force)
  {
    this->position += force;
    this->target += force;
  }

  void 
    dqCamera::rotate()
  {
  }

  void 
    dqCamera::orbitate()
  {
  }
}