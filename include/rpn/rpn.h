#pragma once

#include <optional>
#include <string_view>

namespace rpn {

std::optional<double> calc(std::string_view expr);

}

