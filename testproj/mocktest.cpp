#include "gtest/gtest.h"
#include "MockTurtle.h"

using ::testing::AtLeast;                     // #1

TEST(PainterTest, CanDrawSomething) {
	MockTurtle turtle;                          // #2
	EXPECT_CALL(turtle, PenDown())              // #3
		.Times(AtLeast(1));

	turtle.PenDown();
	// Painter painter(&turtle);                   // #4

	//EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}