#pragma once
#include "dqVertexDX.h"

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqTriangleDX
  {
  public:
    dqTriangleDX();
    ~dqTriangleDX();

    void 
    Init();
    
    void 
    Clear();

    D3D11_BUFFER_DESC *         
    GetBufferDescPointer();
    
    ID3D11Buffer *         
    GetVBufferPointer() const;
    
    ID3D11Buffer **         
    GetVBufferReference();
    
    D3D11_MAPPED_SUBRESOURCE *  
    GetMappedSubPointer();

    dqVertexDX OurVertices[3] =
    {
      { 0.0f, 0.5f, 0.0f, LinearColor(1.0f, 0.0f, 0.0f, 1.0f) },
      { 0.45f, -0.5, 0.0f, LinearColor(0.0f, 1.0f, 0.0f, 1.0f) },
      { -0.45f, -0.5f, 0.0f, LinearColor(0.0f, 0.0f, 1.0f, 1.0f) }
    };

  private:

    D3D11_BUFFER_DESC         m_bd;
    D3D11_MAPPED_SUBRESOURCE  m_ms;
    ID3D11Buffer     *        m_pVBuffer;
  };

}