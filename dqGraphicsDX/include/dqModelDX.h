#pragma once
#include "dqGraphicsDXPrerequisites.h"
#include "dqPlane.h"
#include "dqMeshDX.h"

namespace dqEngineSDK 
{
  class DQ_GRAPHICSDX_EXPORT dqModelDX
  {
  public:
    dqModelDX();
    ~dqModelDX();

    void 
    init();
    void 
    setBuffers(dqDeviceContextDX & context);
    void 
    destroy();

    void 
    addMesh( dqMeshDX * pMesh );
    void 
    createPlane( dqPlane * plane, int32 divX, int32 divY );
    void 
    createTriangle(dqDeviceDX * device );

  private:
    Vector< dqMeshDX * > m_meshList;
  };
}