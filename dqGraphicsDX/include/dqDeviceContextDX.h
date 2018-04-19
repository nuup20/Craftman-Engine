#pragma once
struct ID3D11DeviceContext;

namespace dqEngineSDK 
{
  class dqVertexShaderDX;
  class dqPixelShaderDX;
  class dqRenderTargetDX;
  class dqInputLayoutDX;
  class dqViewportDX;
  class dqTriangleDX;

  struct LinearColor;

  /**
  * Device Context Class that uses the D3D11 Graphic Library.
  */
  class DQ_GRAPHICSDX_EXPORT dqDeviceContextDX
  {
   public:
    /**
    *  @brief dqDeviceContextDX constructor.
    */
    dqDeviceContextDX();

    /**
    *  @brief Calls "Clear" method from this class.
    */
    ~dqDeviceContextDX();

    /**
    *  @brief Device Context initalization.
    */
    void
    init();

    /**
    *  @brief Calls "Release" method from ID3D11DeviceContext.
    */
    void
    clear();

    /**
    *  @brief Device Context initalization.
    *  @param Number of Render Targets.
    *  @param Reference to a Render Target.
    */
    void
    setRenderTargets(int32 nRenderTargets,
                     dqRenderTargetDX& renderTarget);
    
    /**
    *  @brief Set one or more viewports in the Device Context.
    *  @param Number of Viewports.
    *  @param Reference to a viewport.
    */
    void 
    setViewport(int32 nViewports, dqViewportDX&);

    /**
    *  @brief Set a vertex shader.
    *  @param Vertex Shader reference.
    */
    void 
    vsSetShader(dqVertexShaderDX &);

    /**
    *  @brief Set a pixel shader.
    *  @param Pixel Shader reference.
    */
    void 
    psSetShader(dqPixelShaderDX &);
    
    /**
    *  @brief Map information from CPU to GPU.
    *  @param Geometry reference.
    */
    void 
    mapGeometry(const dqTriangleDX &);
    
    /**
    *  @brief Set input layer in the Device Context.
    *  @param Reference to a Input Layout.
    */
    void 
    setInputLayout(dqInputLayoutDX &);
    
    /**
    *  @brief Set vertexBuffers in the Device Context.
    *  @param number of buffers.
    *  @param geometry.
    *  @param stride.
    *  @param offset.
    */
    void 
    setVertexBuffers(uint32, 
                     ID3D11Buffer **,
                     uint32,
                     uint32);
    
    /*
    *  @brief Set a primitive Topology.
    */
    void 
    setPrimitiveTopology();
    
    /**
     * @brief Draw 
     * @param Vertex Count.
     * @param Start Vertex Location.
     */
    void
    draw(uint32 nVertex, uint32 fVertex);
    
    /**
     * @brief Clear a renderTarger with a color.
     * @param Render target to clear.
     * @param clear color.
     */
    void
    clearRenderTargetView(dqRenderTargetDX& renderTarget,
                          LinearColor & clearColor);

    /**
    *  @brief Returns a reference of D3D11 Interface Device Context.
    */
    ID3D11DeviceContext**
    getReference();

  private:
    ID3D11DeviceContext* m_devCont; /**< ID3D11DeviceContext pointer. */
  };
}