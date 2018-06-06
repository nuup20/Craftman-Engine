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

    Matrix4x4
      operator* (const float _escalar) const;
    
    Vector4     
      operator* (const Vector4& _matrix) const;
    
    Matrix4x4&  
      operator+= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator-= (const Matrix4x4& _matrix);
    
    Matrix4x4&  
      operator*= (const Matrix4x4& _matrix);

    Matrix4x4&
      operator*= (const float _escalar);
    
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
    
    inline Matrix4x4&
    rotationMatrixOverAxis(Vector3 axis, float angle);

    static Matrix4x4 
      perpectiveFOVLH(float _fov, 
                      float _aspect, 
                      float _near, 
                      float _far);

    static Matrix4x4
    translationMatrix(float x, float y, float z);

    static Matrix4x4
    translationMatrix(const Vector3& vector);

    static Matrix4x4
    scaleMatrix(float x, float y, float z);

    static Matrix4x4
    scaleMatrix(const Vector3& vector);
    
    static Matrix4x4 
    xAxisRotationMatrix(float radians);

    static Matrix4x4
    yAxisRotationMatrix(float radians);

    static Matrix4x4
    zAxisRotationMatrix(float radians);

    static Matrix4x4&
    lookAtLH(Matrix4x4& lookAtMatrix, 
             const Vector3& up,
             const Vector3& forward,
             const Vector3& right);

    static Matrix4x4&
    lookAtLH(Matrix4x4& lookAtMatrix,
             const Vector3& up,
             const Vector3& forward,
             const Vector3& right,
             const Vector3& eye);

      
      


    static const int8 RANGE_MATRIX = 4;
  };
}
