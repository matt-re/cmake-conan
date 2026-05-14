#include "rpn/rpn.h"

#include <iostream>
#include <optional>
#include <span>
#include <string>

int main(int argc, char **argv)
{
	std::string expr;
	if (argc > 1) {
		for (const char *arg : std::span(argv + 1, static_cast<size_t>(argc) - 1)) {
			if (!expr.empty()) {
				expr += ' ';
			}
			expr += arg;
		}
	} else {
		expr = "99999999999999999999 99999999999999999999 *";
	}

	std::optional<std::string> result = rpn::calc(expr);
	if (result) {
		std::cout << *result << "\n";
		return 0;
	} else {
		std::cerr << "Invalid expression\n";
		return 1;
	}
}

