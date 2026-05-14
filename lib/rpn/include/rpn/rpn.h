#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace rpn {

[[nodiscard]] std::optional<std::string> calc(std::string_view expr, std::optional<unsigned int> output_digits = std::nullopt);

}  // namespace rpn

