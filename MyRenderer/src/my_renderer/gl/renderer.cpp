#include <my_renderer/renderer.hpp>

#include "../logger.hpp"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include <expected>

namespace my_renderer {

std::expected<Renderer, std::string_view> Renderer::create(void* proc_addr) {
    if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(proc_addr))) {
        LOG_CRITICAL("gladLoadGL() failed!");
        return std::unexpected("gladLoadGL() failed!");
    }

    LOG_INFO("Renderer initialized. GLADloadfunc: {0}", proc_addr);

    glClearColor(0, 0, 0, 1);

    return Renderer{};
}

void Renderer::draw() const { glClear(GL_COLOR_BUFFER_BIT); }

}  // namespace my_renderer
