#pragma once

#include "dqShaderDX.h"
namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqPixelShaderDX:
    public dqShaderDX
  {
  public:
    dqPixelShaderDX();
    ~dqPixelShaderDX();

    void Clear();

    virtual void CompileFromFile(const WString& file, const String& funcName);
    ID3D11PixelShader *   GetPPS();
    ID3D11PixelShader **  GetPPSReference();

  private:
    ID3D11PixelShader * m_pPS;
  };
}