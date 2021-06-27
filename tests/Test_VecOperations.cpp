#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "LinAl/LinearAlgebra.hpp"
#include "gtest/gtest.h"

using namespace LinAl;

TEST(Vec_collinear, sameDir)
{
    bool isCollinear = collinear(Z_VEC3D, Z_VEC3D);
    EXPECT_TRUE(isCollinear);
}

TEST(Vec_collinear, oppositeDir)
{
    bool isCollinear = collinear(Z_VEC3D, Vec3d{-1 * Z_VEC3D});
    EXPECT_TRUE(isCollinear);
}

TEST(Vec_collinear, orthogonal)
{
    bool isCollinear = collinear(Z_VEC3D, X_VEC3D);
    EXPECT_FALSE(isCollinear);
}

TEST(Vec_collinear, isNormalized_false)
{
    bool isCollinear =
        collinear(Z_VEC3D, Vec3d{Vec3d{X_VEC3D + Y_VEC3D} + Z_VEC3D});
    EXPECT_FALSE(isCollinear);
}

TEST(Vec_collinear, isNormalized_true)
{
    bool isCollinear = collinear(Z_VEC3D,
                                 Vec3d{Vec3d{X_VEC3D + Y_VEC3D} + Z_VEC3D},
                                 LinAl::isNormalized());
    EXPECT_TRUE(isCollinear);
}
