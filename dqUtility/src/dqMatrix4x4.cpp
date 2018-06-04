#include "dqMatrix4x4.h"

#include "dqPlatformMath.h"

#define Math PlatformBaseMath

namespace dqEngineSDK {
  Matrix4x4::Matrix4x4()
  {
    *this = 0.0f;
  }

  Matrix4x4::Matrix4x4(DEF_INIT::E initValue)
  {
    *this = 0.0f;

    if (initValue == DEF_INIT::E::kONE) {
      this->m[0][0] = 1.0f;
      this->m[1][1] = 1.0f;
      this->m[2][2] = 1.0f;
      this->m[3][3] = 1.0f;
    }
  }

  Matrix4x4::Matrix4x4(const Matrix4x4 & _matrix)
  {
    *this = _matrix;
  }

  Matrix4x4::~Matrix4x4()
  {
  }

  Matrix4x4 
    Matrix4x4::operator+(const Matrix4x4 & matrix) const
  {
    Matrix4x4 resultMat;
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        resultMat.m[row][col] = this->m[row][col] + matrix.m[row][col];
      }
    }
    return resultMat;
  }

  Matrix4x4 
    Matrix4x4::operator-(const Matrix4x4 & matrix) const
  {
    Matrix4x4 resultMat;
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        resultMat.m[row][col] = this->m[row][col] - matrix.m[row][col];
      }
    }
    return resultMat;
  }

  Matrix4x4 
    Matrix4x4::operator*(const Matrix4x4 & matrix) const
  {
    Matrix4x4 resultMatrix;
    Matrix4x4 matrix_t(matrix.Transposed());
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        resultMatrix.m[row][col] = this->rowVec[row] | matrix_t.rowVec[col];
      }
    }

    return resultMatrix;
  }

  Vector4 
    Matrix4x4::operator*(const Vector4 & _vector) const
  {
    Vector4 resutlVector;
    resutlVector.x = this->rowVec[0] | _vector;
    resutlVector.y = this->rowVec[1] | _vector;
    resutlVector.z = this->rowVec[2] | _vector;
    resutlVector.w = this->rowVec[3] | _vector;
    return resutlVector;
  }

  Matrix4x4 & 
    Matrix4x4::operator+=(const Matrix4x4 &)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] += this->m[row][col];
      }
    }
    return *this;
  }

  Matrix4x4 & 
    Matrix4x4::operator-=(const Matrix4x4 &)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] -= this->m[row][col];
      }
    }
    return *this;
  }

  Matrix4x4 & 
    Matrix4x4::operator*=(const Matrix4x4 & _matrix)
  {
    Matrix4x4 resultMatrix;
    Matrix4x4 matrix_t(_matrix.Transposed());

    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        resultMatrix.m[row][col] = this->rowVec[row] | matrix_t.rowVec[col];
      }
    }

    *this = resultMatrix;
    return *this;
  }

  Matrix4x4 & 
    Matrix4x4::operator=(const Matrix4x4 & _matrix)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row) 
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = _matrix.m[row][col];
      }
    }
    return *this;
  }

  Matrix4x4 & 
    Matrix4x4::operator=(const float _number)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = _number;
      }
    }
    return *this;
  }

  Matrix4x4 
    Matrix4x4::Transposed() const
  {
    Matrix4x4 _mat;
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[col][row];
      }
    }
    return _mat;
  }

  Matrix4x4 & 
    Matrix4x4::Transpose()
  {
    Matrix4x4 _mat(*this);
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = _mat.m[col][row];
      }
    }
    return *this;
  }

  Matrix4x4 & 
    Matrix4x4::identityMatrix()
  {
    *this = 0.0f;

    this->m[0][0] = 1.0f;
    this->m[1][1] = 1.0f;
    this->m[2][2] = 1.0f;
    this->m[3][3] = 1.0f;

    return *this;
  }

  Matrix4x4 
    Matrix4x4::perpectiveFOVLH(float _fovDegAngle, 
                               float _aspect, 
                               float _near, 
                               float _far)
  {
    //Matriz Identidad.
    Matrix4x4 retMatrix;

    float angle = _fovDegAngle * Math::TORADIANS;
    float tanHalfFOV = Math::Tan(angle * 0.5f);
    //float xScale = yScale / _aspect;
    float nearmfar = _near - _far;


    retMatrix.m[0][0] = 1.0f / (tanHalfFOV * _aspect);
    
    retMatrix.m[1][1] = 1.0f / tanHalfFOV;
    
    retMatrix.m[2][2] = (-_near - _far) / nearmfar;
    retMatrix.m[2][3] = 2.0f * _far * _near / nearmfar;

    retMatrix.m[3][2] = 1.0f;

    /*
    retMatrix.rowVec[0].x = xScale;
    retMatrix.rowVec[1].y = yScale;
    retMatrix.rowVec[2].z = (_far + _near) / nearmfar;
    retMatrix.rowVec[2].w = -1.0f;
    retMatrix.rowVec[3].z = 2 * _far * _near * nearmfar;
    */

    return retMatrix;
  }
}