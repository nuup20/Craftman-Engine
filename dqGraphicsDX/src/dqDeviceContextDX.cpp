#include "dqGraphicsDXPrerequisites.h"
#include "dqDeviceContextDX.h"
#include "dqRenderTargetDX.h"
#include "dqViewportDX.h"
#include "dqVertexShaderDX.h"
#include "dqPixelShaderDX.h"
#include "dqInputLayoutDX.h"
#include "dqTriangleDX.h"

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
  dqDeviceContextDX::init() {
  }

  void 
  dqDeviceContextDX::clear() {
    if (m_devCont) {
      m_devCont->Release();
    }
  }

  void 
  dqDeviceContextDX::setRenderTargets(int32 nRenderTargets, 
                                      dqRenderTargetDX & renderTarget) {
    m_devCont->OMSetRenderTargets(nRenderTargets, 
                                  renderTarget.GetRTViewReference(), 
                                  nullptr);
  }

  void 
  dqDeviceContextDX::setViewport(int32 nViewports, 
                                 dqViewportDX & viewport) {
    m_devCont->RSSetViewports(nViewports, viewport.GetPointer());
  }

  void 
  dqDeviceContextDX::vsSetShader(dqVertexShaderDX & vShader) {
    m_devCont->VSSetShader(vShader.GetPVS(), 0, 0);
  }

  void 
  dqDeviceContextDX::psSetShader(dqPixelShaderDX & pShader) {
    m_devCont->PSSetShader(pShader.GetPPS(), 0, 0);
  }

  void
  dqDeviceContextDX::mapGeometry(const dqTriangleDX & geometry) {
    DQ_ASSERT(geometry.GetVBufferPointer() 
              && "null Vertex Buffer Pointer");

    //Map the Buffer. d3dmsr = D3D Mapped Subresource.
    D3D11_MAPPED_SUBRESOURCE d3dmsr;
    memset(&d3dmsr, 0, sizeof(D3D11_MAPPED_SUBRESOURCE));

    m_devCont->Map(geometry.GetVBufferPointer(), 
                   0, 
                   D3D11_MAP_WRITE_DISCARD, 
                   0, 
                   &d3dmsr);

    //Copy data.
    memcpy(d3dmsr.pData, 
           geometry.OurVertices, 
           sizeof(geometry.OurVertices));

    //UnMap.
    m_devCont->Unmap(geometry.GetVBufferPointer(), 0);
  }

  void 
  dqDeviceContextDX::setInputLayout(dqInputLayoutDX & iLayout) {
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
  dqDeviceContextDX::setPrimitiveTopology()
  {
    m_devCont->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
  }

  void 
    dqDeviceContextDX::draw(int32 nVertex, int32 fVertex) {
    m_devCont->Draw(nVertex, fVertex);
  }

  void 
  dqDeviceContextDX::clearRenderTargetView(dqRenderTargetDX & renderTarget,
                                           LinearColor & clearColor) {
    m_devCont->ClearRenderTargetView(renderTarget.GetRTViewPointer(), 
               reinterpret_cast<float*>(&clearColor));
  }

  ID3D11DeviceContext ** 
  dqDeviceContextDX::getReference() {
    return &m_devCont;
  }
}