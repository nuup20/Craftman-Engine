#pragma once
#include "dqGraphicsDXPrerequisites.h"
#include "dqIndexBufferDX.h"
#include "dqVertexBufferDX.h"
#include "dqConstantBufferDX.h"

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
    setBuffers(dqDeviceContextDX & context);
    
    void    
    destroy();
    
    HRESULT 
    create( dqDeviceDX *          device,
            Vector<dqVertexDX> &  vertices,
            Vector<uint32> &      indices);

  private:
    dqIndexBufferDX   <uint32>          m_indexBuffer;
    dqVertexBufferDX  <dqVertexDX>      m_vertexBuffer;
    dqConstantBufferDX                  m_constantBuffer;
  };
}