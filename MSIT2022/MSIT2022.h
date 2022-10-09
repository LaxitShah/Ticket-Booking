#pragma once
//enum class ERROR {
//	NoErr,
//	NotAvailable,
//	NoErrQuit,
//};
void Initialize(bool  (&seats)[16][20]);

void ShowUI(bool  (&seats)[16][20], char& rowNameStart);

//ERROR TakeInput(char& rowName, char& rowNameStart, int& seatNo);

//ERROR ProcessInput(bool  (&seats)[16][20], char rowName, char rowNameStart, int seatNo);
