#include "rpn.h"

#include <cctype>
#include <charconv>
#include <cstddef>
#include <span>
#include <stack>
#include <vector>

namespace rpn {
namespace {

std::vector<std::string_view> tokenize(std::string_view expr)
{
	std::vector<std::string_view> tokens;
	std::size_t i = 0;
	while (i < expr.size()) {
		while (i < expr.size() && std::isspace(static_cast<unsigned char>(expr[i]))) {
			i++;
		}
		if (i >= expr.size()) {
			break;
		}
		const std::size_t start = i;
		while (i < expr.size() && !std::isspace(static_cast<unsigned char>(expr[i]))) {
			i++;
		}
		tokens.emplace_back(expr.data() + start, i - start);
	}
	return tokens;
}

std::optional<double> evaluate(std::span<const std::string_view> tokens)
{
	std::stack<double> stack;

	for (std::string_view token : tokens) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2) {
				return std::nullopt;
			}

			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();

			switch (token[0]) {
			case '+':
				stack.push(a + b);
				break;
			case '-':
				stack.push(a - b);
				break;
			case '*':
				stack.push(a * b);
				break;
			case '/':
				if (b == 0.0) {
					return std::nullopt;
				}
				stack.push(a / b);
				break;
			}
		} else {
			double value;
			const char* end = token.data() + token.size();
			auto [ptr, ec] = std::from_chars(token.data(), end, value);
			if (ec != std::errc() || ptr != end) {
				return std::nullopt;
			}
			stack.push(value);
		}
	}

	if (stack.size() != 1) {
		return std::nullopt;
	}

	return stack.top();
}

}  // namespace

std::optional<double> calc(std::string_view expr)
{
	return evaluate(tokenize(expr));
}

}  // namespace rpn

