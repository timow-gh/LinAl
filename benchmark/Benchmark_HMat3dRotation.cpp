#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wredundant-decls"

#include <Core/Math/Constants.hpp>
#include <LinAl/LinearAlgebra.hpp>
#include <benchmark/benchmark.h>

using namespace LinAl;

static void BM_hMatdXRot_HVec(benchmark::State& state)
{
    HVecd source{1, 0, 0, 1};
    for (auto _: state)
    {
        HVecd result = LinAl::hMatXRot(Core::PI<double_t>/ 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_hMatdXRot_HVec);

static void BM_hMatdYRot_HVec(benchmark::State& state)
{
    HVecd source{1, 0, 0, 1};
    for (auto _: state)
    {
        HVecd result = LinAl::hMatYRot(Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_hMatdYRot_HVec);

static void BM_hMatdZRot_HVec(benchmark::State& state)
{
    HVecd source{1, 0, 0, 1};
    for (auto _: state)
    {
        HVecd result = LinAl::hMatZRot(Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_hMatdZRot_HVec);

static void BM_rotationAlign_HVec(benchmark::State& state)
{
    HVecd source{1, 0, 0, 1};
    HVecd target{0, 1, 0, 1};
    for (auto _: state)
    {
        HVecd result = LinAl::rotationAlign(source, target) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_rotationAlign_HVec);

static void BM_matAxisAngleRot_HVec(benchmark::State& state)
{
    HVecd source{1, 0, 0, 1};
    HVecd rotAxis{0, 0, 1, 1};
    for (auto _: state)
    {
        HVecd result =
            LinAl::hMatAxisAngleRot(rotAxis, Core::PI<double_t> / 180 * 90) * source;
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_matAxisAngleRot_HVec);

// Run the benchmark
BENCHMARK_MAIN();

#pragma GCC diagnostic pop
