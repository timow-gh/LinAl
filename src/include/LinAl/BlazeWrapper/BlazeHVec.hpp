#ifndef LINAL_BLAZEHVEC_HPP
#define LINAL_BLAZEHVEC_HPP

namespace LinAl
{
// clang-format off
template <typename T>
using HVec = blaze::StaticVector<T,
                                4,
                                blaze::columnVector,
                                blaze::aligned,
                                blaze::padded>;

using HVecf = blaze::StaticVector<float_t,
                                4,
                                blaze::columnVector,
                                blaze::aligned,
                                blaze::padded>;

using HVecd = blaze::StaticVector<double_t,
                                4,
                                blaze::columnVector,
                                blaze::aligned,
                                blaze::padded>;

template <typename T>
using HVecAllocator = blaze::AlignedAllocator<HVec<T>>;
using HVecfAllocator = blaze::AlignedAllocator<HVecf>;
using HVecdAllocator = blaze::AlignedAllocator<HVecd>;

constexpr HVecf ZERO_HVECF = HVecf{0, 0, 0, 1};
constexpr HVecf X_HVECF = HVecf{1, 0, 0, 1};
constexpr HVecf Y_HVECF = HVecf{0, 1, 0, 1};
constexpr HVecf Z_HVECF = HVecf{0, 0, 1, 1};

constexpr HVecd ZERO_HVECD = HVecd{0, 0, 0, 1};
constexpr HVecd X_HVECD = HVecd{1, 0, 0 , 1};
constexpr HVecd Y_HVECD = HVecd{0, 1, 0 , 1};
constexpr HVecd Z_HVECD = HVecd{0, 0, 1 , 1};
// clang-format on

} // namespace LinAl

#endif // LINAL_BLAZEHVEC_HPP
