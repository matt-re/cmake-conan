#include "rpn/rpn.h"

#include <cstddef>
#include <gmpxx.h>
#include <iomanip>
#include <locale>
#include <span>
#include <sstream>
#include <stack>
#include <vector>

namespace rpn {

constexpr unsigned int kDefaultOutputDigits = 77;

namespace {

constexpr mp_bitcnt_t kPrecision = 256;

std::vector<std::string_view> tokenize(std::string_view expr)
{
	const std::locale& loc = std::locale::classic();

	std::vector<std::string_view> tokens;
	std::size_t i = 0;
	while (i < expr.size()) {
		while (i < expr.size() && std::isspace(expr[i], loc)) {
			i++;
		}
		if (i >= expr.size()) {
			break;
		}
		const std::size_t start = i;
		while (i < expr.size() && !std::isspace(expr[i], loc)) {
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

			mpf_class b = stack.top();
			stack.pop();
			mpf_class a = stack.top();
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
				if (b == 0) {
					return std::nullopt;
				}
				stack.push(a / b);
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

std::optional<std::string> calc(std::string_view expr, std::optional<unsigned int> output_digits)
{
	std::optional<mpf_class> result = evaluate(tokenize(expr));
	if (!result) {
		return std::nullopt;
	}
	std::ostringstream os;
	os << std::setprecision(output_digits.value_or(kDefaultOutputDigits)) << *result;
	return os.str();
}

}  // namespace rpn

