#pragma once

#include <dqVector3.h>
#include <dqMatrix4x4.h>

#include "dqCorePrerequisites.h"

namespace dqEngineSDK 
{
  struct DQ_CORE_EXPORT dqCamera 
  {
  public:
    dqCamera();
    ~dqCamera();

    void
    init();

    void
    update();

    /**
     * @brief Movimiento de la posición de la Cámara.
     * @param force Dirección con magnitud aplicada al movimiento.
     */
    void 
    move(const Vector3& force);

    /**
     * @brief Posiciona la Cámara en una coordenada específica.
     */
    void
    move(float x, float y, float z);
    
    void 
    trackX(float _force);

    void
    trackY(float _force);

    void
    dolly(float _force);
    
    void 
    rotate();

    void
    yaw(float radians);

    void
    pitch(float radians);

    void
    roll(float radians);
    
    void 
    orbitate();    

  private:

    void
    setModelViewMatrix();

    void
    orthonormalVectors();

  public:

    Vector3 position;
    Vector3 target; 

    Matrix4x4 camera_to_world;

  private:

    Vector3 up;
    Vector3 right;
    Vector3 forward;

    bool isDirty;
  };
}
