#pragma once

#include <dqPlatformTypes.h>
#include <d3d11.h>

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqShaderDX
  {
  public:
    dqShaderDX();
    virtual ~dqShaderDX();

    virtual void Clear() = 0;

    virtual void  CompileFromFile(const WString& file, const String& funcName) = 0;
    ID3D10Blob *  GetBlobPointer();
    ID3D10Blob ** GetBlobReference();
    void*         GetBufferPointer();
    SIZE_T        GetBufferSize();

  protected:
    ID3D10Blob * m_blob;
  };
}