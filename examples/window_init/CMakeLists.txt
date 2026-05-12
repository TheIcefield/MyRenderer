set(target_name window_init)

add_executable(${target_name} src/main.cpp)

target_link_libraries(${target_name} window_wrapper my_renderer)
