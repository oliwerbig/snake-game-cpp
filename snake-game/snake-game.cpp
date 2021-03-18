// snake-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Cell.h"
#include "Snake.h"
#include "Board.h"
#include "Game.h"
#include "CellType.h"
#include "Direction.h"

#include <iostream>
#include <list>
#include <thread>
#include <Windows.h>

using namespace std;

int screenWidth = 120;
int screenHeight = 30;

void write(wchar_t* buffer, int row, int col, wchar_t ch);
void write(wchar_t* buffer, int row, int col, const std::wstring& s);
Direction checkForNewDirection();

int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[screenWidth * screenHeight];
	for (int i = 0; i < screenWidth * screenHeight; i++)
	{
		screen[i] = (wchar_t)'.';
	}
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(console);
	DWORD bytesWritten = 0;

	while (1)
	{
		Cell initialSnakeHeadCell(15, 60, CellType::SNAKE_HEAD);
		Snake snake(&initialSnakeHeadCell);
		Board board(screenHeight, screenWidth);
		Game game(&snake, &board);
		game.setGameOver(false);
		game.setDirection(Direction::RIGHT);

		while (!game.isGameOver())
		{
			Direction newDirection = checkForNewDirection();
			if (newDirection != game.getDirection())
			{
				game.setDirection(newDirection);
			}

			game.update();
			for (int row = 0; row < board.getNumOfRows(); row++) {
				for (int column = 0; column < board.getNumOfColumns(); column++) {
					write(screen, row, column, static_cast<wchar_t>(game.getBoard()->getCell(row, column)->getCellType()));
				}
			}

			if (game.isGameOver())
			{
				wsprintf(&screen[15 * screenWidth + 40], L"    PRESS 'SPACE' TO PLAY AGAIN    ");
			}

			// Display Frame
			WriteConsoleOutputCharacter(console, screen, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
		}

		// Wait for space
		while ((GetAsyncKeyState(VK_SPACE) & 0x0001) == 0);
	}
	return 0;
}

void write(wchar_t* buffer, int row, int col, wchar_t ch)
{
	buffer[row * screenWidth + col] = ch;
}

void write(wchar_t* buffer, int row, int col, const std::wstring& s)
{
	swprintf(&buffer[row * screenWidth + col], s.size() + 1, L"%s", s.c_str());
}

Direction checkForNewDirection()
{
	bool upKey = (GetAsyncKeyState(VK_UP) & 0x0001) != 0;
	bool downKey = (GetAsyncKeyState(VK_DOWN) & 0x0001) != 0;
	bool leftKey = (GetAsyncKeyState(VK_LEFT) & 0x0001) != 0;
	bool rightKey = (GetAsyncKeyState(VK_RIGHT) & 0x0001) != 0;
	bool isAnyPressed = false;

	if (upKey && !isAnyPressed)
	{
		return Direction::UP;
		isAnyPressed = true;
	}
	if (downKey && !isAnyPressed)
	{
		return Direction::DOWN;
		isAnyPressed = true;
	}
	if (leftKey && !isAnyPressed)
	{
		return Direction::LEFT;
		isAnyPressed = true;
	}
	if (rightKey && !isAnyPressed)
	{
		return Direction::RIGHT;
		isAnyPressed = true;
	}
}