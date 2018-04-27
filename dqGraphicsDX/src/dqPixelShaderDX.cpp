#include "dqGraphicsDXPrerequisites.h"
#include "dqPixelShaderDX.h"
#include "dqDeviceDX.h"

#include <d3dcompiler.h>

namespace dqEngineSDK
{  
  dqPixelShaderDX::dqPixelShaderDX()
  {
  }
  dqPixelShaderDX::~dqPixelShaderDX()
  {
  }

  void dqPixelShaderDX::create(WString fileDirectory, 
                               String functionName, 
                               dqDeviceDX & device)
  {
    //CompileShader
    //this->compileFromFile(L"shaders.shader", "VShader");
    this->compileFromFile(fileDirectory, functionName);

    //Encapsulate both shaders into shaders object.
    device.createPixelShader(*this);
  }

  void 
  dqPixelShaderDX::clear()
  {
    m_pPS->Release();
  }

  void 
  dqPixelShaderDX::compileFromFile(const WString& file, const String& funcName)
  {
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if DQ_DEBUG_MODE
    flags |= D3DCOMPILE_DEBUG;
#else

#endif
    D3DCompileFromFile(file.c_str(), nullptr, nullptr, funcName.c_str(), "ps_4_0", flags, 0, &m_blob, nullptr);
  }
  
  /************************************************************************/
  /* Gets & Sets                                                          */
  /************************************************************************/
  ID3D11PixelShader* 
  dqPixelShaderDX::getPPS()
  {
    return m_pPS;
  }

  ID3D11PixelShader** 
  dqPixelShaderDX::getPPSReference()
  {
    return &m_pPS;
  }
}
