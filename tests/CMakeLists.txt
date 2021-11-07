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

function(create_linal_test linAlTestName)
    add_executable(${linAlTestName} ${linAlTestName}.cpp)
    target_link_libraries(${linAlTestName} PRIVATE gtest_main LinAl::LinAl)
    add_test(NAME ${linAlTestName} COMMAND ${linAlTestName})
endfunction()

create_linal_test(Test_HMatrixOperations)
create_linal_test(Test_MatrixOperations)
create_linal_test(Test_DotProduct)
create_linal_test(Test_VecOperations)
