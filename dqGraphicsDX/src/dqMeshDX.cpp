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
    
  }
  
  void 
  dqMeshDX::setBuffers(dqDeviceContextDX & context)
  {
    /************************************************************************/
    /* Set IB and VB                                                        */
    /************************************************************************/
    m_vertexBuffer.setBuffer(context);
    //TODO set IB;
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
  dqMeshDX::create(dqDeviceDX * device, Vector<dqVertexDX>& vertices, Vector<uint32>& indices)
  {
    HRESULT hr;
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
}
