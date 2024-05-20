cmake_minimum_required(VERSION 3.28.0)
project(
    loxx
    VERSION 0.1.0
    DESCRIPTION "This is your project. Change on your own."
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 23)

# Build output paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
add_subdirectory(src)
add_subdirectory(lib)

include(CTest)
enable_testing()
add_subdirectory(tests)
