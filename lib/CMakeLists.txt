# Add all the source files
# file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
# ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
# )
# list(REMOVE_ITEM SRC_FILES shape.cc)

# LOXX
add_library(loxx STATIC loxx.cc token.cc tokentype.cc error.cc)
target_include_directories(loxx PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(loxx PRIVATE -Wall -Werror)
