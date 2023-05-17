#include <benchmark/benchmark.h>
#include <linal/HMat.hpp>
#include <linal/HMatRotation.hpp>
#include <linal/HVec.hpp>
#include <linal/utils/Constants.hpp>

using namespace linal;

static void BM_hMatdXRot_HVec(benchmark::State& state)
{
  HVecd source{1, 0, 0, 1};
  for (auto _: state)
  {
    HVecd result = hMatXRot(PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_hMatdXRot_HVec);

static void BM_hMatdYRot_HVec(benchmark::State& state)
{
  HVecd source{1, 0, 0, 1};
  for (auto _: state)
  {
    HVecd result = hMatYRot(PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_hMatdYRot_HVec);

static void BM_hMatdZRot_HVec(benchmark::State& state)
{
  HVecd source{1, 0, 0, 1};
  for (auto _: state)
  {
    HVecd result = hMatZRot(PI<double> / 180 * 90) * source;
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
    HVecd result = hMatRotationAlign(source, target) * source;
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
    HVecd result = hMatAxisAngleRot(rotAxis, PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot_HVec);

// Run the benchmark
BENCHMARK_MAIN();
