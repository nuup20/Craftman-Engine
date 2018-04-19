#include "dqGraphicsDXPrerequisites.h"
#include "dqDeviceDX.h"
#include "dqRenderTargetDX.h"
#include "dqVertexShaderDX.h"
#include "dqPixelShaderDX.h"
#include "dqTriangleDX.h"
#include "dqInputLayoutDX.h"

namespace dqEngineSDK
{
  dqDeviceDX::dqDeviceDX()
  {
  }
  dqDeviceDX::~dqDeviceDX()
  {
    this->clear();
  }
  void dqDeviceDX::init()
  {

  }
  void dqDeviceDX::clear()
  {
    if (m_device)
    {
      m_device->Release();
    }
    return;
  }
  void dqDeviceDX::createRenderTargetView(dqRenderTargetDX & renderTarget)
  {
    m_device->CreateRenderTargetView(renderTarget.GetPointer(), 
                                     NULL, 
                                     renderTarget.GetRTViewReference());
    return;
  }
  void dqDeviceDX::createVertexShader(dqVertexShaderDX & vShader)
  {
     m_device->CreateVertexShader(vShader.GetBufferPointer(), 
                                  vShader.GetBufferSize(), 
                                  NULL, 
                                  vShader.GetPVSReference());
    return;
  }
  void dqDeviceDX::createPixelShader(dqPixelShaderDX & pShader)
  {
    m_device->CreatePixelShader(pShader.GetBufferPointer(), 
                                pShader.GetBufferSize(),
                                NULL, 
                                pShader.GetPPSReference());
    return;
  }

  HRESULT 
  dqDeviceDX::createBuffer(
                            D3D11_BUFFER_DESC *      descriptor,
                            D3D11_SUBRESOURCE_DATA * subresource,
                            ID3D11Buffer **          buffer
                          )
  {
    HRESULT hr;
    hr = m_device->CreateBuffer(  
                                descriptor,
                                subresource,
                                buffer
                               );
    return hr;
  }
  
  void dqDeviceDX::createInputLayout(dqInputLayoutDX & iLayout, dqVertexShaderDX & vShader)
  {
   m_device->CreateInputLayout(iLayout.ied, 
                               2, 
                               vShader.GetBlobPointer()->GetBufferPointer(),
                               vShader.GetBlobPointer()->GetBufferSize(),
                               iLayout.GetLayoutReference());
    return;
  }
  ID3D11Device ** dqDeviceDX::getReference()
  {
    return &m_device;
  }
}