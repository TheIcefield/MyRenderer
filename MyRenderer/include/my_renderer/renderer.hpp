#pragma once

#include <expected>
#include <string_view>

namespace my_renderer {

class Renderer {
   public:
    void draw() const;

    static std::expected<Renderer, std::string_view> create(void* proc_addr);
};

}  // namespace my_renderer
