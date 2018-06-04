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
     * @brief Movimiento de la posici�n de la C�mara.
     * @param force Direcci�n con magnitud aplicada al movimiento.
     */
    void 
    move(Vector3 force);

    /**
     * @brief Posiciona la C�mara en una coordenada espec�fica.
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
