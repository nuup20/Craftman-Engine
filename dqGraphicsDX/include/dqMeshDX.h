#pragma once
#include "dqGraphicsDXPrerequisites.h"
#include "dqIndexBufferDX.h"
#include "dqVertexBufferDX.h"
#include "dqConstantBufferDX.h"
#include "dqMaterialDX.h"

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqMeshDX
  {
  public:
    dqMeshDX();
    ~dqMeshDX();

    void    
    init();
    
    void
    draw(dqDeviceContextDX& context);
    
    void    
    destroy();
    
    void    
    setBuffers(dqDeviceContextDX & context);

    HRESULT 
    create( dqDeviceDX *          device,
            Vector<dqVertexDX> &  vertices,
            Vector<uint32> &      indices); 

    void
    setMaterialVertexShader(dqVertexShaderDX* pVertexShader);

    void
    setMaterialPixelShader(dqPixelShaderDX* pPixelShader);

  private:
    uint32  m_initPosition;
    uint32  m_finalPosition;
    uint32  m_vertexCount;

    dqMaterialDX                    m_material;
    dqIndexBufferDX   <uint32>      m_indexBuffer;
    dqVertexBufferDX  <dqVertexDX>  m_vertexBuffer;
    dqConstantBufferDX <uint32>     m_constantBuffer;
  };
}