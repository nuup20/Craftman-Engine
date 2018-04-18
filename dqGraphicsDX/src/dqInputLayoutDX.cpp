#include "dqGraphicsDXPrerequisites.h"
#include "dqInputLayoutDX.h"

namespace dqEngineSDK
{
  dqInputLayoutDX::dqInputLayoutDX()
  {
  }
  dqInputLayoutDX::~dqInputLayoutDX()
  {
  }
  void dqInputLayoutDX::Init()
  {
  }
  void dqInputLayoutDX::Clear()
  {
  }
  ID3D11InputLayout * dqInputLayoutDX::GetLayoutPointer()
  {
    return m_pLayout;
  }
  ID3D11InputLayout ** dqInputLayoutDX::GetLayoutReference()
  {
    return &m_pLayout;
  }  
}