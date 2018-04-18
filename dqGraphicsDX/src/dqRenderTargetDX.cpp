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
  void dqRenderTargetDX::Init()
  {
  }
  void dqRenderTargetDX::Clear()
  {
    m_texture2D->Release();
  }
  ID3D11RenderTargetView ** dqRenderTargetDX::GetRTViewReference()
  {
    return &m_renderTargetView;
  }
  ID3D11RenderTargetView * dqRenderTargetDX::GetRTViewPointer()
  {
    return m_renderTargetView;
  }
}
