add_executable(loxxc main.cc)
target_link_libraries(loxxc PRIVATE loxx)
target_compile_options(loxxc PUBLIC -Wall -Werror)
