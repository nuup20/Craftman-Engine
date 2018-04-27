#pragma once
#include "dqGraphicsBufferDX.h"
#include "dqDeviceContextDX.h"
#include "dqDeviceDX.h"
#include "dqVertexDX.h"

namespace dqEngineSDK
{
  template< typename T >
  class dqVertexBufferDX :
    public dqGraphicsBufferDX
  {
  public:
    dqVertexBufferDX();
    ~dqVertexBufferDX();

    void      
    init();
    
    void      
    destroy();
    
    HRESULT   
    create( dqDeviceDX* pd3dDevice, Vector < T >  & vertexList );
    
    void      
    setBuffer(dqDeviceContextDX contextDev);

  private:
    ID3D11Buffer * m_pVertexBuffer;   
  };  

  template<typename T>
  inline dqVertexBufferDX<T>::dqVertexBufferDX()
  {
    this->init();
  }

  template<typename T>
  inline dqVertexBufferDX<T>::~dqVertexBufferDX()
  {
    this->destroy();
  }

  template<typename T>
  inline void 
  dqVertexBufferDX<T>::init()
  {
    m_pVertexBuffer = nullptr;
  }

  template<typename T>
  inline void 
  dqVertexBufferDX<T>::destroy()
  {   
  }

  template < typename T >
  inline HRESULT 
  dqVertexBufferDX<T>::create( dqDeviceDX *     pd3dDevice,
                               Vector < T > &   vertexList )
  {
    /************************************************************************/
    /* Buffer Description                                                   */
    /************************************************************************/
    D3D11_BUFFER_DESC bufferDesc;
    SecureZeroMemory(&bufferDesc, sizeof(bufferDesc));

    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof( T ) * vertexList.size();
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;

    /************************************************************************/
    /* Sub Resource Data                                                    */
    /************************************************************************/
    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = &vertexList[0];
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    /************************************************************************/
    /* Vertex Buffer Creation                                               */
    /************************************************************************/
    HRESULT hr;
    hr = pd3dDevice->createBuffer(&bufferDesc, &initData, &m_pVertexBuffer);

    return hr;
  }
  
  template<typename T>
  inline void 
  dqVertexBufferDX<T>::setBuffer(dqDeviceContextDX contextDev)
  {
    /************************************************************************/
    /* Set Vertex Buffers                                                   */
    /************************************************************************/
    if (!m_pVertexBuffer) 
    {
      return;
    }
    
    uint32 stride = sizeof(T);
    uint32 offset = 0;
    contextDev.setVertexBuffers( 1, &m_pVertexBuffer, stride, offset);
  }
}

