#pragma once

#include "dqShaderDX.h"

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqVertexShaderDX :
    public dqShaderDX
  {
  public:
    dqVertexShaderDX();
    ~dqVertexShaderDX();
    
    void Clear();

    virtual void CompileFromFile(const WString& file, const String& funcName);
    ID3D11VertexShader *  GetPVS();
    ID3D11VertexShader ** GetPVSReference();

  private:
    ID3D11VertexShader * m_pVS;
  };
}