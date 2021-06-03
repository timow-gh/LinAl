#include "LinAl/BlazeWrapper/BlazeGlMatrixOperations.hpp"

namespace LinAl
{
void setGlMatrixTranslation(GlMatrix& matrix, const GLVecf& translation)
{
    matrix(0, 3) = translation[0];
    matrix(1, 3) = translation[1];
    matrix(2, 3) = translation[2];
}
} // namespace LinAl
