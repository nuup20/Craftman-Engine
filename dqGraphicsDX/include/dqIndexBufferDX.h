#pragma once
#include "dqGraphicsBufferDX.h"
#include "dqDeviceDX.h"
#include "dqDeviceContextDX.h"

namespace dqEngineSDK
{
  template < typename T >
  class dqIndexBufferDX :
    public dqGraphicsBufferDX
  {
  public:
    dqIndexBufferDX();
    ~dqIndexBufferDX();

    void      
    init();
    
    void      
    destroy();
    
    HRESULT   
    create( dqDeviceDX* pd3dDevice, Vector < T >& pIndices );

    void
    setBuffers(dqDeviceContextDX context);
    
  private:
    ID3D11Buffer* m_pIndexBuffer; 
  };  

  template<typename T>
  inline dqIndexBufferDX<T>::dqIndexBufferDX()
  {
    this->init();
  }

  template<typename T>
  inline dqIndexBufferDX<T>::~dqIndexBufferDX()
  {
    this->destroy();
  }

  template<typename T>
  inline void 
  dqIndexBufferDX<T>::init()
  {
    m_pIndexBuffer = nullptr;
  }

  template<typename T>
  inline void 
  dqIndexBufferDX<T>::destroy()
  {
   
  }

  template<typename T>
  inline HRESULT 
  dqIndexBufferDX<T>::create(dqDeviceDX*  pd3dDevice, Vector<T>& pIndices )
  {
    /************************************************************************/
    /* Copy Indices                                                         */
    /************************************************************************/
    if (!pIndices.size())
    {
      return E_FAIL;
    }  

    /************************************************************************/
    /* Buffer Description                                                   */
    /************************************************************************/
    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(T) * pIndices.size();
    bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;

    /************************************************************************/
    /* Subresource Data                                                     */
    /************************************************************************/
    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = &pIndices[0];
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    /************************************************************************/
    /* Buffer Creation                                                      */
    /************************************************************************/
    HRESULT hr;

    hr = pd3dDevice->createBuffer(&bufferDesc, &initData, &m_pIndexBuffer);
    return hr;
  }

  template<typename T>
  inline void 
  dqIndexBufferDX<T>::setBuffers(dqDeviceContextDX context)
  {
    /************************************************************************/
    /* Set Index Buffers                                                   */
    /************************************************************************/
    if (!m_pIndexBuffer)
    {
      return;
    }

    uint32 offset = 0;
    context.setIndexBuffers(m_pIndexBuffer, offset);
    return;
  }

}

