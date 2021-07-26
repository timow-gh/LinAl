#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include "Core/Math/Constants.hpp"
#include "LinAl/LinearAlgebra.hpp"
#include "gtest/gtest.h"

using namespace LinAl;

TEST(HMatrixOperations, createIdentity)
{
    auto result = createIdentityHMatrix<float_t>();
    EXPECT_TRUE(result.isAligned());
    EXPECT_EQ(result.capacity(), 16);
    for (std::size_t i{0}; i < 4; ++i)
    {
        for (std::size_t j{0}; j < 4; ++j)
        {
            if (i == j)
                EXPECT_FLOAT_EQ(result(i, j), 1.0f);
            else
                EXPECT_FLOAT_EQ(result(i, j), 0.0f);
        }
    }
}

TEST(HMatrixOperations, xTranslation)
{
    HMatrix<float_t> result = createTranslation(HVec<float_t>{3, 0, 0});
    HMatrix<float_t> expected{{1, 0, 0, 3},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0},
                              {0, 0, 0, 1}};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, xRotation)
{
    HMatrix<float_t> hMatrix = hMatXRot(Core::PI_HALF);
    HVec<float_t> start{0, 1, 0, 1};
    HVec<float_t> result = hMatrix * start;
    HVec<float_t> expected{0, 0, 1, 1};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, yRotation)
{
    HMatrix<float_t> hMatrix = hMatYRot(Core::PI_HALF);
    HVec<float_t> start{0, 0, 1, 1};
    HVec<float_t> result = hMatrix * start;
    HVec<float_t> expected{1, 0, 0, 1};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, zRotation)
{
    HMatrix<float_t> hMatrix = hMatZRot(Core::PI_HALF);
    HVec<float_t> start{1, 0, 0, 1};
    HVec<float_t> result = hMatrix * start;
    HVec<float_t> expected{0, 1, 0, 1};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, axisRotation_Y)
{
    HMatrix<float_t> hMatrix = hMatAxisAngleRot(Vec3f{0, 1, 0}, Core::PI_HALF);
    HVec<float_t> start{0, 0, 1, 1};
    HVec<float_t> result = hMatrix * start;
    HVec<float_t> expected{1, 0, 0, 1};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, axisRotation)
{
    Vec3d rotAxis = LinAl::cross(Vec3d{1, 0, 0}, Vec3d{0, 1, 1});
    HMatrix<double_t> hMatrix = hMatAxisAngleRot(rotAxis, Core::PI_HALF);
    Vec3d startVec{0, 1, 1};
    startVec = LinAl::normalize(startVec);
    HVec<double_t> start{startVec[0], startVec[1], startVec[2], 1};
    HVec<double_t> result = hMatrix * start;
    HVec<double_t> expected{-1, 0, 0, 1};
    EXPECT_EQ(result, expected);
}

TEST(HMatrixOperations, inverseXTranslation)
{
    HMatrix<float_t> xTranslation = createTranslation(HVec<float_t>{3, 0, 0});
    HMatrix<float_t> invXTranslation = LinAl::inverse(xTranslation);

    HMatrix<float_t> expected{{1, 0, 0, -3},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0},
                              {0, 0, 0, 1}};
    EXPECT_EQ(invXTranslation, expected);
}

#pragma clang diagnostic pop