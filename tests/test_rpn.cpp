#include "rpn/rpn.h"

#include <cassert>
#include <optional>
#include <string>

static void test_large_mul() {
	std::optional<std::string> result = rpn::calc("999999999999999999 2 *");
	assert(result == "1999999999999999998");
}

static void test_large_add() {
	std::optional<std::string> result = rpn::calc("9999999999999999999 1 +");
	assert(result == "10000000000000000000");
}

static void test_precision_div() {
	std::optional<std::string> result = rpn::calc("1 3 /", 20);
	assert(result == "0.33333333333333333333");
}

static void test_large_roundtrip() {
	std::optional<std::string> result = rpn::calc("1000000000000000000 1000000000000000000 * 1000000000000000000 /");
	assert(result == "1000000000000000000");
}

int main() {
	test_large_mul();
	test_large_add();
	test_precision_div();
	test_large_roundtrip();
}
