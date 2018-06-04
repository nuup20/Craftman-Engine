#include "dqGraphicsDXPrerequisites.h"
#include "dqVertexShaderDX.h"
#include "dqDeviceDX.h"

#include <d3dcompiler.h>

namespace dqEngineSDK
{
  dqVertexShaderDX::dqVertexShaderDX()
  {
  }

  dqVertexShaderDX::~dqVertexShaderDX()
  {
  }

  void dqVertexShaderDX::create(WString fileDirectory, 
                                String functionName, 
                                dqDeviceDX& device)
  {    
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS;
    #if DQ_DEBUG_MODE
    flags |= D3DCOMPILE_DEBUG;
    #else

    #endif

    m_blob = nullptr;
    ID3D10Blob* pError = nullptr;

    HRESULT hr = D3DCompileFromFile( fileDirectory.c_str(),
                        nullptr,
                        nullptr,
                        functionName.c_str(),
                        "vs_4_0",
                        flags,
                        0,
                        &m_blob,
                        &pError);

    if (FAILED(hr))
    {
      char* pErr = (char*)pError->GetBufferPointer();
      String texto;
      texto.resize(pError->GetBufferSize());
      memcpy(&texto[0], pErr, pError->GetBufferSize());
      pError->Release();
    }

    //Encapsulate shader
    device.createVertexShader(*this);  
  }

  void
  dqVertexShaderDX::clear()
  {
    m_pVertexShader->Release();
  } 

  void dqVertexShaderDX::compileFromFile(const WString & file, const String & funcName)
  {
  }

  ID3D11VertexShader *
  dqVertexShaderDX::getPVS()
  {
    return m_pVertexShader;
  }

  ID3D11VertexShader ** 
  dqVertexShaderDX::getPVSReference()
  {
    return &m_pVertexShader;
  }
}
