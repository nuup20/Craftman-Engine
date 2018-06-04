#include "dqCamera.h"

//#include <DirectXMath.h>

namespace dqEngineSDK
{
  //TODO: Borrar esta función.
#if DQ_DEBUG_MODE
  void
    printMatrix(const Matrix4x4& matrix)
  {
    std::cout << "------- Cam to World -------" << std::endl << std::endl;
    for (int8 row = 0; row < 4; ++row)
    {
      std::cout << " | ";
      for (int8 col = 0; col < 4; ++col)
      {
       std::cout <<  matrix.m[row][col] << " , ";
      }
      std::cout << " | ";
      std::cout << std::endl;
    }
  }
#else
  void
    printMatrix(const Matrix4x4& matrix) {}
#endif

  dqCamera::dqCamera()
  {
    this->isDirty = true;
    this->position = 0.0f;
    this->position.x = 0.0f;
    this->position.y = 1.0f;
    this->position.z = -2.0f;
    
    this->target = 0.0f;
  }
  dqCamera::~dqCamera()
  {
  }
  void dqCamera::update()
  {
    if (!this->isDirty) {
      return;
    }

    /*

    //Forward Axis.
    Vector3 vecForward = this->target - this->position;
    vecForward.Normalize();

    //Right Axis.
    Vector3 vecRight = Vector3(0.0f, 1.0f, 0.0f) ^ vecForward;
    //Vector3 vecRight =  vecForward ^ Vector3(0.0f, 1.0f, 0.0f); 
    vecRight.Normalize();

    //Up Axis.
    Vector3 vecUp =  vecForward ^ vecRight;
    //Vector3 vecUp = vecRight ^ vecForward;
    vecUp.Normalize();

    //Set Matrix.
    this->camera_to_world.rowVec[0].equalTo(vecRight, 0.0f);
    this->camera_to_world.rowVec[1].equalTo(vecUp, 0.0f);
    this->camera_to_world.rowVec[2].equalTo(vecForward, 0.0f);
    this->camera_to_world.rowVec[3].x = this->position.x;
    this->camera_to_world.rowVec[3].y = this->position.y;
    this->camera_to_world.rowVec[3].z = -this->position.z;
    this->camera_to_world.rowVec[3].w = 1.0f;

    printMatrix(this->camera_to_world);
    
    */

    /*
    //Forward Axis.
    Vector3 vecForward = this->position - this->target;
    vecForward.Normalize();

    //Right Axis.
    Vector3 vecLeft = Vector3(0.0f, 1.0f, 0.0f) ^ vecForward;
    //Vector3 vecRight =  vecForward ^ Vector3(0.0f, 1.0f, 0.0f); 
    vecLeft.Normalize();

    //Up Axis.
    Vector3 vecUp = vecForward ^ vecLeft;
    //Vector3 vecUp = vecRight ^ vecForward;
    vecUp.Normalize();

    //Set Matrix.
    this->camera_to_world = Matrix4x4(DEF_INIT::kONE);

    this->camera_to_world.mi[0] = vecLeft.x;
    this->camera_to_world.mi[4] = vecLeft.y;
    this->camera_to_world.mi[8] = vecLeft.z;
    this->camera_to_world.mi[1] = vecUp.x;
    this->camera_to_world.mi[5] = vecUp.y;
    this->camera_to_world.mi[9] = vecUp.z;
    this->camera_to_world.mi[2] = vecForward.x;
    this->camera_to_world.mi[6] = vecForward.y;
    this->camera_to_world.mi[10] = vecForward.z;

    this->camera_to_world.mi[12] = -vecLeft.x * position.x - vecLeft.y * position.y - vecLeft.z * position.z;
    this->camera_to_world.mi[13] = -vecUp.x * position.x - vecUp.y * position.y - vecUp.z * position.z;
    this->camera_to_world.mi[14] = -vecForward.x * position.x - vecForward.y * position.y - vecForward.z * position.z;

    printMatrix(this->camera_to_world);
    */

    //Forward Axis.
    Vector3 vecForward = this->target - this->position;
    vecForward.Normalize();

    //Right Axis.
    Vector3 vecRight = Vector3(0.0f, 1.0f, 0.0f) ^ vecForward;
    //Vector3 vecRight =  vecForward ^ Vector3(0.0f, 1.0f, 0.0f); 
    vecRight.Normalize();

    //Up Axis.
    Vector3 vecUp = vecForward ^ vecRight;
    //Vector3 vecUp = vecRight ^ vecForward;
    vecUp.Normalize();

    //Set Matrix.
    this->camera_to_world = Matrix4x4(DEF_INIT::kONE);

    this->camera_to_world.mi[0] = vecRight.x;
    this->camera_to_world.mi[4] = vecRight.y;
    this->camera_to_world.mi[8] = vecRight.z;
    this->camera_to_world.mi[1] = vecUp.x;
    this->camera_to_world.mi[5] = vecUp.y;
    this->camera_to_world.mi[9] = vecUp.z;
    this->camera_to_world.mi[2] = vecForward.x;
    this->camera_to_world.mi[6] = vecForward.y;
    this->camera_to_world.mi[10] = vecForward.z;

    this->camera_to_world.mi[12] = -vecRight.x * position.x - vecRight.y * position.y - vecRight.z * position.z;
    this->camera_to_world.mi[13] = -vecUp.x * position.x - vecUp.y * position.y - vecUp.z * position.z;
    this->camera_to_world.mi[14] = -vecForward.x * position.x - vecForward.y * position.y - vecForward.z * position.z;

    printMatrix(this->camera_to_world);

    this->isDirty = false;
    return;
  }

  void
    dqCamera::move(Vector3 force)
  {
    this->position += force;
    this->isDirty = true;
    return;
  }

  void 
    dqCamera::move(float x, float y, float z)
  {
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;

    this->isDirty = true;
    return;
  }

  void
    dqCamera::pan(Vector3 force)
  {
    this->position += force;
    this->target += force;

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
    dqCamera::orbitate()
  {

    this->isDirty = true;
    return;
  }
}