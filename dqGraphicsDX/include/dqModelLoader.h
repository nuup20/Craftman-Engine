#pragma once
#include "dqGraphicsDXPrerequisites.h"

namespace dqEngineSDK
{
  class dqModelDX;
  class dqDeviceDX;
  class dqInfoCollector;

  class DQ_GRAPHICSDX_EXPORT dqModelLoader
  {
  public:
    dqModelLoader();
    dqModelLoader(dqInfoCollector* pInfoCollector);
    ~dqModelLoader();

    void 
    init();
    void 
    destroy();

    int32
    loadModel(dqDeviceDX& device, 
              dqModelDX& model, 
              String filePath );

    void
    setInfoCollector(dqInfoCollector* pInfoCollector);
  
  private:
    dqInfoCollector * m_pInfoCollector;
  };
}

