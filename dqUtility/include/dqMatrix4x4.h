#pragma once

#include "dqPlatformTypes.h"
#include "dqVector3.h"
#include "dqVector4.h"

namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Matrix4x4
  {
    union
    {
      float m[4][4];
      float m00, m01, m02, m03,
            m10, m11, m12, m13,
            m20, m21, m22, m23,
            m30, m31, m32, m33;
      Vector3 rowVec[4];
    };

    Matrix4x4();
    Matrix4x4(DEF_INIT::E); 
    Matrix4x4(const Matrix4x4&);
    ~Matrix4x4();  

    Matrix4x4   operator+ (const Matrix4x4&) const;
    Matrix4x4   operator- (const Matrix4x4&) const;
    Matrix4x4   operator* (const Matrix4x4&) const;
    Vector4     operator* (const Vector4&) const;
    Matrix4x4&  operator+= (const Matrix4x4&);
    Matrix4x4&  operator-= (const Matrix4x4&);
    Matrix4x4&  operator*= (const Matrix4x4&);

    Matrix4x4   Transposed() const;
    Matrix4x4&  Transpose();

    static const int8 RANGE_MATRIX = 4;
  };
}
