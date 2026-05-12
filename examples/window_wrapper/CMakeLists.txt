set(target_name window_wrapper)

add_library(${target_name} STATIC src/window_wrapper/window.cpp)

target_link_libraries(${target_name} PRIVATE glfw)

target_include_directories(${target_name} PUBLIC include)
