#pragma once

#include "dqTextureDX.h"

struct ID3D11RenderTargetView;
namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqRenderTargetDX : public dqTextureDX
  {
  public:
    dqRenderTargetDX();
    dqRenderTargetDX(const dqRenderTargetDX&);
    ~dqRenderTargetDX();

    void 
    init();
    
    void 
    clear();

    /**
     * Get Render Target View Reference.
     */
    ID3D11RenderTargetView**   
    getRTViewReference();    

    /**
     * Get Render Target View Pointer.
     */
    ID3D11RenderTargetView*    
    getRTViewPointer();

  private:
    ID3D11RenderTargetView * m_renderTargetView;
  };  
}