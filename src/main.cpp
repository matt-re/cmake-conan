#include <iostream>
#include <string>
#include "rpn.h"

int main(int argc, char **argv)
{
	std::string expr;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (i > 1) {
				expr += ' ';
			}
			expr += argv[i];
		}
	} else {
		expr = "2 3 + 10 *";
	}

	std::optional<double> result = rpn::calc(expr);
	if (result) {
		std::cout << *result << "\n";
		return 0;
	} else {
		std::cerr << "Invalid expression\n";
		return 1;
	}
}

