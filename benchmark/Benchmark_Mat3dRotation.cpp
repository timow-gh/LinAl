#include <benchmark/benchmark.h>
#include <linal/Mat.hpp>
#include <linal/MatRotation.hpp>
#include <linal/Vec3.hpp>
#include <linal/utils/Constants.hpp>

using namespace linal;

static void BM_mat3dXRot_Vec3d(benchmark::State& state)
{
  Vec3d source{1, 0, 0};
  for (auto _: state)
  {
    Vec3d result = linal::mat3XRot(linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3dXRot_Vec3d);

static void BM_mat3dYRot_Vec3d(benchmark::State& state)
{
  Vec3d source{1, 0, 0};
  for (auto _: state)
  {
    Vec3d result = linal::mat3YRot(linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3dYRot_Vec3d);

static void BM_mat3dZRot_Vec3d(benchmark::State& state)
{
  Vec3d source{1, 0, 0};
  for (auto _: state)
  {
    Vec3d result = linal::mat3ZRot(linal::PI<double> / 180 * 90) * source;
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
    Vec3d result = linal::rotationAlign(source, target) * source;
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
    Vec3d result = linal::matAxisAngleRot(rotAxis, linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot_Vec3d);

// Run the benchmark
BENCHMARK_MAIN();
