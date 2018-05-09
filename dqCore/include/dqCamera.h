#pragma once

#include <dqVector3.h>

#include "dqCorePrerequisites.h"

namespace dqEngineSDK 
{
  struct DQ_CORE_EXPORT dqCamera 
  {
  public:

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
    
    // VAMOS A INCLUIR SFML PARA HACER PRUEBAS DE LOS INPUTS, DESPLEGAR EN CONSOLA LA POSICION DE LA CAMARA
    // Y COMPROBAR QUE LOS VECTORES EST�N FUNCIONANDO CORRECTAMENTE.
    void 
      pan(Vector3 force);
    
    void 
      rotate();
    
    void 
      orbitate();

    Vector3 position;
    Vector3 target;
  };
}
