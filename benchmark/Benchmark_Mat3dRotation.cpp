#include <benchmark/benchmark.h>
#include <linal/mat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/constants.hpp>
#include <linal/vec3.hpp>

static void BM_mat3dXRot_Vec3d(benchmark::State& state)
{
  linal::vec3d source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3d result = linal::rot_x(linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3dXRot_Vec3d);

static void BM_mat3dYRot_Vec3d(benchmark::State& state)
{
  linal::vec3d source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3d result = linal::rot_y(linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3dYRot_Vec3d);

static void BM_mat3dZRot_Vec3d(benchmark::State& state)
{
  linal::vec3d source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3d result = linal::rot_y(linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3dZRot_Vec3d);

static void BM_rotationAlign_Vec3d(benchmark::State& state)
{
  linal::vec3d source{1, 0, 0};
  linal::vec3d target{0, 1, 0};
  for (auto _: state)
  {
    linal::vec3d result = linal::rot_align(source, target) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_rotationAlign_Vec3d);

static void BM_matAxisAngleRot_Vec3d(benchmark::State& state)
{
  linal::vec3d source{1, 0, 0};
  linal::vec3d rotAxis{0, 0, 1};
  for (auto _: state)
  {
    linal::vec3d result = linal::rot_axis(rotAxis, linal::PI<double> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot_Vec3d);

// Run the benchmark
BENCHMARK_MAIN();
