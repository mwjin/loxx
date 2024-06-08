include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(googletest)

# Create an interface library to hold the gtest dependencies
add_library(gtest_bundle INTERFACE)
target_link_libraries(gtest_bundle INTERFACE gtest gmock gtest_main)

# Create the test executables and link against the interface library
add_executable(token_test token_test.cc)
target_link_libraries(token_test PRIVATE loxx gtest_bundle)

add_executable(scanner_test scanner_test.cc)
target_link_libraries(scanner_test PRIVATE loxx gtest_bundle)

include(GoogleTest)
gtest_discover_tests(token_test)
gtest_discover_tests(scanner_test)
