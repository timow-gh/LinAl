#include <benchmark/benchmark.h>
#include <linal/mat.hpp>
#include <linal/mat_rot.hpp>
#include <linal/utils/constants.hpp>
#include <linal/vec3.hpp>

using namespace linal;

static void BM_mat3fXRot(benchmark::State& state)
{
  linal::vec3f source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3f result = linal::rot_x(PI<float> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3fXRot);

static void BM_mat3fYRot(benchmark::State& state)
{
  linal::vec3f source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3f result = linal::rot_y(PI<float> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3fYRot);

static void BM_mat3fZRot(benchmark::State& state)
{
  linal::vec3f source{1, 0, 0};
  for (auto _: state)
  {
    linal::vec3f result = linal::rot_z(PI<float> / 180 * 90) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_mat3fZRot);

static void BM_rotationAlign(benchmark::State& state)
{
  linal::vec3f source{1, 0, 0};
  linal::vec3f target{0, 1, 0};
  for (auto _: state)
  {
    linal::vec3f result = linal::rot_align(source, target) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_rotationAlign);

static void BM_matAxisAngleRot(benchmark::State& state)
{
  linal::vec3f source{1, 0, 0};
  linal::vec3f rotAxis{0, 0, 1};
  constexpr float angle = PI<float> / 180 * 90;
  for (auto _: state)
  {
    linal::vec3f result = linal::rot_axis(rotAxis, angle) * source;
    benchmark::DoNotOptimize(result);
  }
}
BENCHMARK(BM_matAxisAngleRot);

// Run the benchmark
BENCHMARK_MAIN();
