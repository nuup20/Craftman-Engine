#pragma once
#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT LinearColor
  {
    LinearColor() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}
    LinearColor(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}

    float r, g, b, a;
  };

  struct DQ_UTILITY_EXPORT Color
  {
    union 
    {
      uint8   r, g, b, a;
      uint32  fullColor;
    };

    Color();
    Color(const Color&);
    Color(const float& r, const float& g, const float& b, const float& a);
    ~Color();

  };
}