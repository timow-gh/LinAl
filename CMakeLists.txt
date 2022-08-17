cmake_minimum_required(VERSION 3.19)

include(FetchContent)
FetchContent_Declare(twCMakeUtils
        GIT_REPOSITORY https://github.com/timow-gh/twCMakeUtils.git
        GIT_TAG main)
FetchContent_GetProperties(twCMakeUtils)
set(lcs_twCMakeUtils "")
string(TOLOWER "twCMakeUtils" lcs_twCMakeUtils)
if (NOT ${lcs_twCMakeUtils}_POPULATED)
    FetchContent_Populate(twCMakeUtils)
    list(APPEND CMAKE_MODULE_PATH ${${lcs_twCMakeUtils}_SOURCE_DIR}/modules)
    include(CMakeHelperFunctions)
endif ()

project("LinAl"
        VERSION 0.1.0
        LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(LinAl_BUILD_TESTS "LinAl: Enable tests" ON)
    option(LinAl_BUILD_BENCHMARKS "LinAl: Enable benchmarks" ON)
else ()
    option(LinAl_BUILD_TESTS "LinAl: Enable tests" OFF)
    option(LinAl_BUILD_BENCHMARKS "LinAl: Enable benchmarks" OFF)
endif ()

preamble()

add_subdirectory(dependencies)
add_subdirectory(src)

if (LinAl_BUILD_BENCHMARKS)
    add_subdirectory(benchmark)
endif ()

if (LinAl_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()
