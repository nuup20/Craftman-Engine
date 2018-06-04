#pragma once

#define DQ_PLATFORM_WIN32 1
#define DQ_PLATFORM_OSX 2
#define DQ_PLATFORM_LINUX 3
#define DQ_PLATFORM_PS4 4

#define DQ_COMPILER_MSVC 1
#define DQ_COMPILER_GCC 2
#define DQ_COMPILER_INTEL 3
#define DQ_COMPILER_GNUC 4

#define DQ_ARCHITECTURE_x86_64 1
#define DQ_ARCHITECTURE_x86_32 2

#define DQ_ENDIAN_LITTLE 1
#define DQ_ENDIAN_BIG 2

//
#define DQ_ENDIAN_ DQ_ENDIAN_LITTLE;

#if defined(__clang__)

# define DQ_COMPILER DQ_COMPILER_MSVC // CLANG
# define DQ_COMP_VER __clang_version__
# define DQ_THREADLOCAL _thread
# define DQ_STDCALL __attribute__((stdcall))
# define DQ_CDECL __attribute__ ((cdecl))

#elif defined(__GNUC__)

# define DQ_COMPILER DQ_COMPILER_GNUC //GNUC
# define DQ_COMP_VER (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
# define DQ_THREADLOCAL __thread
# define DQ_STDCALL _attribute__((stdcall))
# define DQ_CDECL __attribute__ ((cdecl))

#elif defined (__INTEL_COMPILER)

# define DQ_COMPILER DQ_COMPILER_INTEL // INTEL
# define DQ_COMP_VER __INTEL_COMPILER
# define DQ_STDCALL __stdcall
# define DQ_CDECL __cdecl

// check if we could be building with either with vs
#elif defined(_MSC_VER)

# define DQ_COMPILER DQ_COMPILER_MSVC
# define DQ_COMP_VER _MSC_VER
# define DQ_THREADLOCAL _declspec(thread)
# define DQ_STDCALL __stdcall
# define DQ_CDECL __cdecl
# undef __PRETTY_FUNCTION__
# define __PRETTY_FUNCTION__ __FUNCSIG__ 

#else

# pragma error "No known compiler."

#endif

#if DQ_COMPILER == DQ_COMPILER_MSVC       // if we are on VS6 or Higher.
# if DQ_COMP_VER >= 1200
#   define FORCEINLINE __forceinline
#   ifndef RESTRICT
#     define RESTRICT __restrict
#   endif
# endif
#elif defined(__MINGW32__)                // if we are on a Unix System.
# if !defined (FORCEINLINE)
#   define FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT
#   endif
# endif
#else
# define  FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT __restrict
#   endif
#endif

/************************************************************************/
/* FInds the current platform                                                                     */
/************************************************************************/

#if defined(__WIN32__) || defined(_WIN32)
#define DQ_PLATFORM DQ_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
#define DQ_PLATFORM DQ_PLATFORM_OSX
#elif defined(__ORBIS__)
#define DQ_PLATFORM DQ_PLATFORM_PS4
#else
#define DQ_PLATFORM DQ_PLATFORM_LINUX
#endif

/************************************************************************/
/* Find the architecture type                                           */
/************************************************************************/

#if defined(__x86_64__) || defined(_M_X64)
# define DQ_ARCH_TYPE DQ_ARCHITECTURE_x86_64
#else
# define DQ_ARCH_TYPE DQ_ARCHITECTURE_x86_32
#endif

/************************************************************************/
/* Memory Alignment macros                                              */
/************************************************************************/

#if DQ_COMPILER == DQ_COMPILER_MSVC
# define MS_ALIGN(n)  __declspec(align(n))
# ifdef GCC_PACK
#   define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN
#   define GCC_ALIGN(n)
# endif
#elif ( DQ_COMPILER == DQ_COMPILER_GNUC && DQ_PLATFORM == DQ_PLATFORM_PS4 )
# define MS_ALIGN(n)
# define GCC_PACK(n)
# define GCC_ALIGN(n) __attribute__((__aligned__(n)))
#else
# define MS_ALIGN(n)  
# define GCC_PACK(n)   __attribute__((packed, aligned(n)))
# define GCC_ALIIGN(n) __attribute__((aligned(n)))
#endif

/************************************************************************/
/* for throw override                                                   */
/************************************************************************/

#if DQ_COMPILER == DQ_COMPILER_MSVC
# define _NOEXCEPT noexcept
#elif DQ_COMPILER == DQ_COMPILER_INTEL
# define _NOEXCEPT noexcept
#elif DQ_COMPILER == DQ_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif

/************************************************************************/
/* Library especific                                                    */
/************************************************************************/

#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#   if defined(DQ_STATIC_LIB)
#     define DQ_UTILITY_EXPORT
#   else
#     if defined( DQ_UTILITY_EXPORTS )
#       define DQ_UTILITY_EXPORT  __declspec( dllexport )
#     else
#       define DQ_UTILITY_EXPORT  __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( DQ_STATIC_LIB )
#     define DQ_UTILITY_EXPORT
#   else
#     if defined( DQ_UTILITY_EXPORTS)
#       defined DQ_UTILITY_EXPORT __attribute__((dllexport))
#     else
#       define DQ_UTILITY_EXPORT  __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define DQ_UTILITY_HIDDEN
#else // Linux / Mac settings
# define DQ_UTILITY_EXPORT __attribute__ ((visibility("default")))
# define DQ_UTILITY_EXPORT __attribute__ ((visibility("hidden")))
#endif

//DLL export for plugins
#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if DQ_COMPILER == DQ_COMPILER_MSVC
#  define DQ_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define DQ_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
# define DQ_UTILITY_HIDDEN
#else // Linux / Mac settings
# define DQ_PLUGIN_EXPORT __attribute__ ((visibility("defualt")))
#endif

/************************************************************************/
/* Windows specific settings                                            */
/************************************************************************/

//win32 compilers use _DEBUG for specifying debug builds. For MinGW, we set DEBUG
#if DQ_PLATFORM == DQ_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
#   define DQ_DEBUG_MODE 1
# else
#   define DQ_DEBUG_MODE 0
# endif
# if DQ_COMPILER == DQ_COMPILER_INTEL
#   define DQ_THREADLOCAL __declspec(thread)
# endif
#endif

/************************************************************************/
/* Linux / Apple specific Settings                                      */
/************************************************************************/
#if DQ_PLATFORM == DQ_PLATFORM_LINUX || DQ_PLATFORM == DQ_PLATFORM_OSX
# define stripcmp strcasecmp

//If we are one DEBUG build
#if defined(_DEBUG) || defined(DEBUG)
#   define DQ_DEBUG_MODE 1
# else
#   define DQ_DEBUG_MODE 0
# endif
# if DQ_COMPILER == DQ_COMPILER_INTEL 
#   define DQ_THREADLOCAL __thread
# endif
#endif

#if DQ_PLATFORM == DQ_PLATFORM_PS4
# if defined(_DEBUG) || defined(DEBUG)
#   define DQ_DEBUG_MODE 1
# else
#   define DQ_DEBUG_MODE 0
# endif
#endif

/************************************************************************/
/* Definition of Debug macros                                           */
/************************************************************************/

#if DQ_DEBUG_MODE
# define DQ_DEBUG_ONLY(x) x
# define DQ_ASSERT(x) assert(x)
#else
# define DQ_DEBUG_ONLY(x)
# define DQ_ASSERT(x)
#endif

#if DQ_COMPILER == DQ_COMPILER_MSVC
# define _CRT_SECURE_NO_WARNINGS
# pragma warning(disable : 4251)
#endif
