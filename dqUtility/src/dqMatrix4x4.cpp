#include "dqMatrix4x4.h"

namespace dqEngineSDK {

  Matrix4x4::Matrix4x4()
  {
  }

  Matrix4x4::Matrix4x4(DEF_INIT::E)
  {
  }

  Matrix4x4::Matrix4x4(const Matrix4x4 &)
  {
  }

  Matrix4x4::~Matrix4x4()
  {
  }

  Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &) const
  {
    return Matrix4x4();
  }

  Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &) const
  {
    return Matrix4x4();
  }

  Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &) const
  {
    return Matrix4x4();
  }

  Vector4 Matrix4x4::operator*(const Vector4 &) const
  {
    return Vector4();
  }

  Matrix4x4 & Matrix4x4::operator+=(const Matrix4x4 &)
  {
    // TODO: insert return statement here
    return *this;
  }

  Matrix4x4 & Matrix4x4::operator-=(const Matrix4x4 &)
  {
    // TODO: insert return statement here
    return *this;
  }

  Matrix4x4 & Matrix4x4::operator*=(const Matrix4x4 &)
  {
    // TODO: insert return statement here
    return *this;
  }

  Matrix4x4 Matrix4x4::Transposed() const
  {
    return Matrix4x4();
  }

  Matrix4x4 & Matrix4x4::Transpose()
  {
    // TODO: insert return statement here
    return *this;
  }
}
