#pragma once

#include <cstdint>
#include <expected>
#include <string_view>

struct GLFWwindow;

namespace window_wrapper {

class Window {
public:
    Window(std::string_view title, std::uint32_t width, std::uint32_t height);
    ~Window();

    bool should_close() const;

    void swap_buffers() const;

    void poll_events() const;

    static void *get_proc_addr();

private:
    GLFWwindow *m_window;

    std::expected<void, std::string_view> init_glfw() const;

    std::expected<GLFWwindow*, std::string_view> create_window(
        std::string_view title,
        uint32_t const width,
        uint32_t const height) const;

    void terminate_glfw() const;

    static bool is_glfw_inited;
};

} // namespace window_wrapper
