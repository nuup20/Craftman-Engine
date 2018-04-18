#pragma once
#include <cmath>

#include "dqPlatformTypes.h"

namespace dqEngineSDK {
  struct DQ_UTILITY_EXPORT PlatformBaseMath
  {
    /************************************************************************/
    /* Constant                                                             */
    /************************************************************************/

    static const float PI;
    static const float PIHALF;
    static const float TWOPI;
    static const float EULER;
    static const float PHI;
    static const float TORADIANS;
    static const float TODEGREES;

    /************************************************************************/
    /* Basic Functions                                                      */
    /************************************************************************/

    static int
      Factorial(const int Param) {
      if (Param < 0) { return 0; }
      return ((Param == 1 || Param == 0) ? 1 : Factorial(Param - 1) * Param);
    }

    template <typename T>
    static T
    Abs(const T Param) {
      return std::abs(Param);
    }

    /************************************************************************/
    /* Exponential Function                                                 */
    /************************************************************************/

    template<typename T>
    static T
      Exp(T Param) {
      return std::exp(Param);
    }

    static float
      FastExp(float Param) {
      float result = 0.0f;
      for (int n = 0; n < 45; ++n)
      {
        result += (std::pow(Param, n)) / Factorial(n);
      }
      return result;
    }
    /************************************************************************/
    /* Trigonometric Functions                                              */
    /************************************************************************/

    template<typename T>
    static T
      Loge(const T Param) {
      return static_cast<T>(std::log(Param));
    }

    template<>
    static float
      Loge(const float Param) {
      return std::logf(Param);
    }

    template<typename T>
    static T
      Log(const T Base, const T Param) {
      return static_cast<T>(Loge(Param) / Loge(Base));
    }

    template<typename T>
    static T
      Sin(const T Angle) {
      return static_cast<T>(std::sin(Angle));
    }

    template<>
    static float
      Sin(const float Angle) {
      return std::sinf(Angle);
    }

    template<typename T>
    static T
      Asin(const T Param) {
      return std::asin(Param);
    }

    template<>
    static float
      Asin(const float Param) {
      return std::asinf(Param);
    }

    template<typename T>
    static T
      Cos(const T Param) {
      return std::cos(Param);
    }

    template<>
    static float
      Cos(const float Param) {
      return std::cosf(Param);
    }

    template<typename T>
    static T
      Acos(const T Param) {
      return std::acos(Param);
    }

    template<>
    static float
      Acos(const float Param) {
      return std::acosf(Param);
    }

    template<typename T>
    static T
      Tan(const T Param) {
      return std::tan(Param);
    }

    template<>
    static float
      Tan(const float Param) {
      return std::tanf(Param);
    }

    template<typename T>
    static T
      Atan(const T Param) {
      return std::atan(Param);
    }

    template<>
    static float
      Atan(const float Param) {
      return std::atanf(Param);
    }

    template<typename T>
    static T
      Atan2(const T Param) {
      return std::atan2(Param);
    }

    static float
      Atan2(const float X, const float Y) {
      return std::atan2f(X,Y);
    }

    /************************************************************************/
    /* Trigonometric Functions (Taylor Series)                              */
    /************************************************************************/

    template<typename T>
    static T
      FastCos(const T Param) {
      T result{};
      for (int n = 0; n < 45; ++n)
      {
        result += std::pow(-1, n) * (std::pow(Param, 2 * n) / Factorial(2 * n));
      }
      return result;
    }

    template<typename T>
    static T
      FastSin(const T Param) {
      T result{};
      for (int n = 0; n < 45; ++n)
      {
        result += std::pow(-1, n) * (std::pow(Param, (2 * n) + 1) / Factorial((2 * n) + 1));
      }
    }

    static float
    FastAtan(const float Param) {
      if (Param < -1.0f || 1.0f < Param)
      {
        return 0.0f;
      }

      float result = 0.f;
      for (int n = 0; n < 45; ++n)
      {
        result += Pow(-1, n) * ((Pow(Param, static_cast<float>((2 * n) + 1) / (2 * n) + 1)));
      }

      return result;
    }

    /************************************************************************/
    /* Power Functions                                                      */
    /************************************************************************/

    template<typename T>
    static float
      Sqrt(const T Param) {
      return static_cast<float>(std::sqrt(Param));
    }

    template<>
    static float
      Sqrt(const float Param) {
      return std::sqrtf(Param);
    }

    template<typename T>
    static float
      InvSqrt(const T Param) {
      return 1.0f / std::sqrt(Param);
    }

    template<>
    static float
      InvSqrt(const float Param) {
      return 1.0f / std::sqrtf(Param);
    }

    template<typename T>
    static T
      Pow(const T Base, const T Exp) {
      return static_cast<T>(std::pow(Base, Exp));
    }

    template<>
    static float
      Pow(const float Base, const float Exp) {
      return std::powf(Base, Exp);
    }

    template<typename T>
    static T
      Cbrt(const T Param) {
      return std::cbrt(Param);
    }

    template<>
    static float
      Cbrt(const float Param) {
      return std::cbrtf(Param);
    }

    /************************************************************************/
    /* Gamma Functions                                                      */
    /************************************************************************/

    template<typename T>
    static T
      Tgamma(const T Param) {
      return std::tgamma(Param);
    }

    template<>
    static float
      Tgamma(const float Param) {
      return std::tgammaf(Param);
    }

    /************************************************************************/
    /* Nearest integer floating point operations                            */
    /************************************************************************/

    template<typename T>
    static T
      Trunc(const T Param) {
      return std::trunc(Param);
    }

    template<>
    static float
      Trunc(const float Param) {
      return std::truncf(Param);
    }

    template<typename T>
    static T
      Ceil(const T Param) {
      return std::ceil(Param);
    }

    template<>
    static float
      Ceil(const float Param) {
      return std::ceilf(Param);
    }

    template<typename T>
    static T
      Floor(const T Param) {
      return std::floor(Param);
    }

    template<>
    static float
      Floor(const float Param) {
      return std::floorf(Param);
    }

    template<typename T>
    static T
      Round(const T Param) {
      return std::round(Param);
    }

    template<>
    static float
      Round(const float Param) {
      return std::roundf(Param);
    }
  };
}
