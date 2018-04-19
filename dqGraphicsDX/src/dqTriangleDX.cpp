#include "dqTriangleDX.h"

namespace dqEngineSDK
{
  dqTriangleDX::dqTriangleDX()
  {
  }
  dqTriangleDX::~dqTriangleDX()
  {
  }
  void dqTriangleDX::Init()
  {
    SecureZeroMemory(&m_bd, sizeof(m_bd));
    
    m_bd.Usage = D3D11_USAGE_DYNAMIC;               // write Access Access by CPU and GPU.
    m_bd.ByteWidth = sizeof(dqVertexDX) * 3;
    m_bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;      //Use as a vertex buffer.
    m_bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;   //Allow cpu to write in buffer.
  }
  void dqTriangleDX::Clear()
  {
  }
  D3D11_BUFFER_DESC * dqTriangleDX::GetBufferDescPointer()
  {
    return &m_bd;
  }
  ID3D11Buffer * dqTriangleDX::GetVBufferPointer() const
  {
    return m_pVBuffer;
  }
  ID3D11Buffer ** dqTriangleDX::GetVBufferReference()
  {
    return &m_pVBuffer;
  }
  D3D11_MAPPED_SUBRESOURCE * dqTriangleDX::GetMappedSubPointer()
  {
    return &m_ms;
  }
}