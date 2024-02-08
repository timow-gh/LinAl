#ifndef LINAL_ASSERT_HPP
#define LINAL_ASSERT_HPP

#include <cstdio>
#include <linal/utils/compiler.hpp>

// Check if we're on windows and have access to __debugbreak().
#if !defined(LINAL_DEBUGBREAK)
#if defined(_WIN32) && defined(__has_include)
#if __has_include(<intrin.h>)
#define LINAL_DEBUGBREAK 1
#endif
#endif
#endif

#if !defined(LINAL_DEBUGBREAK)
#define LINAL_DEBUGBREAK 0
#endif

// Check if we're on a compiler that supports __builtin_trap().
#if !defined(LINAL_BUILTIN_TRAP)
#if defined(__GNUC__) || defined(__clang__)
#define LINAL_BUILTIN_TRAP 1
#else
#define LINAL_BUILTIN_TRAP 0
#endif
#endif

#if !defined(LINAL_BUILTIN_TRAP)
#define LINAL_BUILTIN_TRAP 0
#endif

#if LINAL_DEBUGBREAK
#include <intrin.h> // Provides access to the __debugbreak() function on windows.
#define LINAL_ASSERT_TRAP() ::__debugbreak()
#elif LINAL_BUILTIN_TRAP
#define LINAL_ASSERT_TRAP() __builtin_trap()
#else
#define LINAL_ASSERT_TRAP() ::std::abort()
#endif

namespace linal
{
inline void assertion(const char* fileName, int line, const char* funcName, const char* message)
{
  std::fprintf(stderr, "%s:%d: internal check failed in '%s': '%s'\n", fileName, line, funcName, message);
}
} // namespace linal

#if defined(NDEBUG) && NDEBUG
#define LINAL_ASSERT(...)
#else
#define LINAL_ASSERT(...)                                                                                                                  \
  do                                                                                                                                       \
  {                                                                                                                                        \
    if (LINAL_UNLIKELY(!(__VA_ARGS__)))                                                                                                    \
    {                                                                                                                                      \
      ::linal::assertion(__FILE__, __LINE__, __func__, #__VA_ARGS__);                                                                      \
      LINAL_ASSERT_TRAP();                                                                                                                 \
    }                                                                                                                                      \
  } while (false)
#endif

#endif // LINAL_ASSERT_HPP
