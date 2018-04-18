#pragma once

#include <stdint.h>

#include <string>

#include "dqPlatformDefines.h"

#if DQ_PLATFORM == DQ_PLATFORM_PS4
#include <scebase.h>
#endif

namespace DEF_INIT
{
  enum E {
    kZERO = 0,
    kONE
  };
}

namespace dqEngineSDK {
  /************************************************************************/
  /* Basic unsigned types                                                 */
  /************************************************************************/

  typedef uint8_t   uint8;
  typedef uint16_t  uint16;
  typedef uint32_t  uint32;
  typedef uint64_t  uint64;

  /************************************************************************/
  /* Basic signed types                                                                     */
  /************************************************************************/

  typedef int8_t    int8;
  typedef int16_t   int16;
  typedef int32_t   int32;
  typedef int64_t   int64;

  // Float y Double son Standard

  /************************************************************************/
  /*                                                                     */
  /************************************************************************/

  typedef size_t  SIZE_T;

  MS_ALIGN(16) class QWord
  {
    /**
    * Constructor
    */

  public:
    QWord() : m_lower(0), m_upper(0) {}
            explicit QWord(bool from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(uint8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(int8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(uint16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(int16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(uint32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(int32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(uint64 from) : m_lower(from), m_upper(0) {}
            explicit QWord(int64 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(float from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
            explicit QWord(double from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}

            operator int64() const { return static_cast<uint64>(m_lower); }

  public:
    uint64  m_lower;
    int64   m_upper;
  }GCC_ALIGN(16);

  typedef QWord int128;
  typedef QWord uint128;

  typedef char ANSICHAR;
  typedef wchar_t UNICODECHAR;

  typedef std::basic_string<ANSICHAR, std::char_traits<ANSICHAR>, std::allocator<ANSICHAR>> String;
  typedef std::basic_string<UNICODECHAR, std::char_traits<UNICODECHAR>, std::allocator<UNICODECHAR>> WString;
};
