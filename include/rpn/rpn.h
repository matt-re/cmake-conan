#pragma once

#include <optional>
#include <span>
#include <string>

std::optional<double> rpn_calc(std::string_view expr);

