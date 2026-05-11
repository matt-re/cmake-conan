#include <iostream>
#include "rpn.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::optional<double> result = rpn_calc("2 3 + 10 *");
	if (result) {
		std::cout << *result << "\n";
		return 0;
	} else {
		std::cerr << "Invalid expression\n";
		return 1;
	}
}

