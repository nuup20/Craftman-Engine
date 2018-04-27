#pragma once

#include "dqShaderDX.h"

namespace dqEngineSDK
{
  class dqDeviceDX;
  class dqDeviceContextDX;
  class dqInfoCollector;

  class DQ_GRAPHICSDX_EXPORT dqVertexShaderDX :
    public dqShaderDX
  {
  public:
    dqVertexShaderDX();
    ~dqVertexShaderDX();
    
    void create(WString fileDirectory, 
                String functionName, 
                dqDeviceDX& device);

    void clear();
    void setInfoCollector(dqInfoCollector* pInfoCollector);

    void  compileFromFile(const WString& file, const String& funcName);
   
    ID3D11VertexShader*  getPVS();
    ID3D11VertexShader** getPVSReference();

  private:
    ID3D11VertexShader * m_pVertexShader;
    dqInfoCollector* m_pInfoCollector;
  };
}