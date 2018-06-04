#include "dqMatrix3x3.h"

namespace dqEngineSDK
{
  Matrix3x3::Matrix3x3()
  {
    *this = 0.0f;
  }

  Matrix3x3::Matrix3x3(DEF_INIT::E initValue)
  {
    *this = 0.0f;

    if (initValue == DEF_INIT::E::kONE) {
      this->m[0][0] = 1.0f;
      this->m[1][1] = 1.0f;
      this->m[2][2] = 1.0f;      
    }
  }

  Matrix3x3::Matrix3x3(const Matrix3x3 & matrix)
  {
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = matrix.m[row][col];
      }
    }
  }

  Matrix3x3::~Matrix3x3()
  {
  }

  Matrix3x3 
    Matrix3x3::operator+(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[row][col] + matrix.m[row][col];
      }
    }
    return _mat;
  }

  Matrix3x3 
    Matrix3x3::operator-(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[row][col] - matrix.m[row][col];
      }
    }
    return _mat;
  }

  Matrix3x3 
    Matrix3x3::operator*(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    Matrix3x3 matrix_t(matrix.Transposed());
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->rowVec[row] | matrix_t.rowVec[col];
      }
    }
    return _mat;
  }

  Vector3 
    Matrix3x3::operator*(const Vector3 & vec) const
  {
    Vector3 _vector;
    _vector.x = this->rowVec[0] | vec;
    _vector.y = this->rowVec[1] | vec;
    _vector.z = this->rowVec[2] | vec;
    return _vector;
  }

  Matrix3x3 & 
    Matrix3x3::operator+=(const Matrix3x3 & _matrix)
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

  Matrix3x3 & 
    Matrix3x3::operator-=(const Matrix3x3 &)
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

  Matrix3x3 & 
    Matrix3x3::operator*=(const Matrix3x3 & _matrix)
  {
    Matrix3x3 resultMatrix;
    Matrix3x3 matrix_t(_matrix.Transposed());

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

  Matrix3x3 & 
    Matrix3x3::operator=(const Matrix3x3 & _matrix)
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

  Matrix3x3 & 
    Matrix3x3::operator=(const float number)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = number;
      }
    }
    return *this;
  }

  Matrix3x3 
    Matrix3x3::Transposed() const
  {
    Matrix3x3 _mat;
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[col][row];
      }
    }
    return _mat;
  }

  Matrix3x3 & 
    Matrix3x3::Transpose()
  {
    Matrix3x3 _mat(*this);
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] = _mat.m[col][row];
      }
    }
    return *this;
  }

  Matrix3x3 & Matrix3x3::identityMatrix()
  {
    *this = 0.0f;

    this->m[0][0] = 1.0f;
    this->m[1][1] = 1.0f;
    this->m[2][2] = 1.0f;

    return *this;
  }


}