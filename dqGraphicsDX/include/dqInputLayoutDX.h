#pragma once

namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqInputLayoutDX
  {
  public:
    dqInputLayoutDX();
    ~dqInputLayoutDX();

    void 
    Init();
    
    void 
    Clear();

    ID3D11InputLayout*   
    GetLayoutPointer();
    
    ID3D11InputLayout**  
    GetLayoutReference();

    D3D11_INPUT_ELEMENT_DESC ied[2] = 
    {
      { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
      { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

  private:
    ID3D11InputLayout* m_pLayout;
  };
}

