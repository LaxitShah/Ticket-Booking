// MSIT2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MSIT2022.h"
#include "BookingLib.h"
using namespace std;

#pragma region TickeBooking
ERROR TakeInput(char& rowName, char& rowNameStart, int& seatNo);

void ShowUI()
{
	for (int i{0}; i < ROWS; i++)
	{
		for (int j{0}; j<COLS;j++)
			cout << (IsBook(STARTROW+i, j) ? 'X' : '*') << ' ';
		cout << " --> " << STARTROW+i << endl;
	}
	cout << endl;
	cout << "   vvvvvvvvvv   --- Screen this way" << endl;
	cout << "* --> Available" << endl;
	cout << "X --> Already booked" << endl;

	cout << "Book: ";
}

void BookTicketsV3()
{
	for (;;)
	{
		ShowUI();
		char inRow{ '\0' };
		int inSeatNo{ 0 };
		char st{ 'A' };
		auto ret = TakeInput(inRow, st, inSeatNo);
		if (ret == ERROR::NoErrQuit)
			break;
		if (IsBook(inRow, inSeatNo))
		{
			cout << "Not Available!" << endl;
			cin.get();
			cin.get();
		}
		else
		{
			BookSeat(inRow, inSeatNo);
		}
	}
}


#pragma region TicketBooking V2

void Initialize(bool (& seats)[16][20])
{
	for (auto& row : seats)
		for (auto& theSeat : row)
			theSeat = false;
}
void ShowUI(bool(&seats)[16][20], char& rowNameStart)
{
	for (const auto& row : seats)
	{
		for (const auto& theSeat : row)
			cout << (theSeat == true ? 'X' : '*') << ' ';
		cout << " --> " << rowNameStart++ << endl;
	}
	cout << endl;
	cout << "   vvvvvvvvvv   --- Screen this way" << endl;
	cout << "* --> Available" << endl;
	cout << "X --> Already booked" << endl;

	cout << "Book: ";
}

ERROR TakeInput(char& rowName, char& rowNameStart, int& seatNo)
{
	cin >> rowName;

	rowNameStart = 'A';
	if (rowName == 'q' || rowName == 'Q')
	{
		return ERROR::NoErrQuit;
	};
	cin >> seatNo;

	return ERROR::NoErr;
}
ERROR ProcessInput(bool  (&seats)[16][20], char rowName, char rowNameStart, int seatNo)
{
	ERROR flag{ ERROR::NoErr};
	if (seats[rowName - rowNameStart][seatNo - 1] == false)
	{
		seats[rowName - rowNameStart][seatNo - 1] = true;
	}
	else
	{
		flag = ERROR::NotAvailable;
	}
	return flag;
}
void BookTicketsV2()
{
	bool seats[16][20]; // state of object / program, model

	Initialize(seats);

	char rowNameStart{ 'A' };

	for (;;)
	{
		ShowUI(seats, rowNameStart);
		// A4
		char rowName{ '\0' };
		int seatNo{ 0 };

		auto retflag = TakeInput(rowName, rowNameStart, seatNo);

		if (retflag == ERROR::NoErrQuit) break;

		if (ProcessInput(seats, rowName, rowNameStart, seatNo) == ERROR::NotAvailable)
		{
			cout << "Not Available!";
			cin.get();
			cin.get();
		}

		system("cls");
	}

}
#pragma endregion

void BookTicketsV1()
{
	bool seats[16][20]; // state of object / program, model

	char rowNameStart{ 'A' };
	for (auto& row : seats)
		for (auto& theSeat : row)
			theSeat = false;

	for (;;)
	{
		for (const auto& row : seats)
		{
			for (const auto& theSeat : row)
				cout << (theSeat == true ? '0' : '*') << ' ';
			cout << " --> " << rowNameStart++ << endl;
		}
		cout << endl;
		cout << "   vvvvvvvvvv   --- Screen this way" << endl;
		cout << "* --> Available" << endl;
		cout << "X --> Already booked" << endl;

		cout << "Book: ";
		// A4
		char rowName{ '\0' };
		int seatNo{ 0 };
		cin >> rowName;
		rowNameStart = 'A';
		if (rowName == 'q' || rowName == 'Q')
			break;
		cin >> seatNo;

		if (seats[rowName - rowNameStart][seatNo - 1] == false)
		{
			seats[rowName - rowNameStart][seatNo - 1] = true;
		}
		else
		{
			cout << "Not Available!" << endl;
		}

		system("cls");
	}
}

#pragma endregion

#pragma region Exercises
int sum(int a, int b)
{
	return a + b;
}
void ex1()
{
	auto j{ 23L };

	byte a{ 10 };

	int size = sizeof(j);

	const int s{ 120 };
	unsigned int ages[s]{ 0 };

	if (j == 24)
	{
		std::cout << j;
	}
	auto k{ 30LL };
	size = sizeof(k);
}

#pragma endregion

int main()
{
	BookTicketsV3();
}

