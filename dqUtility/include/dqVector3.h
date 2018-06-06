#pragma once

#include "dqPlatformTypes.h"

namespace dqEngineSDK
{
  struct Vector2;
  struct Vector4;

  struct DQ_UTILITY_EXPORT Vector3
  {
    float x, y, z;
    
    Vector3();
    Vector3(DEF_INIT::E);
    Vector3(const Vector3&);
    explicit Vector3(const Vector2&);
    explicit Vector3(const Vector4&);
    Vector3(float x, float y, float z);
    ~Vector3();

    Vector3   
    operator+ (const Vector3&) const;
    
    Vector3   
    operator- (const Vector3&) const;
    
    Vector3   
    operator* (const Vector3&) const;
    
    Vector3   
    operator* (const float&) const;
    
    Vector3   
    operator/ (const Vector3&) const;
    
    Vector3   
    operator/ (const float&) const;
    
    Vector3   
    operator^ (const Vector3&) const;
    
    float     
    operator| (const Vector3&) const;
    
    float     
    operator[] (const int32&) const;    
    
    Vector3&  
    operator+= (const Vector3&);
    
    Vector3&  
    operator-= (const Vector3&);
    
    Vector3&  
    operator*= (const Vector3&);
    
    Vector3&  
    operator*= (const float&);
    
    Vector3&  
    operator/= (const Vector3&);    
    
    Vector3&  
    operator/= (const float&);
    
    Vector3&  
    operator^= (const Vector3&);
    
    Vector3&  
    operator= (const Vector3& _vector);
    
    Vector3&  
    operator= (const Vector4& _vector);
    
    Vector3&  
    operator= (const float& number);
    
    Vector3   
    normalized() const;
    
    float     
    magnitude() const;
    
    float     
    halfMagnitude() const;
    
    float     
    radiansBetween(const Vector3&) const;
    
    float     
    degreesBetween(const Vector3&) const;
    
    Vector3&  
    normalize();

    /**
     * Limita la magnitud del vector a un valor máximo. Si la magnitud del 
     *vector sobrepasa la magnitud máxima éste será recortado hasta la 
     *magnitud máxima. El vector no se verá afectado si no es mayor a la 
     *magnitud máxima.
     * @param un flotante que represanta la magnitud máxima del vector.
     * @return una referencia hacia éste vector.
     */
    Vector3&
    truncate(float maxMagnitude);

    Vector3&
    seek(const Vector3& _targetPos, 
          const Vector3& _agentPosition, 
          float _forceMagnitude);

    Vector3&
    flee(const Vector3& _targetPos, 
         const Vector3& _agentPosition, 
         float _forceMagnitude);

    Vector3&
    arrive(const Vector3& _targetPos, 
           const Vector3& _agentPosition, 
           float _areaEffect, 
           float _maxForceMagnitude);

    Vector3&
    obstacleAvoidance(Vector3* _obsPositions,
                      uint32 _obsSize,
                      float _obsRadius,
                      const Vector3& _agentPosition,
                      const Vector3& _agentDirection,
                      float _agentRadius,
                      float _maxForceMagnitude);

    Vector3&
    cohesion(Vector3* _othersPositions,
             uint32 _othersSize,
             float _maxForceMagnitude);

    Vector3&
    separation(Vector3* _othersPositions,
                uint32 _othersSize,
                const Vector3& _agentPosition,
                float _agentPersonalSpace,
                float _maxSeparationMagnitude);

    Vector3&
    alignment(Vector3* _othersDirections,
              uint32 _othersSize,
              const Vector3& _agentDirection,
              float _alignmentForce);
  };
}
