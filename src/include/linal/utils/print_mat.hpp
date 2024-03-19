#ifndef LINAL_PRINT_MAT_HPP
#define LINAL_PRINT_MAT_HPP

#include <ostream>

namespace linal
{

template <typename TMat>
void print_mat(const TMat& mat)
{
  std::ostream& os = std::cout;
  os << std::setprecision(3);
  os << std::fixed;
  os << "Matrix:\n";
  for (int i = 0; i < mat.noOfRows; ++i)
  {
    for (int j = 0; j < mat.noOfCols; ++j)
    {
      os << mat(i, j) << " ";
    }
    os << "\n";
  }
  os << std::endl;
}

} // namespace linal

#endif // LINAL_PRINT_MAT_HPP
