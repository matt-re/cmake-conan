#pragma once

#include <optional>
#include <string_view>

namespace rpn {

[[nodiscard]] std::optional<double> calc(std::string_view expr);

}  // namespace rpn

