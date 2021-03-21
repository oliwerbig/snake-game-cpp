#include "WinTerminalScreen.h"
#include "Board.h"
#include "Cell.h"

WinTerminalScreen::WinTerminalScreen()
{
	SetConsoleActiveScreenBuffer(console);
	for (int i = 0; i < height * width; i++)
	{
		screenBuffer[i] = (wchar_t)' ';
	}
}

void WinTerminalScreen::render()
{
	WriteConsoleOutputCharacter(console, screenBuffer, height * width, { 0,0 }, &bytesWritten);
}

void WinTerminalScreen::writeCharacter(int row, int col, wchar_t character)
{
	screenBuffer[row * width + col] = character;
	render();
}

void WinTerminalScreen::writeString(int row, int col, const std::wstring& string)
{
	swprintf(&screenBuffer[row * width + col], string.size() + 1, L"%s", string.c_str());
	render();
}

void WinTerminalScreen::renderBoard(Board* board)
{
	for (int row = 0; row < board->getNumOfRows(); row++) {
		for (int column = 0; column < board->getNumOfColumns(); column++) {
			screenBuffer[row * width + column] = static_cast<wchar_t>(board->getCell(row, column)->getCellType());
		}
	}
	render();
}
