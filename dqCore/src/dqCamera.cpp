#include "dqCamera.h"

//#include <DirectXMath.h>

namespace dqEngineSDK
{
  dqCamera::dqCamera()
  {
    this->init();
  }
  dqCamera::~dqCamera()
  {
  }

  void dqCamera::init()
  {
    this->isDirty = true;
    this->position = 0.0f;
    this->position.x = 0.0f;
    this->position.y = 0.0f;
    this->position.z = -2.0f;

    this->target = 0.0f;

    this->up.x = 0.0f;
    this->up.y = 1.0f;
    this->up.z = 0.0f;

    this->orthonormalVectors();
    this->setModelViewMatrix();
  }

  void 
  dqCamera::update()
  {
    if (!this->isDirty) {
      return;
    }  

    this->setModelViewMatrix();

    this->isDirty = false;
    return;
  }

  void
  dqCamera::move(const Vector3& force)
  {
    this->position += force;
    this->isDirty = true;
    return;
  }

  void 
  dqCamera::move(float x, float y, float z)
  {
    this->move(Vector3(x, y, z));
    return;
  }

  void
  dqCamera::trackX(float _force)
  {
    if (_force == 0.0f) {
      return;
    }

    Vector3 sumando = this->right * _force;
    this->position += sumando;
    this->target += sumando;

    this->isDirty = true;
    return;
  }

  void 
  dqCamera::trackY(float _force)
  {
    if (_force == 0.0f) {
      return;
    }

    Vector3 sumando = this->up * _force;
    this->position += sumando;
    this->target += sumando;

    this->isDirty = true;
    return;
  }

  void 
  dqCamera::dolly(float _force)
  {
    if (_force == 0.0f) {
      return;
    }

    Vector3 sumando = this->forward * _force;
    this->position += sumando;
    this->target += sumando;

    this->isDirty = true;
    return;
  }

  void 
  dqCamera::rotate()
  {
    this->isDirty = true;
    return;
  }

  void 
  dqCamera::yaw(float radians)
  {
    Matrix4x4 yawMatrix(DEF_INIT::kONE);
    yawMatrix.rotationMatrixOverAxis(up, radians);

    right = yawMatrix * Vector4(right);
    forward = yawMatrix * Vector4(forward);
    target = this->position + (this->forward * target.magnitude());

    this->isDirty = true;
    return;
  }

  void 
  dqCamera::pitch(float radians)
  {

    Matrix4x4 pitchMatrix(DEF_INIT::kONE);
    pitchMatrix.rotationMatrixOverAxis(right, radians);

    up = pitchMatrix * Vector4(up);
    forward = pitchMatrix * Vector4(forward);
    target = this->position + (this->forward * target.magnitude());

    this->isDirty = true;
    return;
  }

  void 
  dqCamera::roll(float radians)
  {

    Matrix4x4 rollMatrix(DEF_INIT::kONE);
    rollMatrix.rotationMatrixOverAxis(forward, radians);

    right = rollMatrix * Vector4(right);
    up = rollMatrix * Vector4(up);
    target = this->position + (this->forward * target.magnitude());

    this->isDirty = true;
    return;
  }

  void
  dqCamera::orbitate()
  {
    this->isDirty = true;
    return;
  }

  void dqCamera::setModelViewMatrix()
  {
    Matrix4x4::lookAtLH(this->camera_to_world, 
                        this->up, 
                        this->forward, 
                        this->right, 
                        this->position);

    return;
  }

  void dqCamera::orthonormalVectors()
  {
    //Forward Axis.
    this->forward = this->target - this->position;
    this->forward.normalize();

    //Right Axis.
    this->right = this->up ^ this->forward;
    this->right.normalize();

    //Up Axis.
    this->up = this->forward ^ this->right;
    this->up.normalize();

    return;
  }
}