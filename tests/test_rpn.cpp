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

static void test_invalid_token() {
	std::optional<std::string> result = rpn::calc("foo 1 +");
	assert(!result);
}

static void test_division_by_zero() {
	std::optional<std::string> result = rpn::calc("5 0 /");
	assert(!result);
}

static void test_too_few_operands() {
	std::optional<std::string> result = rpn::calc("1 +");
	assert(!result);
}

static void test_extra_values() {
	std::optional<std::string> result = rpn::calc("1 2");
	assert(!result);
}

static void test_empty() {
	std::optional<std::string> result = rpn::calc("");
	assert(!result);
}

int main() {
	test_large_mul();
	test_large_add();
	test_precision_div();
	test_large_roundtrip();
	test_invalid_token();
	test_division_by_zero();
	test_too_few_operands();
	test_extra_values();
	test_empty();
}
