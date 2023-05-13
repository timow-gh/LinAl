#include <benchmark/benchmark.h>
#include <linal/Mat.hpp>
#include <linal/MatOperations.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Constants.hpp>

using namespace linal;

static void BM_mat3fXRot_Vec3f(benchmark::State& state)
{
  Vec3f source{1, 0, 0};
  for (auto _: state)
  {
    Vec3f result = mat3XRot(PI<float> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3fXRot_Vec3f);

static void BM_mat3fYRot_Vec3f(benchmark::State& state)
{
  Vec3f source{1, 0, 0};
  for (auto _: state)
  {
    Vec3f result = mat3YRot(PI<float> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3fYRot_Vec3f);

static void BM_mat3fZRot_Vec3f(benchmark::State& state)
{
  Vec3f source{1, 0, 0};
  for (auto _: state)
  {
    Vec3f result = mat3ZRot(PI<float> / 180 * 90) * source;
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
    Vec3f result = rotationAlign(source, target) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_rotationAlign_Vec3f);

static void BM_matAxisAngleRot_Vec3f(benchmark::State& state)
{
  Vec3f source{1, 0, 0};
  Vec3f rotAxis{0, 0, 1};
  constexpr float angle = PI<float> / 180 * 90;
  for (auto _: state)
  {
    Vec3f result = matAxisAngleRot(rotAxis, angle) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot_Vec3f);

// Run the benchmark
BENCHMARK_MAIN();
