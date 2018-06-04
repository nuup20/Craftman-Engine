#pragma once
#include "dqGraphicsBufferDX.h"
#include "dqDeviceDX.h"
#include "dqDeviceContextDX.h"

namespace dqEngineSDK 
{
  template < typename T >
  class  dqConstantBufferDX :
    public dqGraphicsBufferDX
  {
  public:
    dqConstantBufferDX();
    ~dqConstantBufferDX();

    void init();

    void destroy();

    HRESULT
    create( dqDeviceDX* pd3dDevice, Vector < T >& pConstant );

    void
    setInVertexShader(dqDeviceContextDX* pd3dDeviceContext, UINT regNum = 0) {
      (*pd3dDeviceContext->getReference())->VSSetConstantBuffers(0, 1, &m_pConstantBuffer);
    }

  public:
    ID3D11Buffer * m_pConstantBuffer;
  };

  template<typename T>
  inline 
  dqConstantBufferDX<T>::dqConstantBufferDX()
  {
    this->init();
  }

  template<typename T>
  inline 
  dqConstantBufferDX<T>::~dqConstantBufferDX()
  {
    this->destroy();
  }

  template<typename T>
  inline void 
  dqConstantBufferDX<T>::init()
  {
    m_pConstantBuffer = nullptr;
  }

  template<typename T>
  inline void 
  dqConstantBufferDX<T>::destroy()
  {

  }

  template<typename T>
  inline HRESULT 
  dqConstantBufferDX<T>::create(dqDeviceDX * pd3dDevice, Vector<T>& pConstant)
  {
    /************************************************************************/
    /* Copy Indices                                                         */
    /************************************************************************/
    if (!pConstant.size())
    {
      return E_FAIL;
    }

    /************************************************************************/
    /* Buffer Description                                                   */
    /************************************************************************/
    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    bufferDesc.ByteWidth = sizeof(T) * pConstant.size();
    bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    bufferDesc.MiscFlags = 0;

    /************************************************************************/
    /* Subresource Data                                                     */
    /************************************************************************/
    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = &pConstant[0];
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    /************************************************************************/
    /* Buffer Creation                                                      */
    /************************************************************************/
    HRESULT hr;

    hr = pd3dDevice->createBuffer(&bufferDesc, &initData, &m_pConstantBuffer);
    return hr;
  }

}

