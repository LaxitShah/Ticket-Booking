// BookingLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "BookingLib.h"

#pragma region Header
bool seats[ROWS][COLS]; // state of object / program, model
#pragma endregion


ERROR BookSeat(const char& row, const int& seat)
{
	ERROR flag{ ERROR::NoErr };
	if (seats[row - STARTROW][seat - 1] == false)
	{
		seats[row - STARTROW][seat - 1] = true;
	}
	else
	{
		flag = ERROR::NotAvailable;
	}
	return flag;
}
bool IsBook(const char& row, const int& seat)
{
	return seats[row - STARTROW][seat - 1];
}
