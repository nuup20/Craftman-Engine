/********************************************************************
	created:	
	created:	
	filename: 	file Name here
	author:		Max Maldonado
	
	purpose:	
*********************************************************************/
                                                                                              
#pragma once

#include "dqPlatformDefines.h"

#if DQ_PLATFORM == DQ_PLATFORM_WIN32
  #include "dqWindowsMath.h"
  typedef  dqEngineSDK::WindowsMath Math;
  
#else //DQ_PLATFORM == DQ_PLATFORM_WIN32
  #include "dqPlatformMath.h"
  typedef dqEngineSDK::PlatformBaseMath Math;
#endif
