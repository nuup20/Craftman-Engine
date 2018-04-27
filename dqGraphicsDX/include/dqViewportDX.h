#pragma once

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqViewportDX
  {
  public:
    dqViewportDX();
    ~dqViewportDX();

    void 
    Init(int32 width, int32 heigth);
    
    void 
    Destroy();

    D3D11_VIEWPORT*  
    GetPointer();

  private:
    D3D11_VIEWPORT m_viewport;
  };
}