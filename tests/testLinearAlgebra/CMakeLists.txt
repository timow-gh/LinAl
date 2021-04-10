project(Test_LinearAlgebra)

set(TEST_LINAL_SOURCES
    testmatrixoperations.cpp
    Test_DotProduct.cpp)

set(LINK_LIBS
    gtest_main
    LinAl::LinAl)

add_executable(test_linearalgebra ${TEST_LINAL_SOURCES})
target_link_libraries(test_linearalgebra
                      PRIVATE
                      ${LINK_LIBS}
                      )
add_test(NAME test_linearalgebra COMMAND test_linearalgebra)
