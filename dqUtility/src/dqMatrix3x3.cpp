#include "dqMatrix3x3.h"

namespace dqEngineSDK
{
  Matrix3x3::Matrix3x3()
  {
  }
  Matrix3x3::Matrix3x3(DEF_INIT::E)
  {
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
  Matrix3x3 Matrix3x3::operator+(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[row][col] + matrix.m[row][col];
      }
    }
    return _mat;
  }
  Matrix3x3 Matrix3x3::operator-(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->m[row][col] - matrix.m[row][col];
      }
    }
    return _mat;
  }
  Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & matrix) const
  {
    Matrix3x3 _mat;
    Matrix3x3 matrix_t(matrix.Transposed());
    for (int32 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int32 col = 0; col < RANGE_MATRIX; ++col)
      {
        _mat.m[row][col] = this->rowVec[row] | matrix_t.rowVec[col];
      }
    }

    return _mat;
  }
  Vector3 Matrix3x3::operator*(const Vector3 & vec) const
  {
    Vector3 _vector;
    _vector.x = this->rowVec[0] | vec;
    _vector.y = this->rowVec[1] | vec;
    _vector.z = this->rowVec[2] | vec;
    return _vector;
  }
  Matrix3x3 & Matrix3x3::operator+=(const Matrix3x3 &)
  {
    // TODO: insert return statement here
    return *this;
  }
  Matrix3x3 & Matrix3x3::operator-=(const Matrix3x3 &)
  {
    // TODO: insert return statement here
    return *this;
  }
  Matrix3x3 & Matrix3x3::operator*=(const Matrix3x3 &)
  {
    // TODO: insert return statement here
    return *this;
  }
  Matrix3x3 Matrix3x3::Transposed() const
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
  Matrix3x3 & Matrix3x3::Transpose()
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
}