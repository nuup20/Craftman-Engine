#include "dqGraphicsDXPrerequisites.h"
#include "dqTextureDX.h"

namespace dqEngineSDK
{
  dqTextureDX::dqTextureDX()
  {
  }
  dqTextureDX::dqTextureDX(const dqTextureDX & texture)
  {
    m_texture2D = texture.m_texture2D;
  }
  dqTextureDX::~dqTextureDX()
  {
  }
  void dqTextureDX::Init()
  {
  }
  void dqTextureDX::Clear()
  {
    m_texture2D->Release();
  }
  ID3D11Texture2D ** dqTextureDX::GetReference()
  {
    return &m_texture2D;
  }
  ID3D11Texture2D * dqTextureDX::GetPointer() 
  {
    return m_texture2D;
  }
}