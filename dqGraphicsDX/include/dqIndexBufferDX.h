#pragma once
#include "dqGraphicsBufferDX.h"
#include "dqDeviceDX.h"

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
    create( dqDeviceDX * pd3dDevice, Vector < T > & pIndices );
    
  private:
    ID3D11Buffer *          m_pIndexBuffer;    
    Vector < T > *          m_pIndexList;
  };  

  template<typename T>
  inline void 
  dqIndexBufferDX<T>::init()
  {
    m_pIndexBuffer = nullptr;
    m_pIndexList = nullptr;
  }

  template<typename T>
  inline void 
  dqIndexBufferDX<T>::destroy()
  {
    /************************************************************************/
    /* Clear and Destroy IndexList                                          */
    /************************************************************************/
    if (m_pIndexList != nullptr)
    {
      m_pIndexList->clear();
      delete m_pIndexList;
    }
  }

  template<typename T>
  inline HRESULT 
  dqIndexBufferDX<T>::create(dqDeviceDX *  pd3dDevice, Vector<T>  & pIndices )
  {
    /************************************************************************/
    /* Copy Indices                                                         */
    /************************************************************************/
    if (m_pIndexList != nullptr)
    {
      m_pIndexList->clear();
      delete m_pIndexList;
    }

    m_pIndexList = new Vector< T >( pIndices );

    /************************************************************************/
    /* Buffer Description                                                   */
    /************************************************************************/
    D3D11_BUFFER_DESC             bufferDesc;
    bufferDesc.Usage =            D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth =        sizeof(T) * pIndices.size();
    bufferDesc.BindFlags =        D3D11_BIND_INDEX_BUFFER;
    bufferDesc.CPUAccessFlags =   0;
    bufferDesc.MiscFlags =        0;

    /************************************************************************/
    /* Subresource Data                                                     */
    /************************************************************************/
    D3D11_SUBRESOURCE_DATA      initData;
    initData.pSysMem =          &m_pIndexList;
    initData.SysMemPitch =      0;
    initData.SysMemSlicePitch = 0;

    /************************************************************************/
    /* Buffer Creation                                                      */
    /************************************************************************/
    HRESULT hr;

    hr = pd3dDevice->createBuffer(&bufferDesc, &initData, &m_pIndexBuffer);
    return hr;
  }

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
}

