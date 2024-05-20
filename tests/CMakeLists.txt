include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)

add_executable(token_test token_test.cc)
target_link_libraries(token_test PRIVATE loxx gtest gmock gtest_main)

add_executable(scanner_test scanner_test.cc)
target_link_libraries(scanner_test PRIVATE loxx gtest gmock gtest_main)

include(GoogleTest)
gtest_discover_tests(token_test)
gtest_discover_tests(scanner_test)
