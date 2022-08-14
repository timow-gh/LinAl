#ifndef LINAL_BLAZEHVEC_HPP
#define LINAL_BLAZEHVEC_HPP

namespace LinAl
{

template <typename T>
class HVec : public blaze::StaticVector<T, 4, blaze::columnVector, blaze::aligned, blaze::padded> {
  public:
    using blaze::StaticVector<T, 4>::StaticVector;
    using value_type = T;
};

using HVecf = HVec<float_t>;
using HVecd = HVec<double_t>;

template <typename T>
class HVecAllocator : public blaze::AlignedAllocator<HVec<T>> {
  public:
    using blaze::AlignedAllocator<Vec<T, 4>>::AlignedAllocator;
};

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

} // namespace LinAl

#endif // LINAL_BLAZEHVEC_HPP
