#pragma once
#include "dqGraphicsDXPrerequisites.h"

namespace dqEngineSDK
{
  class dqVertexShaderDX;
  class dqPixelShaderDX;
  class dqDeviceContextDX;

  class DQ_GRAPHICSDX_EXPORT dqMaterialDX
  {
  public:
    dqMaterialDX();
    ~dqMaterialDX();

    void
    init();

    void
    destroy();

    void
    setShaders(dqDeviceContextDX& device);
    
    void
    setVertexShader( dqVertexShaderDX* pVertexShader );

    void
    setPixelShader( dqPixelShaderDX* pPixelShader );
  
  private:
    dqVertexShaderDX* m_pVertexShader;
    dqPixelShaderDX* m_pPixelShader;    
  };
}