file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

add_executable(loxx ${SRC_FILES})
target_link_libraries(loxx shape)
target_compile_options(loxx PUBLIC -Wall -Werror)
