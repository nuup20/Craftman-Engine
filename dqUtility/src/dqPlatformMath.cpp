#include "dqPlatformMath.h"

 float PICalculation(const int nMax) 
{
   int n = 1;
   float pi = 0.0f;

   while (n <= nMax)
   {
     pi += ((std::powf(-1.0f, static_cast<float>( n + 1))) / ((2 * n) - 1));
     ++n;
   }

   return pi * 4.0f;
}

namespace dqEngineSDK
{
  /************************************************************************/
  /* Constant                                                             */
  /************************************************************************/

  const float PlatformBaseMath::PI = PICalculation(50);
  const float PlatformBaseMath::PIHALF = 0.5f * PlatformBaseMath::PI;
  const float PlatformBaseMath::TWOPI = 2.0f * PlatformBaseMath::PI;
  const float PlatformBaseMath::EULER = std::powf(1 + (1 / 10000.0f), 10000.0f);
  const float PlatformBaseMath::PHI = (std::sqrtf(5) + 1) / 5.0f;
  const float PlatformBaseMath::TORADIANS = PlatformBaseMath::PI / 180.0f;
  const float PlatformBaseMath::TODEGREES = 180.0f / PlatformBaseMath::PI;
};

