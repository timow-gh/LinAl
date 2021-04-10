add_executable(testBasicBlaze testBasicBlaze.cpp)
target_link_libraries(testBasicBlaze PRIVATE gtest_main blaze::blaze)
add_test(NAME testBasicBlaze COMMAND testBasicBlaze)
