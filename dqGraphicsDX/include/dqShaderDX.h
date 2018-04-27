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

    virtual void clear() = 0;

    virtual void  compileFromFile(const WString& file, const String& funcName) = 0;
    ID3D10Blob*   getBlobPointer();
    ID3D10Blob**  getBlobReference();
    void*         getBufferPointer();
    SIZE_T        getBufferSize();

  protected:
    ID3D10Blob* m_blob;
  };
}