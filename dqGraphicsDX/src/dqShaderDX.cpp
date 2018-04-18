#include "dqGraphicsDXPrerequisites.h"
#include "dqShaderDX.h"

#include <d3dcompiler.h>

namespace dqEngineSDK
{
  dqShaderDX::dqShaderDX()
  {
  }
  dqShaderDX::~dqShaderDX()
  {
  }

  ID3D10Blob * dqShaderDX::GetBlobPointer()
  {
    return m_blob;
  }
  ID3D10Blob ** dqShaderDX::GetBlobReference()
  {
    return &m_blob;
  }
  void* dqShaderDX::GetBufferPointer()
  {
    return m_blob->GetBufferPointer();
  }
  SIZE_T dqShaderDX::GetBufferSize()
  {
    return m_blob->GetBufferSize();
  }
}
