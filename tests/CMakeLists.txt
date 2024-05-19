include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)

add_executable(token_test token_test.cc)
target_link_libraries(token_test PRIVATE loxx gtest gmock gtest_main)

add_executable(shape_test shape_test.cc)
target_link_libraries(shape_test PRIVATE shape gtest gmock gtest_main)
