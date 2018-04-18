#pragma once

#include "dqGraphicsDXPrerequisites.h"

#include "dqDeviceDX.h"
#include "dqDeviceContextDX.h"
#include "dqSwapChainDX.h"
#include "dqRenderTargetDX.h"
#include "dqViewportDX.h"
#include "dqVertexShaderDX.h"
#include "dqPixelShaderDX.h"
#include "dqTriangleDX.h"
#include "dqInputLayoutDX.h"
#include "dqModelDX.h"

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
    AddGeometry();
    
    void 
    RenderFrame();

  private:
    void 
    InitPipeline();

    dqDeviceDX            m_device;
    dqDeviceContextDX     m_deviceContext;
    dqSwapChainDX         m_swapChain;
    dqRenderTargetDX      m_backBuffer;
    dqViewportDX          m_viewport;
    dqVertexShaderDX      m_vertexShader;
    dqPixelShaderDX       m_pixelShader;
    dqInputLayoutDX       m_inputLayout;

    dqTriangleDX          m_testTriangle;
    dqModelDX             m_testTriangleModel;
  };
}

