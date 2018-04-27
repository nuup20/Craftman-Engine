#pragma once

#include "dqShaderDX.h"
namespace dqEngineSDK
{
  class dqDeviceDX;
  class DQ_GRAPHICSDX_EXPORT dqPixelShaderDX:
    public dqShaderDX
  {
  public:
    dqPixelShaderDX();
    ~dqPixelShaderDX();

    void create(WString fileDirectory,
                String functionName,
                dqDeviceDX& device);

    void clear();

    virtual void compileFromFile(const WString& file, const String& funcName);
    ID3D11PixelShader*   getPPS();
    ID3D11PixelShader**  getPPSReference();

  private:
    ID3D11PixelShader* m_pPS;
  };
}