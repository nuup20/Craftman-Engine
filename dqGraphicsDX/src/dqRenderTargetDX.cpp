#include "dqGraphicsDXPrerequisites.h"
#include "dqRenderTargetDX.h"

namespace dqEngineSDK
{
  dqRenderTargetDX::dqRenderTargetDX()
  {
  }

  dqRenderTargetDX::dqRenderTargetDX(const dqRenderTargetDX & renderTarget)
  {
    m_renderTargetView = renderTarget.m_renderTargetView;
  }

  dqRenderTargetDX::~dqRenderTargetDX()
  {
  }

  void 
  dqRenderTargetDX::init()
  {
  }

  void 
  dqRenderTargetDX::clear()
  {
    if (m_texture2D) {
      m_texture2D->Release();
      m_texture2D = nullptr;
    }
  }

  ID3D11RenderTargetView** 
  dqRenderTargetDX::getRTViewReference()
  {
    return &m_renderTargetView;
  }

  ID3D11RenderTargetView* 
  dqRenderTargetDX::getRTViewPointer()
  {
    return m_renderTargetView;
  }
}
