#include <cstdlib>
#include <iostream>
#include <my_renderer/renderer.hpp>
#include <window_wrapper/window.hpp>

using namespace window_wrapper;
using namespace my_renderer;

int main() {
    Window window{"WindowInit", 640, 480};

    auto res = Renderer::create(Window::get_proc_addr());
    if (!res.has_value()) {
        std::cerr << res.error() << std::endl;
        return EXIT_FAILURE;
    }

    Renderer renderer = std::move(res.value());

    while (!window.should_close()) {
        renderer.draw();

        window.swap_buffers();
        window.poll_events();
    }

    return 0;
}
