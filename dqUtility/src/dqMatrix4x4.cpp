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

  Matrix4x4 
  Matrix4x4::operator*(const float _escalar) const
  {
    Matrix4x4 retMatrix;

    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        retMatrix.m[row][col] = this->m[row][col] * _escalar;
      }
    }

    return retMatrix;
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
  Matrix4x4::operator*=(const float _escalar)
  {
    for (int8 row = 0; row < RANGE_MATRIX; ++row)
    {
      for (int8 col = 0; col < RANGE_MATRIX; ++col)
      {
        this->m[row][col] *= _escalar;
      }
    }

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

  inline Matrix4x4 &
  Matrix4x4::rotationMatrixOverAxis(Vector3 axis, float radians)
  {
    float axisModule = axis.magnitude();
    float axisModuleSqr = Math::Pow(axisModule, 2.0f);

    float co = Math::Cos(radians);
    float vo = 1.0f - co;

    float xyVo = axis.x * axis.y * vo;
    float xzVo = axis.x * axis.z * vo;
    float yzVo = axis.y * axis.z * vo;

    float soModule = Math::Sin(radians) * axisModule;

    float soModX = soModule * axis.x;
    float soModY = soModule * axis.y;
    float soModZ = soModule * axis.z;

    float modSqrCo = axisModuleSqr * co;

    this->m[0][0] = (Math::Pow(axis.x, 2.0f) * vo) + modSqrCo;
    this->m[1][1] = (Math::Pow(axis.y, 2.0f) * vo) + modSqrCo;
    this->m[2][2] = (Math::Pow(axis.z, 2.0f) * vo) + modSqrCo;
    
    this->m[0][1] = xyVo - soModZ;
    this->m[1][0] = xyVo + soModZ;
    
    this->m[0][2] = xzVo + soModY;
    this->m[2][0] = xzVo - soModY;
    
    this->m[1][2] = yzVo - soModX;
    this->m[2][1] = yzVo + soModX;
    
    this->m[0][3] = 0.0f;
    this->m[1][3] = 0.0f;
    this->m[2][3] = 0.0f;
    this->m[3][0] = 0.0f;
    this->m[3][1] = 0.0f;
    this->m[3][2] = 0.0f;

    *this *= 1.0f / axisModuleSqr;

    this->m[3][3] = 1.0f;

    return *this;

    /*******************************************************************************************/
    /* http://www.wag.caltech.edu/home/ajaramil/libro_robotica/transformaciones_espaciales.pdf */
    /*******************************************************************************************/
  }

  Matrix4x4 
  Matrix4x4::perpectiveFOVLH(float _fovDegAngle, 
                               float _aspect, 
                               float _near, 
                               float _far)
  {
    Matrix4x4 retMatrix;

    float angle = _fovDegAngle * Math::TORADIANS;
    float tanHalfFOV = Math::Tan(angle * 0.5f);
    float nearmfar = _near - _far;


    retMatrix.m[0][0] = 1.0f / (tanHalfFOV * _aspect);
    
    retMatrix.m[1][1] = 1.0f / tanHalfFOV;
    
    retMatrix.m[2][2] = (-_near - _far) / nearmfar;
    retMatrix.m[2][3] = 2.0f * _far * _near / nearmfar;

    retMatrix.m[3][2] = 1.0f;
   
    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::translationMatrix(float x, float y, float z)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    retMatrix.m[0][3] = x;
    retMatrix.m[1][3] = y;
    retMatrix.m[2][3] = z;

    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::translationMatrix(const Vector3& vector)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();
    
    retMatrix.m[0][3] = vector.x;
    retMatrix.m[1][3] = vector.y;
    retMatrix.m[2][3] = vector.z;

    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::scaleMatrix(float x, float y, float z)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    retMatrix.m[0][0] = x;
    retMatrix.m[1][1] = y;
    retMatrix.m[2][2] = z;

    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::scaleMatrix(const Vector3& vector)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    retMatrix.m[0][0] = vector.x;
    retMatrix.m[1][1] = vector.y;
    retMatrix.m[2][2] = vector.z;

    return retMatrix;
  }

  Matrix4x4 
  Matrix4x4::xAxisRotationMatrix(float radians) 
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    float co = Math::Cos(radians);
    float so = Math::Sin(radians);

    retMatrix.m[1][1] = co;
    retMatrix.m[1][2] = so;

    retMatrix.m[2][1] = -so;
    retMatrix.m[2][2] = co;

    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::yAxisRotationMatrix(float radians)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    float co = Math::Cos(radians);
    float so = Math::Sin(radians);

    retMatrix.m[0][0] = co;
    retMatrix.m[0][2] = -so;

    retMatrix.m[2][0] = so;
    retMatrix.m[2][2] = co;

    return retMatrix;
  }

  Matrix4x4
  Matrix4x4::zAxisRotationMatrix(float radians)
  {
    Matrix4x4 retMatrix;
    retMatrix.identityMatrix();

    float co = Math::Cos(radians);
    float so = Math::Sin(radians);

    retMatrix.m[0][0] = co;
    retMatrix.m[0][1] = so;

    retMatrix.m[1][0] = -so;
    retMatrix.m[1][1] = co;

    return retMatrix;
  }

  Matrix4x4&
  Matrix4x4::lookAtLH(Matrix4x4& lookAtMatrix, 
                      const Vector3& up, 
                      const Vector3& forward,
                      const Vector3& right)
  {
    //Set Matrix.
    lookAtMatrix = Matrix4x4(DEF_INIT::kONE);

    lookAtMatrix.mi[0] = right.x;
    lookAtMatrix.mi[4] = right.y;
    lookAtMatrix.mi[8] = right.z;
    
    lookAtMatrix.mi[1] = up.x;
    lookAtMatrix.mi[5] = up.y;
    lookAtMatrix.mi[9] = up.z;
    
    lookAtMatrix.mi[2] = forward.x;
    lookAtMatrix.mi[6] = forward.y;
    lookAtMatrix.mi[10] = forward.z;

    return lookAtMatrix;
  }

  Matrix4x4&
  Matrix4x4::lookAtLH(Matrix4x4& lookAtMatrix,
                      const Vector3& up,
                      const Vector3& forward,
                      const Vector3& right,
                      const Vector3& eye)
  {
    //Set Matrix.
    lookAtMatrix = Matrix4x4(DEF_INIT::kONE);

    lookAtMatrix.mi[0] = right.x;
    lookAtMatrix.mi[4] = right.y;
    lookAtMatrix.mi[8] = right.z;

    lookAtMatrix.mi[1] = up.x;
    lookAtMatrix.mi[5] = up.y;
    lookAtMatrix.mi[9] = up.z;

    lookAtMatrix.mi[2] = forward.x;
    lookAtMatrix.mi[6] = forward.y;
    lookAtMatrix.mi[10] = forward.z;

    lookAtMatrix.mi[12] = (right * -1) | eye;
    lookAtMatrix.mi[13] = (up * -1) | eye;
    lookAtMatrix.mi[14] = (forward * -1) | eye;

    return lookAtMatrix;
  }
}