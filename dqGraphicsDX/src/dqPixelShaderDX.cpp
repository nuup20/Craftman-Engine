#include "dqGraphicsDXPrerequisites.h"
#include "dqPixelShaderDX.h"

#include <d3dcompiler.h>

namespace dqEngineSDK
{  
  dqPixelShaderDX::dqPixelShaderDX()
  {
  }
  dqPixelShaderDX::~dqPixelShaderDX()
  {
  }
  void dqPixelShaderDX::Clear()
  {
    m_pPS->Release();
  }
  void dqPixelShaderDX::CompileFromFile(const WString& file, const String& funcName)
  {
    D3DCompileFromFile(file.c_str(), nullptr, nullptr, funcName.c_str(), "ps_4_0", 0, 0, &m_blob, nullptr);
  }
  ID3D11PixelShader * dqPixelShaderDX::GetPPS()
  {
    return m_pPS;
  }
  ID3D11PixelShader ** dqPixelShaderDX::GetPPSReference()
  {
    return &m_pPS;
  }
}
