#include "rpn/rpn.h"

#include <cctype>
#include <cstddef>
#include <gmpxx.h>
#include <iomanip>
#include <span>
#include <sstream>
#include <stack>
#include <vector>

namespace rpn {
namespace {

constexpr mp_bitcnt_t kPrecision = 256;

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

std::optional<mpf_class> evaluate(std::span<const std::string_view> tokens)
{
	std::stack<mpf_class> stack;

	for (std::string_view token : tokens) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2) {
				return std::nullopt;
			}

			mpf_class result(kPrecision);

			mpf_class b = stack.top();
			stack.pop();
			mpf_class a = stack.top();
			stack.pop();

			switch (token[0]) {
			case '+':
				result = a + b;
				stack.push(std::move(result));
				break;
			case '-':
				result = a - b;
				stack.push(std::move(result));
				break;
			case '*':
				result = a * b;
				stack.push(std::move(result));
				break;
			case '/':
				if (b == 0) {
					return std::nullopt;
				}
				result = a / b;
				stack.push(std::move(result));
				break;
			}
		} else {
			mpf_class value(kPrecision);
			if (value.set_str(std::string(token), 10) != 0) {
				return std::nullopt;
			}
			stack.push(std::move(value));
		}
	}

	if (stack.size() != 1) {
		return std::nullopt;
	}

	return stack.top();
}

}  // namespace

std::optional<std::string> calc(std::string_view expr, int output_digits)
{
	std::optional<mpf_class> result = evaluate(tokenize(expr));
	if (!result) {
		return std::nullopt;
	}
	std::ostringstream os;
	os << std::setprecision(output_digits) << *result;
	return os.str();
}

}  // namespace rpn

