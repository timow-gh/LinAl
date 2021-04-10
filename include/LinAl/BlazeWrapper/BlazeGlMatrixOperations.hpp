#ifndef GLFWTESTAPP_BLAZEGLMATRIXOPERATIONS_HPP
#define GLFWTESTAPP_BLAZEGLMATRIXOPERATIONS_HPP

#include "BlazeGlMatrix.hpp"
#include "BlazeGlVector.hpp"
#include "linal_export.h"

namespace LinAl {
void LINAL_EXPORT setGlMatrixTranslation(GlMatrix &matrix,
                                         const LinAl::GLVecf &translation);
}

#endif // GLFWTESTAPP_BLAZEGLMATRIXOPERATIONS_HPP
