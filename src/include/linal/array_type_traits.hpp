#ifndef LINAL_ARRAY_TYPE_TRAITS_HPP
#define LINAL_ARRAY_TYPE_TRAITS_HPP

namespace linal
{

// array_traits is a type traits class for array like classes that implement
// the addition, subtraction, multiplication, and division policies using CRTP.
// It is used to obtain the value_type and size_type from the derived class.
// The derived class is a template class, therefore it is not possible
// to use dependent names.
template <typename value_t, typename size_t, size_t size>
struct array_traits
{
  using value_type = value_t;
  using reference = value_type&;
  using size_type = size_t;
  static const size_type dim = size;
};

} // namespace linal

#endif // LINAL_ARRAY_TYPE_TRAITS_HPP
