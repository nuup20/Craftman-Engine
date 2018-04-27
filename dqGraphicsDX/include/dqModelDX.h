#pragma once
#include "dqGraphicsDXPrerequisites.h"

namespace dqEngineSDK 
{
  class dqDeviceContextDX;
  class dqDeviceDX;
  class dqMeshDX;
  class dqPlane;
  class dqMaterialDX;
  class dqVertexShaderDX;
  class dqPixelShaderDX;

  class DQ_GRAPHICSDX_EXPORT dqModelDX
  {
  public:
    dqModelDX();
    ~dqModelDX();

    void 
    init();

    void
    draw(dqDeviceContextDX& device);

    void 
    setBuffers( dqDeviceContextDX& context );
    
    void 
    destroy();

    void 
    addMesh( dqMeshDX* pMesh );

    void
      addVertexShader(dqVertexShaderDX* pVertexShader);

    void
      addPixelShader(dqPixelShaderDX* pPixelShader);    

    void 
    createPlane( dqPlane* plane, int32 divX, int32 divY );
    
    void 
    createTriangle( dqDeviceDX* device );

  private:
    Vector< dqMeshDX* > m_meshList;
  };
}