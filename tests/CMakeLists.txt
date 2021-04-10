cmake_minimum_required(VERSION 3.16)
project(Tests
        LANGUAGES CXX)

option(INSTALL_GTEST OFF)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(testBlaze)
add_subdirectory(testLinearAlgebra)

add_executable(testBasicGTest testbasicgtest.cpp)
target_link_libraries(testBasicGTest PRIVATE gtest_main)
add_test(NAME testBasicGTest COMMAND testBasicGTest)
