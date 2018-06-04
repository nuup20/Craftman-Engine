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
    update();

    /**
     * @brief Movimiento de la posición de la Cámara.
     * @param force Dirección con magnitud aplicada al movimiento.
     */
    void 
    move(Vector3 force);

    /**
     * @brief Posiciona la Cámara en una coordenada específica.
     */
    void
    move(float x, float y, float z);
    
    void 
    pan(Vector3 force);
    
    void 
    rotate();
    
    void 
    orbitate();

    Vector3 position;
    Vector3 target;

    Matrix4x4 camera_to_world;

    bool isDirty;
  };
}
