#pragma once
#include "dqGraphicsDXPrerequisites.h"

namespace dqEngineSDK
{
  class dqRenderTargetDX;
  class DQ_GRAPHICSDX_EXPORT dqSwapChainDX
  {
  public:
    dqSwapChainDX();
    ~dqSwapChainDX();

    void 
    Init();
    
    void 
    Clear();
    
    void 
    GetBuffer(dqRenderTargetDX &);
    
    void 
    Present();

    IDXGISwapChain ** GetReference();

  private:
    IDXGISwapChain * m_sc;
  };
}
