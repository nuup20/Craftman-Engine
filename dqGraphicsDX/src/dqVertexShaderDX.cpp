#include "dqGraphicsDXPrerequisites.h"
#include "dqVertexShaderDX.h"

#include <d3dcompiler.h>

namespace dqEngineSDK
{
  dqVertexShaderDX::dqVertexShaderDX()
  {
  }
  dqVertexShaderDX::~dqVertexShaderDX()
  {
  }
  void dqVertexShaderDX::Clear()
  {
    m_pVS->Release();
  }
  void dqVertexShaderDX::CompileFromFile(const WString& file, const String& funcName)
  {
    D3DCompileFromFile(file.c_str(), 
                       nullptr, 
                       nullptr, 
                       funcName.c_str(), 
                       "vs_4_0", 
                       0, 
                       0, 
                       &m_blob, 
                       nullptr);    
    return;
  }
  ID3D11VertexShader * dqVertexShaderDX::GetPVS()
  {
    return m_pVS;
  }
  ID3D11VertexShader ** dqVertexShaderDX::GetPVSReference()
  {
    return &m_pVS;
  }
}
