#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <Core/Math/Constants.hpp>
#include <LinAl/LinearAlgebra.hpp>
#include <benchmark/benchmark.h>

using namespace LinAl;

static void BM_mat3fXRot_Vec3f(benchmark::State& state)
{
    Vec3f source{1, 0, 0};
    for (auto _: state)
    {
        Vec3f result = LinAl::mat3XRot(Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3fXRot_Vec3f);

static void BM_mat3fYRot_Vec3f(benchmark::State& state)
{
    Vec3f source{1, 0, 0};
    for (auto _: state)
    {
        Vec3f result = LinAl::mat3YRot(Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3fYRot_Vec3f);

static void BM_mat3fZRot_Vec3f(benchmark::State& state)
{
    Vec3f source{1, 0, 0};
    for (auto _: state)
    {
        Vec3f result = LinAl::mat3ZRot(Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3fZRot_Vec3f);

static void BM_rotationAlign_Vec3f(benchmark::State& state)
{
    Vec3f source{1, 0, 0};
    Vec3f target{0, 1, 0};
    for (auto _: state)
    {
        Vec3f result = LinAl::rotationAlign(source, target) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_rotationAlign_Vec3f);

static void BM_matAxisAngleRot_Vec3f(benchmark::State& state)
{
    Vec3f source{1, 0, 0};
    Vec3f rotAxis{0, 0, 1};
    constexpr auto angle = static_cast<float_t>(Core::PI<double_t> / 180 * 90);
    for (auto _: state)
    {
        Vec3f result = LinAl::matAxisAngleRot(rotAxis, angle) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_matAxisAngleRot_Vec3f);

// Run the benchmark
BENCHMARK_MAIN();
#pragma clang diagnostic pop