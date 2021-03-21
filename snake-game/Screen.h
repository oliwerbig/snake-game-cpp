#pragma once
#include <string>
class Board;
class Screen
{
public:
	Screen();

	virtual void render() = 0;
	virtual void writeCharacter(int row, int col, wchar_t character) = 0;
	virtual void writeString(int row, int col, const std::wstring& string) = 0;
	virtual void renderBoard(Board* board) = 0;

	virtual int getHeight() = 0;
	virtual int getWidth() = 0;
};

