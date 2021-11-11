FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.6.0)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_EXCEPTIONS OFF CACHE BOOL "" FORCE)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(BENCHMARK_USE_LIBCXX ON CACHE BOOL "" FORCE)
else ()
    set(BENCHMARK_USE_LIBCXX OFF CACHE BOOL "" FORCE)
endif ()
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

create_linal_benchmark(Benchmark_HMat3dRotation)
create_linal_benchmark(Benchmark_Mat3dRotation)
create_linal_benchmark(Benchmark_Mat3fRotation)
create_linal_benchmark(Benchmark_MatOperations)
