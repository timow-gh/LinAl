#ifndef LINAL_HVEC_HPP
#define LINAL_HVEC_HPP

#include <linal/utils/Warnings.hpp>
DISABLE_ALL_WARNINGS
#include <blaze/math/StaticVector.h>
#include <blaze/util/AlignedAllocator.h>
ENABLE_ALL_WARNINGS

namespace linal
{

template <typename T>
using HVec = blaze::StaticVector<T, 4, blaze::columnVector, blaze::aligned, blaze::unpadded>;

using HVecf = HVec<float_t>;
using HVecd = HVec<double_t>;

template <typename T>
using HVecAllocator = blaze::AlignedAllocator<HVec<T>>;

using HVecAllocatorf = HVecAllocator<float_t>;
using HVecAllocatord = HVecAllocator<double_t>;

constexpr HVecf ZERO_HVECF = HVecf{0, 0, 0, 1};
constexpr HVecf X_HVECF = HVecf{1, 0, 0, 1};
constexpr HVecf Y_HVECF = HVecf{0, 1, 0, 1};
constexpr HVecf Z_HVECF = HVecf{0, 0, 1, 1};

constexpr HVecd ZERO_HVECD = HVecd{0, 0, 0, 1};
constexpr HVecd X_HVECD = HVecd{1, 0, 0, 1};
constexpr HVecd Y_HVECD = HVecd{0, 1, 0, 1};
constexpr HVecd Z_HVECD = HVecd{0, 0, 1, 1};

} // namespace linal

#endif // LINAL_HVEC_HPP
