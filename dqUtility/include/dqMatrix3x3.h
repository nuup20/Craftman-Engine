#pragma once

#include "dqPlatformTypes.h"
#include "dqVector3.h"

//row major
namespace dqEngineSDK
{
  struct DQ_UTILITY_EXPORT Matrix3x3
  {
    union 
    {
      float m[3][3];
      float m00, m01, m02,
            m10, m11, m12,
            m20, m21, m22;
      Vector3 rowVec[3];
    };
    
    Matrix3x3();
    Matrix3x3(DEF_INIT::E);
    Matrix3x3(const Matrix3x3&);
    ~Matrix3x3();

    Matrix3x3   
      operator+ (const Matrix3x3&) const;
    
    Matrix3x3   
      operator- (const Matrix3x3&) const;
    
    Matrix3x3   
      operator* (const Matrix3x3&) const;
    
    Vector3     
      operator* (const Vector3&) const;
    
    Matrix3x3&  
      operator+= (const Matrix3x3&);
    
    Matrix3x3&  
      operator-= (const Matrix3x3&);
    
    Matrix3x3&  
      operator*= (const Matrix3x3&);
    
    Matrix3x3&  
      operator= (const Matrix3x3&);
    
    Matrix3x3&  
      operator= (const float);

    Matrix3x3   
      Transposed() const; 
    
    Matrix3x3&  
      Transpose();
    
    /**
    * @brief Convierte la matrix original en una matriz identidad.
    */
    Matrix3x3&
      identityMatrix();

    static const int8 RANGE_MATRIX = 3;
  };
}
