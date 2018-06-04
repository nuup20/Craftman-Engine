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
      float mi[16];
      Vector4 rowVec[4];
    };

    Matrix4x4();
    Matrix4x4(DEF_INIT::E); 
    Matrix4x4(const Matrix4x4&);
    ~Matrix4x4();  

    Matrix4x4   
      operator+ (const Matrix4x4& _matrix) const;
    
    Matrix4x4   
      operator- (const Matrix4x4& _matrix) const;
    
    Matrix4x4   
      operator* (const Matrix4x4& _matrix) const;
    
    Vector4     
      operator* (const Vector4& _matrix) const;
    
    Matrix4x4&  
      operator+= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator-= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator*= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator= (const float _number);

    Matrix4x4   
      Transposed() const;
    
    Matrix4x4&  
      Transpose();

    /**
     * @brief Convierte la matrix original en una matriz identidad. 
     */
    Matrix4x4&  
      identityMatrix();

    static Matrix4x4 
      perpectiveFOVLH(float _fov, 
                      float _aspect, 
                      float _near, 
                      float _far);

    static const int8 RANGE_MATRIX = 4;
  };
}
