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
    void      
    init();
    
    void      
    destroy();
    
    HRESULT   
    create( dqDeviceDX * pd3dDevice, Vector < T >  & vertexList );
    
    void      
    setBuffer(dqDeviceContextDX contextDev);

    dqVertexBufferDX();
    ~dqVertexBufferDX();

  private:
    ID3D11Buffer *          m_pVertexBuffer;    
    Vector< T >             m_vertexList;
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
    /************************************************************************/
    /* Clear and Destroy VertexList                                         */
    /************************************************************************/
    if (!m_vertexList.empty())
    {
      m_vertexList.clear();      
    }
  }

  template < typename T >
  inline HRESULT 
  dqVertexBufferDX<T>::create( dqDeviceDX *     pd3dDevice,
                               Vector < T > &   vertexList )
  {
    /************************************************************************/
    /* Copy Vertices                                                        */
    /************************************************************************/
    if (!m_vertexList.empty())
    {
      m_vertexList.clear();
    }    
    m_vertexList = vertexList;

    /************************************************************************/
    /* Buffer Description                                                   */
    /************************************************************************/
    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage =            D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth =        sizeof( T ) * m_vertexList.size();
    bufferDesc.BindFlags =        D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.CPUAccessFlags =   0;
    bufferDesc.MiscFlags =        0;

    /************************************************************************/
    /* Sub Resource Data                                                    */
    /************************************************************************/
    D3D11_SUBRESOURCE_DATA        initData;
    initData.pSysMem =            &m_vertexList;
    initData.SysMemPitch =        0;
    initData.SysMemSlicePitch =   0;

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

