#pragma once
#include "Screen.h"
#include <Windows.h>
class WinTerminalScreen :
    public Screen
{
protected:
	int height = 30;
	int width = 120;
private:
	wchar_t* screenBuffer = new wchar_t[height * width];
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	DWORD bytesWritten = 0;
public:
	WinTerminalScreen();

	void render();
	void writeCharacter(int row, int col, wchar_t character);
	void writeString(int row, int col, const std::wstring& string);
	void renderBoard(Board* board);

	int getHeight() { return height;  }
	int getWidth() { return width; }
};

