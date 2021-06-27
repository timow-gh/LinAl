enable_testing()

include(FetchContent)

option(INSTALL_GTEST OFF)
mark_as_advanced(BUILD_GMOCK)
mark_as_advanced(BUILD_TESTING)
mark_as_advanced(INSTALL_GTEST)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

mark_as_advanced(FETCHCONTENT_BASE_DIR)
mark_as_advanced(FETCHCONTENT_FULLY_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_QUIET)
mark_as_advanced(FETCHCONTENT_SOURCE_DIR_GOOGLETEST)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED_GOOGLETEST)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
        core
        GIT_REPOSITORY git@github.com:timow-gh/Core.git
        GIT_TAG main)
set(Core_INSTALL ON)
FetchContent_MakeAvailable(core)

add_executable(Test_HMatrixOperations Test_HMatrixOperations.cpp)
target_link_libraries(Test_HMatrixOperations PRIVATE gtest_main LinAl::LinAl)
add_test(NAME Test_HMatrixOperations COMMAND Test_HMatrixOperations)

add_executable(Test_MatrixOperations Test_HMatrixOperations.cpp)
target_link_libraries(Test_MatrixOperations PRIVATE gtest_main LinAl::LinAl)
add_test(NAME Test_MatrixOperations COMMAND Test_MatrixOperations)

add_executable(Test_DotProduct Test_HMatrixOperations.cpp)
target_link_libraries(Test_DotProduct PRIVATE gtest_main LinAl::LinAl)
add_test(NAME Test_DotProduct COMMAND Test_DotProduct)

add_executable(Test_VecOperations Test_VecOperations.cpp)
target_link_libraries(Test_VecOperations PRIVATE gtest_main LinAl::LinAl)
add_test(NAME Test_VecOperations COMMAND Test_VecOperations)
