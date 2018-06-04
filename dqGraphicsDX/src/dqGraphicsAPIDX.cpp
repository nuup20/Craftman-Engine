#include "dqGraphicsAPIDX.h"

namespace dqEngineSDK
{
  
  DXGI_FORMAT
  ColorFormatTraductor(dqColorFormat::E cF)
  {
    switch (cF)
    {
    case dqColorFormat::k_R8G8B8A8_UNFORM:
      return DXGI_FORMAT_R8G8B8A8_UNORM;
    default:
      return DXGI_FORMAT_R8G8B8A8_UNORM;
    }
  }

  dqGraphicsAPIDX::dqGraphicsAPIDX()
  {
  }

  dqGraphicsAPIDX::~dqGraphicsAPIDX()
  {
    Clean();
  }
  
  void 
  dqGraphicsAPIDX::Init(void* hWnd, 
                        dqWindowMode::E wndMode, 
                        dqColorFormat::E colorFormat )
  {
    m_infoCollector.init();
    
    //Cast void* to Window Pointer.
    HWND* myWind = static_cast<HWND*>(hWnd);

    // Transform the engine color format to DXGI format.
    DXGI_FORMAT cFormat = ColorFormatTraductor(colorFormat);

    /************************************************************************/
    /* SwapChain, Device and Device Context  Initialization                 */
    /************************************************************************/

    //Create a description for swapChain
    DXGI_SWAP_CHAIN_DESC  swapChainDesc;
    SecureZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

    swapChainDesc.BufferCount = 1;                                  // Number of Back Buffers.
    swapChainDesc.BufferDesc.Format = cFormat;                      // Color Format.
    swapChainDesc.BufferDesc.Width = SCREEN_WIDTH;                  // Screen Width.
    swapChainDesc.BufferDesc.Height = SCREEN_HEIGHT;                // Screen Height.
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;    // How SC is to be used.
    swapChainDesc.OutputWindow = *myWind;                           // The window to be used.
    swapChainDesc.SampleDesc.Count = 1;                             // Number of Multi samples.
    swapChainDesc.SampleDesc.Quality = 0;                           // Multisample quality level.
    swapChainDesc.Windowed = TRUE;                                  // Windowed / Full.

    if (wndMode == dqWindowMode::kFullScreen)
    {
      swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; // Allow Full-Screen Switching.
    }

    DWORD flags = 0;
#if DQ_DEBUG_MODE
    flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    //Create Device and SwapChain
    HRESULT hr = D3D11CreateDeviceAndSwapChain( nullptr,
                                                D3D_DRIVER_TYPE_HARDWARE,
                                                nullptr,
                                                flags,
                                                nullptr,
                                                0,
                                                D3D11_SDK_VERSION,
                                                &swapChainDesc,
                                                m_swapChain.GetReference(),
                                                m_device.getReference(),
                                                nullptr,
                                                m_deviceContext.getReference());

    if (FAILED(hr))
    {
      return;
    }

    /************************************************************************/
    /* BackBuffer Initialization                                            */
    /************************************************************************/
    m_swapChain.GetBuffer(m_backBuffer);
    m_device.createRenderTargetView(m_backBuffer);
    m_deviceContext.setRenderTargets(1, m_backBuffer);

    /************************************************************************/
    /* Viewport Initialization                                              */
    /************************************************************************/

    //Set Viewport
    m_viewport.Init(SCREEN_WIDTH, SCREEN_HEIGHT);
    m_deviceContext.setViewport(1, m_viewport);

    /************************************************************************/
    /* Clear Color                                                          */
    /************************************************************************/
    m_clearColor.r = 0.f;
    m_clearColor.g = 0.f;
    m_clearColor.b = 1.f;
    m_clearColor.a = 1.f;

    /************************************************************************/
    /* Primitive Topology                                                   */
    /************************************************************************/
    m_deviceContext.setPrimitiveTopology( PRIMITIVE_TOPOLOGY::kTriangleList );
  }
  
  void 
  dqGraphicsAPIDX::Clean()
  {
    m_swapChain.Clear();   
    m_backBuffer.clear();
    m_device.clear();
    m_deviceContext.clear();
    m_viewport.Destroy();
  }

  void 
  dqGraphicsAPIDX::LoadModelFromFile(dqModelDX & model, String filePath)
  {
    m_modelLoader.loadModel(m_device, model, filePath);
    return;
  }

  void 
  dqGraphicsAPIDX::addGeometry(dqModelDX & model)
  {
    //TODO llamar cuando se hace el render.
    model.setBuffers(m_deviceContext); 
    m_modelList.push_back(&model);
  }

  void 
  dqGraphicsAPIDX::RenderFrame()
  {
    /************************************************************************/
    /* Clear                                                                */
    /************************************************************************/
    LinearColor color(1, 0, 1, 1);
    m_deviceContext.clearRenderTargetView(m_backBuffer, color);
    
    /************************************************************************/
    /* Draw                                                                 */
    /************************************************************************/
    for (auto model : m_modelList) {
      if (model != nullptr) {
        model->draw(m_deviceContext);
      }
    }

    m_swapChain.Present();
  }

  void dqGraphicsAPIDX::createAndSetInputLayout(dqVertexShaderDX & vertexShader)
  {
    //InputLayout
    m_device.createInputLayout(m_inputLayout, vertexShader);
    m_deviceContext.setInputLayout(m_inputLayout);
  }

  dqDeviceDX* 
  dqGraphicsAPIDX::getDevice()
  {
    return &m_device;
  }
}