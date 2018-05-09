#pragma once

/************************************************************************/
/* Include Types                                                        */
/************************************************************************/
#include <dqPlatformTypes.h>
#include <dqSTDHeaders.h>

/************************************************************************/
/* General Defines                                                      */
/************************************************************************/


/************************************************************************/
/* Library especific                                                    */
/************************************************************************/

#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#   if defined(DQ_STATIC_LIB)
#     define DQ_CORE_EXPORT
#   else
#     if defined( DQ_CORE_EXPORTS )
#       define DQ_CORE_EXPORT  __declspec( dllexport )
#     else
#       define DQ_CORE_EXPORT  __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( DQ_STATIC_LIB )
#     define DQ_CORE_EXPORT
#   else
#     if defined( DQ_CORE_EXPORTS)
#       defined DQ_CORE_EXPORT __attribute__((dllexport))
#     else
#       define DQ_CORE_EXPORT  __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define DQ_CORE_HIDDEN
#else // Linux / Mac settings
# define DQ_CORE_EXPORT __attribute__ ((visibility("default")))
# define DQ_CORE_EXPORT __attribute__ ((visibility("hidden")))
#endif

//DLL export for plugins
#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#  define DQ_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define DQ_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
# define DQ_CORE_HIDDEN
#else // Linux / Mac settings
# define DQ_PLUGIN_EXPORT __attribute__ ((visibility("defualt")))
#endif