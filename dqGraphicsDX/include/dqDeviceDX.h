#pragma once
struct ID3D11Device;

namespace dqEngineSDK
{
  class dqVertexShaderDX;
  class dqRenderTargetDX;
  class dqInputLayoutDX;
  class dqPixelShaderDX;
  class dqTriangleDX;

  /**
  * Device Class that uses the D3D11 Graphic Library.
  */
  class DQ_GRAPHICSDX_EXPORT dqDeviceDX
  {
  public:
    
    /**
    * Device Class that uses the D3D11 Graphic Library.
    */
    dqDeviceDX();

    /**
    *  @brief Calls "Clear" method from this class.
    *  Clear method "Release" the Device.
    */
    ~dqDeviceDX();

    /**
    *  @brief Device initalization.
    */
    void 
    init();
    
    /**
    *  @brief Calls "Release" method from ID3D11Device.
    */
    void 
    clear();

    /**
    *  @brief Create a render target COM.
    */
    void    
    createRenderTargetView(dqRenderTargetDX &);
    
    /**
    *  @brief Create a VertexShader COM.
    */
    void    
    createVertexShader(dqVertexShaderDX & );
    
    /**
    *  @brief Create a PixeShader COM.
    */
    void    
    createPixelShader(dqPixelShaderDX &);
    
    /**
    *  @brief Create a Buffer COM.
    */
    HRESULT    
    createBuffer(D3D11_BUFFER_DESC* descriptor,
                 D3D11_SUBRESOURCE_DATA* subresource,
                 ID3D11Buffer** buffer);
    
    /**
    *  @brief Create an Input Layout.
    */
    void    
    createInputLayout(dqInputLayoutDX&, dqVertexShaderDX&);
    
    /**
    *  @brief Returns a reference of D3D11 Interface Device.
    */
    ID3D11Device** 
    getReference();
    
  private:
    ID3D11Device* m_device; /**< ID3D11Device pointer. */
  };
}




