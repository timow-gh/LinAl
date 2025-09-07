option(INSTALL_GTEST OFF)
mark_as_advanced(BUILD_GMOCK)
mark_as_advanced(BUILD_TESTING)
mark_as_advanced(INSTALL_GTEST)

CPMAddPackage(
        NAME googletest
        GITHUB_REPOSITORY google/googletest
        GIT_TAG release-1.12.1
        GIT_SHALLOW TRUE
        OPTIONS "INSTALL_GTEST OFF"
)

if (googletest_ADDED)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(gtest_main INTERFACE
                "-Wno-weak-vtables"
        )
    endif ()
endif ()

mark_as_advanced(FETCHCONTENT_BASE_DIR)
mark_as_advanced(FETCHCONTENT_FULLY_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_QUIET)
mark_as_advanced(FETCHCONTENT_SOURCE_DIR_GOOGLETEST)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED)
mark_as_advanced(FETCHCONTENT_UPDATES_DISCONNECTED_GOOGLETEST)

macro(create_linal_test linAlTestName)
    add_executable(${linAlTestName} ${linAlTestName}.cpp)
    target_link_libraries(${linAlTestName} PRIVATE gtest_main linal::linal)
    add_test(NAME ${linAlTestName} COMMAND ${linAlTestName})
endmacro()


create_linal_test(Test_Vec)
create_linal_test(Test_VecCompare)
create_linal_test(Test_VecOperations)
create_linal_test(Test_MatrixOperations)
create_linal_test(Test_HMatrixOperations)
create_linal_test(Test_Radians)
create_linal_test(Test_Quat)

