
#include "gtest/gtest.h"


struct MyStruct
{
	int i_;
	MyStruct() {
		memset(this, 0, sizeof(*this));
	}
};
TEST(StreamTest, OutputObject)
{
	EXPECT_TRUE(true) << true;
	EXPECT_TRUE(false) << true;

	MyStruct ms;
	EXPECT_EQ(ms.i_, 0);
	
	// need implement <<
	// EXPECT_EQ(ms.i_, 100) << ms;

}