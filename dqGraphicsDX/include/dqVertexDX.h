#pragma once

#include "dqGraphicsDXPrerequisites.h"
#include <dqColor.h>

namespace dqEngineSDK
{
  struct DQ_GRAPHICSDX_EXPORT dqVertexDX
  {
    float         x, y, z;
    float         nx, ny, nz;
    LinearColor   color;
  }; 
}