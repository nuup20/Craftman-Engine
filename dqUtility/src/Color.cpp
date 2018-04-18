#include "dqColor.h"

dqEngineSDK::Color::Color()
{
}

dqEngineSDK::Color::Color(const Color & C)
{
  this->r = C.r; 
  this->g = C.g; 
  this->b = C.b;
  this->a = C.a; 
}

dqEngineSDK::Color::Color(const float & R, const float & G, const float & B, const float & A)
{
  this->r = static_cast<int8>(R); 
  this->g = static_cast<int8>(G);
  this->b = static_cast<int8>(B);
  this->a = static_cast<int8>(A);
}

dqEngineSDK::Color::~Color()
{
}
