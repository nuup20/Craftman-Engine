#include "dqGraphicsDXPrerequisites.h"
#include "dqViewportDX.h"

namespace dqEngineSDK
{
  dqViewportDX::dqViewportDX()
  {
  }
  dqViewportDX::~dqViewportDX()
  {
  }
  void dqViewportDX::Init(int32 width, int32 heigth)
  {
    ZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));

    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;
    m_viewport.Width = static_cast<FLOAT>(width);
    m_viewport.Height = static_cast<FLOAT>(heigth);

  }
  void dqViewportDX::Destroy()
  {
    
  }
  D3D11_VIEWPORT * dqViewportDX::GetPointer()
  {
    return &m_viewport;
  }
}

