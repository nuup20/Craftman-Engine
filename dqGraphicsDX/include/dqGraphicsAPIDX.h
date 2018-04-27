#pragma once

#include "dqGraphicsDXPrerequisites.h"

#include "dqDeviceDX.h"
#include "dqDeviceContextDX.h"
#include "dqSwapChainDX.h"
#include "dqRenderTargetDX.h"
#include "dqViewportDX.h"
#include "dqVertexShaderDX.h"
#include "dqPixelShaderDX.h"
#include "dqInputLayoutDX.h"
#include "dqColor.h"
#include "dqModelDX.h"
#include "dqInfoCollector.h"
#include "dqModelLoader.h"

namespace dqEngineSDK
{
  namespace dqColorFormat
  {
    enum E
    {
      k_R8G8B8A8_UNFORM
    };
  }

  namespace dqWindowMode
  {
    enum E
    {
      kWindowed,
      kFullScreen
    };
  }

  class DQ_GRAPHICSDX_EXPORT dqGraphicsAPIDX
  { 
  public:
    dqGraphicsAPIDX();
    ~dqGraphicsAPIDX();

    void 
    Init(void* hWnd, dqWindowMode::E, dqColorFormat::E colorFormat);
    
    void 
    Clean();

    void
    LoadModelFromFile(dqModelDX& model, String filePath);
    
    void 
    addGeometry(dqModelDX & model);
    
    void 
    RenderFrame();

    void
    createAndSetInputLayout(dqVertexShaderDX& vertexShader);

    dqDeviceDX *
    getDevice();

  private:
    dqDeviceDX            m_device;
    dqDeviceContextDX     m_deviceContext;
    dqSwapChainDX         m_swapChain;
    dqRenderTargetDX      m_backBuffer;
    dqViewportDX          m_viewport;    
    dqInputLayoutDX       m_inputLayout;

    LinearColor           m_clearColor;
    Vector < dqModelDX* > m_modelList;

    dqModelLoader         m_modelLoader;
    dqInfoCollector       m_infoCollector;
  };
}

