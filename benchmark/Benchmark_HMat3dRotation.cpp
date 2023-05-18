#include <benchmark/benchmark.h>
#include <linal/hmat.hpp>
#include <linal/hmat_rotation.hpp>
#include <linal/hvec.hpp>
#include <linal/utils/constants.hpp>

using namespace linal;

static void BM_hMatdXRot_HVec(benchmark::State& state)
{
  hcoord::hvecd source{1, 0, 0, 1};
  for (auto _: state)
  {
    hcoord::hvecd result = hcoord::rot_x(PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_hMatdXRot_HVec);

static void BM_rotationAlign_HVec(benchmark::State& state)
{
  hcoord::hvecd source{1, 0, 0, 1};
  hcoord::hvecd target{0, 1, 0, 1};
  for (auto _: state)
  {
    hcoord::hvecd result = hcoord::rot_align(source, target) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_rotationAlign_HVec);

static void BM_matAxisAngleRot_HVec(benchmark::State& state)
{
  hcoord::hvecd source{1, 0, 0, 1};
  hcoord::hvecd rotAxis{0, 0, 1, 1};
  for (auto _: state)
  {
    hcoord::hvecd result = hcoord::rot_axis(rotAxis, PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot_HVec);

// Run the benchmark
BENCHMARK_MAIN();
