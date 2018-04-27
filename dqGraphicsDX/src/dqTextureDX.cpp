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

  void 
  dqTextureDX::init()
  {
  }
  
  void 
  dqTextureDX::clear()
  {
    m_texture2D->Release();
  }
  
  ID3D11Texture2D** 
  dqTextureDX::getReference()
  {
    return &m_texture2D;
  }
  
  ID3D11Texture2D* 
  dqTextureDX::getPointer() 
  {
    return m_texture2D;
  }
}