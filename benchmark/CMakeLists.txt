FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.6.0)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_MakeAvailable(benchmark)

function(create_linal_benchmark benchMarkName)
    add_executable(${benchMarkName} ${benchMarkName}.cpp)
    target_link_libraries(${benchMarkName}
            PRIVATE
            benchmark::benchmark
            benchmark::benchmark_main
            Core::Types
            LinAl::LinAl)
endfunction()

create_linal_benchmark(Benchmark_MatOperations)
create_linal_benchmark(Benchmark_Mat3dRotation)
create_linal_benchmark(Benchmark_Mat3fRotation)

