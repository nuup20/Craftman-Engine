#include "dqMaterialDX.h"

#include "dqDeviceContextDX.h"

namespace dqEngineSDK
{
  dqMaterialDX::dqMaterialDX()
  {
    m_pPixelShader = nullptr;
    m_pVertexShader = nullptr;
    this->init();
  }

  dqMaterialDX::~dqMaterialDX()
  {
    this->destroy();
  }

  void 
  dqMaterialDX::init()
  {    
  }

  void 
  dqMaterialDX::destroy()
  {
  }

  void dqMaterialDX::setShaders(dqDeviceContextDX & deviceContext)
  {
    if (m_pVertexShader != nullptr) {
      deviceContext.vsSetShader(*m_pVertexShader);
    }

    if (m_pPixelShader != nullptr) {
      deviceContext.psSetShader(*m_pPixelShader);
    }    
  }

  void 
  dqMaterialDX::setVertexShader(dqVertexShaderDX * pVertexShader)
  {
    m_pVertexShader = pVertexShader;
  }

  void 
  dqMaterialDX::setPixelShader(dqPixelShaderDX * pPixelShader)
  {
    m_pPixelShader = pPixelShader;
  }

}

