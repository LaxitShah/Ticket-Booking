#include "pch.h"
#include "BookingLib.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Init, AllAvailable)
{
	BookSeat('A', 7);
	for (int i{ 0 }; i < ROWS; i++)
		for (int j{ 0 }; j < COLS; j++)
			EXPECT_FALSE(IsBook(STARTROW + i, j));
}
TEST(SeatIsBooked, BookA5)
{
	BookSeat('A', 5);
	EXPECT_TRUE(IsBook('A', 5));
}