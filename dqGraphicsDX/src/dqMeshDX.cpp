#include "dqMeshDX.h"
#include "dqVertexDX.h"

namespace dqEngineSDK 
{
  dqMeshDX::dqMeshDX()
  {
    this->init();
  }

  dqMeshDX::~dqMeshDX()
  {
    this->destroy();
  }

  void 
  dqMeshDX::init()
  {
    m_initPosition = 0;
    m_finalPosition = 0;   
  }

  void dqMeshDX::draw(dqDeviceContextDX & context)
  {
    /************************************************************************/
    /* Set Vertex & Pixel Shader                                            */
    /************************************************************************/
    m_material.setShaders(context);
    context.draw(m_vertexCount, 0);
  }
  
  void 
  dqMeshDX::setBuffers(dqDeviceContextDX & context)
  {
    /************************************************************************/
    /* Set IB and VB                                                        */
    /************************************************************************/
    m_vertexBuffer.setBuffer(context);
    //TODO: set IB;
  }

  void 
  dqMeshDX::destroy()
  {
    /************************************************************************/
    /* Destroy All Buffers                                                  */
    /************************************************************************/
    m_indexBuffer.destroy();
    m_vertexBuffer.destroy();
    //m_constantBuffer.destroy();
  }

  HRESULT 
  dqMeshDX::create(dqDeviceDX * device, 
                   Vector<dqVertexDX>& vertices, 
                   Vector<uint32>& indices)
  {
    HRESULT hr;

    m_vertexCount = (uint32)vertices.size();

    /************************************************************************/
    /* Create VertexBuffer                                                  */
    /************************************************************************/
    hr = m_vertexBuffer.create(device, vertices);
    if (FAILED(hr)) {
      return hr;
    }

    /************************************************************************/
    /* Create IndexBuffer                                                   */
    /************************************************************************/
    hr = m_indexBuffer.create(device, indices);
    if (FAILED(hr)) {
      return hr;
    }

    return hr;
  }

  void 
  dqMeshDX::setMaterialVertexShader(dqVertexShaderDX * pVertexShader)
  {
    m_material.setVertexShader(pVertexShader);
  }

  void 
  dqMeshDX::setMaterialPixelShader(dqPixelShaderDX * pPixelShader)
  {
    m_material.setPixelShader(pPixelShader);
  }
}
