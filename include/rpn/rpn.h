#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace rpn {

[[nodiscard]] std::optional<std::string> calc(std::string_view expr, int output_digits = 50);

}  // namespace rpn

