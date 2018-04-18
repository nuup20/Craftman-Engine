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

    void Init();
    void Clear();

    ID3D11RenderTargetView **   GetRTViewReference();
    ID3D11RenderTargetView *    GetRTViewPointer();

  private:
    ID3D11RenderTargetView * m_renderTargetView;
  };  
}