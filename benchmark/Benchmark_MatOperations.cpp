#include <benchmark/benchmark.h>
#include <linal/Mat.hpp>
#include <linal/MatOperations.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Constants.hpp>

static void BM_transpose_Mat3d(benchmark::State& state)
{
  auto mat = linal::mat3XRot(linal::PI<double> / 180.0 * 90.0);
  for (auto _: state)
  {
    linal::transpose(mat);
    benchmark::DoNotOptimize(mat);
  }
}
BENCHMARK(BM_transpose_Mat3d);

// Run the benchmark
BENCHMARK_MAIN();
