#include <charconv>
#include <span>
#include <sstream>
#include <stack>
#include <vector>

#include "rpn.h"

namespace rpn {
namespace {

std::vector<std::string> tokenize(std::string_view expr)
{
	std::istringstream iss{std::string(expr)};
	std::vector<std::string> tokens;
	std::string token;
	while (iss >> token) {
		tokens.push_back(token);
	}
	return tokens;
}

std::optional<double> evaluate(std::span<const std::string> tokens)
{
	if (tokens.empty()) {
		return std::optional{ 0.0 };
	}
	
	std::stack<double> stack;

	for (const std::string& token : tokens) {
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

	return std::optional{ stack.top() };
}

}

std::optional<double> calc(std::string_view expr)
{
	return evaluate(tokenize(expr));
}

}

