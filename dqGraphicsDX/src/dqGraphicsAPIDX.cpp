#include "dqGraphicsAPIDX.h"

namespace dqEngineSDK
{
  DXGI_FORMAT ColorFormatTraductor(dqColorFormat::E cF)
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
  void dqGraphicsAPIDX::Init(void* hWnd, dqWindowMode::E wndMode, dqColorFormat::E colorFormat)
  {
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
    swapChainDesc.BufferDesc.Width = SCREEN_WIDTH;                 // Screen Width.
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

    //Create Device and SwapChain
    HRESULT hr = D3D11CreateDeviceAndSwapChain(
      nullptr,
      D3D_DRIVER_TYPE_HARDWARE,
      nullptr,
      0,
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
    m_viewport.Init(SCREEN_WIDTH, SCREEN_HEIGHT);
    m_deviceContext.setViewport(1, m_viewport);

    /************************************************************************/
    /* Pipeline Initialization                                              */
    /************************************************************************/
    InitPipeline();

    /************************************************************************/
    /* Triangle                                                             */
    /************************************************************************/
    //m_testTriangle.Init();
    //m_device.createBuffer(m_testTriangle);
    //m_deviceContext.mapGeometry(m_testTriangle);

    m_testTriangleModel.createTriangle( &m_device );

  }
  void dqGraphicsAPIDX::Clean()
  {
    m_swapChain.Clear();
    m_vertexShader.Clear();
    m_pixelShader.Clear();
    m_backBuffer.Clear();
    m_device.clear();
    m_deviceContext.clear();
    m_viewport.Destroy();
  }

  void dqGraphicsAPIDX::AddGeometry()
  {
  }

  void dqGraphicsAPIDX::RenderFrame()
  {
    LinearColor clearColor(0.0f, 0.0f, 1.0f, 1.0f);
    m_deviceContext.clearRenderTargetView(m_backBuffer, clearColor);

    m_testTriangleModel.setBuffers(m_deviceContext);
    //m_deviceContext.setVertexBuffers(1, m_testTriangle, sizeof(dqVertexDX), 0);
    m_deviceContext.setPrimitiveTopology();
    m_deviceContext.draw(3, 0);

    m_swapChain.Present();
  }

  void dqGraphicsAPIDX::InitPipeline()
  {
    //Load and compile the two shaders.
    m_vertexShader.CompileFromFile(L"shaders.shader", "VShader");
    m_pixelShader.CompileFromFile(L"shaders.shader", "PShader");

    //Encapsulate both shaders into shaders object.
    m_device.createVertexShader(m_vertexShader);
    m_device.createPixelShader(m_pixelShader);

    //Set Shader Objects.
    m_deviceContext.vsSetShader(m_vertexShader);
    m_deviceContext.psSetShader(m_pixelShader);

    //InputLayout
    m_device.createInputLayout(m_inputLayout, m_vertexShader);
    m_deviceContext.setInputLayout(m_inputLayout);
  }
}