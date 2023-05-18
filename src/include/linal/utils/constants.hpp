#ifndef LINAL_CONSTANTS_H
#define LINAL_CONSTANTS_H

namespace linal
{

inline constexpr double PI_D = 3.1415926535897932384626433832795028841971693993751058209749445923;
inline constexpr double PI_HALF_D = 1.5707963267948966192313216916397514420985846996875529104874722961;
inline constexpr double PI_2_D = 6.2831853071795864769252867665590057683943387987502116419498891846;

template <typename T>
inline constexpr T PI = static_cast<T>(PI_D);

template <typename T>
inline constexpr T PI_HALF = static_cast<T>(PI_HALF_D);

template <typename T>
inline constexpr T PI_2 = static_cast<T>(PI_2_D);

} // namespace linal

#endif // LINAL_CONSTANTS_H
