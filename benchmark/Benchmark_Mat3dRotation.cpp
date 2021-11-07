#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <Core/Math/Constants.hpp>
#include <LinAl/LinearAlgebra.hpp>
#include <benchmark/benchmark.h>

using namespace LinAl;

static void BM_mat3dXRot_Vec3d(benchmark::State& state)
{
    Vec3d source{1, 0, 0};
    for (auto _: state)
    {
        Vec3d result = LinAl::mat3XRot(Core::PI / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3dXRot_Vec3d);

static void BM_mat3dYRot_Vec3d(benchmark::State& state)
{
    Vec3d source{1, 0, 0};
    for (auto _: state)
    {
        Vec3d result = LinAl::mat3YRot(Core::PI / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3dYRot_Vec3d);

static void BM_mat3dZRot_Vec3d(benchmark::State& state)
{
    Vec3d source{1, 0, 0};
    for (auto _: state)
    {
        Vec3d result = LinAl::mat3ZRot(Core::PI / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_mat3dZRot_Vec3d);

static void BM_rotationAlign_Vec3d(benchmark::State& state)
{
    Vec3d source{1, 0, 0};
    Vec3d target{0, 1, 0};
    for (auto _: state)
    {
        Vec3d result = LinAl::rotationAlign(source, target) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_rotationAlign_Vec3d);

static void BM_matAxisAngleRot_Vec3d(benchmark::State& state)
{
    Vec3d source{1, 0, 0};
    Vec3d rotAxis{0, 0, 1};
    for (auto _: state)
    {
        Vec3d result = LinAl::matAxisAngleRot(rotAxis, Core::PI / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_matAxisAngleRot_Vec3d);

// Run the benchmark
BENCHMARK_MAIN();
#pragma clang diagnostic pop