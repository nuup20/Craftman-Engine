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

  ID3D10Blob* 
  dqShaderDX::getBlobPointer()
  {
    return m_blob;
  }

  ID3D10Blob** 
  dqShaderDX::getBlobReference()
  {
    return &m_blob;
  }

  void* 
  dqShaderDX::getBufferPointer()
  {
    return m_blob->GetBufferPointer();
  }

  SIZE_T 
  dqShaderDX::getBufferSize()
  {
    return m_blob->GetBufferSize();
  }
}
