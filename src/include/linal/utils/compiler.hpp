#ifndef LINAL_COMPILER_HPP
#define LINAL_COMPILER_HPP

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

#if __has_attribute(packed)
#define LINAL_PACKED __attribute__((packed))
#else
#define LINAL_PACKED
#endif

#if __has_builtin(__builtin_expect)
#ifdef __cplusplus
#define LINAL_LIKELY(exp) (__builtin_expect(!!(exp), true))
#define LINAL_UNLIKELY(exp) (__builtin_expect(!!(exp), false))
#else
#define LINAL_LIKELY(exp) (__builtin_expect(!!(exp), 1))
#define LINAL_UNLIKELY(exp) (__builtin_expect(!!(exp), 0))
#endif
#else
#define LINAL_LIKELY(exp) (!!(exp))
#define LINAL_UNLIKELY(exp) (!!(exp))
#endif

#if __has_builtin(__builtin_prefetch)
#define LINAL_PREFETCH(exp) (__builtin_prefetch(exp))
#else
#define LINAL_PREFETCH(exp)
#endif

#if __has_builtin(__builtin_assume)
#define LINAL_ASSUME(exp) (__builtin_assume(exp))
#else
#define UTILS_ASSUME(exp)
#endif

#if __has_attribute(always_inline)
#define LINAL_ALWAYS_INLINE __attribute__((always_inline))
#else
#define LINAL_ALWAYS_INLINE
#endif

#if __has_attribute(noinline)
#define LINAL_NOINLINE __attribute__((noinline))
#else
#define LINAL_NOINLINE
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1900
#define LINAL_RESTRICT __restrict
#elif (defined(__clang__) || defined(__GNUC__))
#define LINAL_RESTRICT __restrict__
#else
#define LINAL_RESTRICT
#endif

#if __has_attribute(pure)
#define LINAL_PURE __attribute__((pure))
#else
#define LINAL_PURE
#endif

#if __has_attribute(const)
#define LINAL_CONST __attribute__((const))
#else
#define LINAL_CONST
#endif

#define LINAL_NODISCARD [[nodiscard]]

#endif // LINAL_COMPILER_HPP
