#include "dqGraphicsDXPrerequisites.h"
#include "dqDeviceContextDX.h"
#include "dqRenderTargetDX.h"
#include "dqViewportDX.h"
#include "dqVertexShaderDX.h"
#include "dqPixelShaderDX.h"
#include "dqInputLayoutDX.h"

namespace dqEngineSDK
{
  dqDeviceContextDX::dqDeviceContextDX()
  {
  }

  dqDeviceContextDX::~dqDeviceContextDX()
  {
    this->clear();
  }

  void 
  dqDeviceContextDX::init() 
  {
  }

  void 
  dqDeviceContextDX::clear() 
  {
    if (m_devCont) {
      m_devCont->Release();
    }
  }

  void 
  dqDeviceContextDX::setRenderTargets(int32 nRenderTargets, 
                                      dqRenderTargetDX & renderTarget) 
  {
    m_devCont->OMSetRenderTargets(nRenderTargets, 
                                  renderTarget.getRTViewReference(), 
                                  nullptr);
  }

  void 
  dqDeviceContextDX::setViewport(int32 nViewports, 
                                 dqViewportDX & viewport) 
  {
    m_devCont->RSSetViewports(nViewports, viewport.GetPointer());
  }

  void 
  dqDeviceContextDX::vsSetShader(dqVertexShaderDX & vShader) 
  {
    m_devCont->VSSetShader(vShader.getPVS(), 0, 0);
  }

  void 
  dqDeviceContextDX::psSetShader(dqPixelShaderDX & pShader) 
  {
    m_devCont->PSSetShader(pShader.getPPS(), 0, 0);
  } 

  void 
  dqDeviceContextDX::setInputLayout(dqInputLayoutDX & iLayout) 
  {
    DQ_ASSERT(iLayout.GetLayoutPointer()
              && "null LayoutPointer.");

    m_devCont->IASetInputLayout(iLayout.GetLayoutPointer());
  }

  void 
  dqDeviceContextDX::setVertexBuffers(uint32          numBuffers,
                                      ID3D11Buffer ** vertexBuffer,
                                      uint32          stride,
                                      uint32          offset) 
  {
    m_devCont->IASetVertexBuffers(0, 
                                  numBuffers,
                                  vertexBuffer,
                                  &stride, 
                                  &offset);
  }

  void 
  dqDeviceContextDX::setIndexBuffers(ID3D11Buffer * buffer, uint32 offset)
  {
    m_devCont->IASetIndexBuffer(buffer, DXGI_FORMAT_R32_UINT, offset);
    return;
  }

  void 
  dqDeviceContextDX::setPrimitiveTopology( PRIMITIVE_TOPOLOGY::E topology )
  {   
    m_devCont->IASetPrimitiveTopology( primitiveTopologyTraductor(topology) );
  }

  void 
  dqDeviceContextDX::draw(uint32 nVertex, uint32 fVertex) 
  {
    m_devCont->Draw(nVertex, fVertex);
  }

  void
  dqDeviceContextDX::drawIndexed( uint32 numIndices, 
                                  uint32 startPosition, 
                                  uint32 baseVertexLocation)
  {
    m_devCont->DrawIndexed(numIndices, startPosition, baseVertexLocation);
  }

  void 
  dqDeviceContextDX::clearRenderTargetView(dqRenderTargetDX & renderTarget,
                                           LinearColor & clearColor) 
  {
    m_devCont->ClearRenderTargetView (renderTarget.getRTViewPointer(), 
                                      reinterpret_cast<float*>(&clearColor));
  }

  ID3D11DeviceContext ** 
  dqDeviceContextDX::getReference() 
  {
    return &m_devCont;
  }

  D3D_PRIMITIVE_TOPOLOGY
  dqDeviceContextDX::primitiveTopologyTraductor(PRIMITIVE_TOPOLOGY::E topology)
  {
    switch (topology)
    {
    case dqEngineSDK::PRIMITIVE_TOPOLOGY::kTriangleList:
      return D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
    case dqEngineSDK::PRIMITIVE_TOPOLOGY::kPointList:
      return D3D10_PRIMITIVE_TOPOLOGY_POINTLIST;
    default:
      return D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED;
    }
  }
}