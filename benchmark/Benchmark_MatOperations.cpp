#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <Core/Math/Constants.hpp>
#include <LinAl/LinearAlgebra.hpp>
#include <benchmark/benchmark.h>

using namespace LinAl;

static void BM_transpose_Mat3d(benchmark::State& state)
{
    auto mat = LinAl::mat3XRot(Core::PI<double_t>/ 180.0 * 90.0);
    for (auto _: state)
    {
        LinAl::transpose(mat);
        benchmark::DoNotOptimize(mat);
    }
}
BENCHMARK(BM_transpose_Mat3d);

// Run the benchmark
BENCHMARK_MAIN();
#pragma clang diagnostic pop