#pragma once

struct ID3D11Texture2D;
namespace dqEngineSDK
{
  class DQ_GRAPHICSDX_EXPORT dqTextureDX
  {
  public:
    dqTextureDX();
    dqTextureDX(const dqTextureDX&);
    virtual ~dqTextureDX();

    virtual void 
    init();
    
    virtual void 
    clear();

    ID3D11Texture2D** 
    getReference();
    
    ID3D11Texture2D*  
    getPointer() ;

  protected:
    ID3D11Texture2D* m_texture2D;
  };

}