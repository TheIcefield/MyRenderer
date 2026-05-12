set(target_name my_renderer)

add_library(${target_name} STATIC
  src/my_renderer/gl/renderer.cpp)

target_include_directories(${target_name} PUBLIC include)

target_link_libraries(${target_name} glad spdlog)
