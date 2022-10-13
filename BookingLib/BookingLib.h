#pragma once
const int ROWS{ 16 };
const int COLS{ 20 };
const char STARTROW{ 'A' };

enum class ERROR {
	NoErr,
		NotAvailable,
		NoErrQuit,
};
ERROR BookSeat(const char& row, const int& seat);
bool IsBook(const char& row, const int& seat);
