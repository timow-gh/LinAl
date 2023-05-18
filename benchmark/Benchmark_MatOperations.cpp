#include <benchmark/benchmark.h>
#include <linal/mat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/constants.hpp>
#include <linal/vec3.hpp>

static void BM_transpose_Mat3d(benchmark::State& state)
{
  linal::mat3d mat = linal::rot_x(linal::PI_D / 180.0 * 90.0);
  for (auto _: state)
  {
    linal::transpose(mat);
    benchmark::DoNotOptimize(mat);
  }
}
BENCHMARK(BM_transpose_Mat3d);

// Run the benchmark
BENCHMARK_MAIN();
