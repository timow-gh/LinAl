#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <Core/Math/Constants.hpp>
#include <LinAl/LinearAlgebraUtil.hpp>
#include <gtest/gtest.h>

TEST(LinAl_Utils, dToF)
{
    LinAl::Vec3f res = LinAl::dToF(LinAl::Vec3d{1, 2, 3});
}

TEST(LinAl_Utils, fToD)
{
    LinAl::Vec3f res = LinAl::fToD(LinAl::Vec3f{1.0f, 2.0f, 3.0f});
}