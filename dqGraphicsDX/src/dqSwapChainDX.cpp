#include "dqSwapChainDX.h"
#include "dqRenderTargetDX.h"

namespace dqEngineSDK
{
  dqSwapChainDX::dqSwapChainDX()
  {
  }

  dqSwapChainDX::~dqSwapChainDX()
  {
  }

  void 
  dqSwapChainDX::Init()
  {
  }

  void 
  dqSwapChainDX::Clear()
  {
    m_sc->SetFullscreenState(FALSE, NULL);    //Set it in window mode. 
    m_sc->Release();
  }

  void 
  dqSwapChainDX::GetBuffer(dqRenderTargetDX & renderTarget)
  {
    assert(m_sc);
    this->m_sc->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(renderTarget.getReference()));
  }

  void 
  dqSwapChainDX::Present()
  {
    this->m_sc->Present(0,0);
  }

  IDXGISwapChain** 
  dqSwapChainDX::GetReference()
  {
    return &m_sc;
  }
}
