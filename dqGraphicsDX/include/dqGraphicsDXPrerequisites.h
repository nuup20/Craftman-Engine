#pragma once

/************************************************************************/
/* Include the Direct3D headers                                         */
/* d3d11 contiene piezas clave de Direct3D. d3dx11 posee funciones que  */
/* serviran a la hora de crear juegos. Como Direct11 es una extensión de*/
/* Direct10, muchas macros son compartidas con d3dx10.h.                */
/************************************************************************/
#include <d3d11.h>
#include <cassert>

/************************************************************************/
/* Include Types                                                        */
/************************************************************************/
#include <dqPlatformTypes.h>
#include <dqSTDHeaders.h>

#include "dqGraphicsCommons.h"

/************************************************************************/
/* General Defines                                                      */
/************************************************************************/
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

/************************************************************************/
/* Library especific                                                    */
/************************************************************************/

#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#   if defined(DQ_STATIC_LIB)
#     define DQ_GRAPHICSDX_EXPORT
#   else
#     if defined( DQ_GRAPHICSDX_EXPORTS )
#       define DQ_GRAPHICSDX_EXPORT  __declspec( dllexport )
#     else
#       define DQ_GRAPHICSDX_EXPORT  __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( DQ_STATIC_LIB )
#     define DQ_GRAPHICSDX_EXPORT
#   else
#     if defined( DQ_GRAPHICSDX_EXPORTS)
#       defined DQ_GRAPHICSDX_EXPORT __attribute__((dllexport))
#     else
#       define DQ_GRAPHICSDX_EXPORT  __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define DQ_GRAPHICSDX_HIDDEN
#else // Linux / Mac settings
# define DQ_GRAPHICSDX_EXPORT __attribute__ ((visibility("default")))
# define DQ_GRAPHICSDX_EXPORT __attribute__ ((visibility("hidden")))
#endif

//DLL export for plugins
#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#  define DQ_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define DQ_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
# define DQ_GRAPHICSDX_HIDDEN
#else // Linux / Mac settings
# define DQ_PLUGIN_EXPORT __attribute__ ((visibility("defualt")))
#endif