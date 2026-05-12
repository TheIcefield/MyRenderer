#include <stdexcept>
#include <string_view>
#include <window_wrapper/window.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

using namespace window_wrapper;

bool Window::is_glfw_inited = false;

Window::Window(std::string_view title, std::uint32_t const width,
               std::uint32_t const height) {
    {
        auto const res = this->init_glfw();
        if (!res.has_value()) {
            std::string const error{res.error()};
            throw std::runtime_error(error);
        }
    }

    {
        auto const res = this->create_window(title, width, height);
        if (!res.has_value()) {
            std::string const error{res.error()};
            throw std::runtime_error(error);
        }

        this->m_window = res.value();
    }
}

Window::~Window() {
    glfwDestroyWindow(this->m_window);
    this->terminate_glfw();
}

bool Window::should_close() const {
    return glfwWindowShouldClose(this->m_window);
}

void Window::swap_buffers() const { glfwSwapBuffers(this->m_window); }

void Window::poll_events() const { glfwPollEvents(); }

void* Window::get_proc_addr() {
    return reinterpret_cast<void*>(glfwGetProcAddress);
}

std::expected<void, std::string_view> Window::init_glfw() const {
    if (this->is_glfw_inited) {
        return {};
    }

    if (!glfwInit()) {
        return std::unexpected("glfwInit() failed");
    }

    this->is_glfw_inited = true;
    return {};
}

std::expected<GLFWwindow*, std::string_view> Window::create_window(
    std::string_view title, uint32_t const width, uint32_t const height) const {
    auto const window =
        glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!window) {
        return std::unexpected("glfwCreateWindow() failed");
    }

    glfwMakeContextCurrent(window);
    return window;
}

void Window::terminate_glfw() const { glfwTerminate(); }
