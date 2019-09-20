#include <string>
#include "gmock/gmock.h"

using ::testing::AllOf;
using ::testing::Ge;
using ::testing::Le;
using ::testing::MatchesRegex;
using ::testing::StartsWith;

std::string Foo() {
	return "Hello World";
}
std::string Bar() {
	return "Line 33";
}
int Baz() {
	return 7;
}

TEST(MYTHAT, THATTEST)
{
	EXPECT_THAT(Foo(), StartsWith("Hello"));
	EXPECT_THAT(Bar(), MatchesRegex("Line \\d+"));
	ASSERT_THAT(Baz(), AllOf(Ge(5), Le(10)));
}