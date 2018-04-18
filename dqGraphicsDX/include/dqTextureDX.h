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

    virtual void Init();
    virtual void Clear();

    ID3D11Texture2D ** GetReference();
    ID3D11Texture2D *  GetPointer() ;

  protected:
    ID3D11Texture2D * m_texture2D;
  };

}