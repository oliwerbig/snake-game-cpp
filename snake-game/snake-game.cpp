// snake-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Cell.h"
#include "Snake.h"
#include "Board.h"
#include "Game.h"
#include "CellType.h"
#include "Direction.h"
#include "WinTerminalScreen.h"
#include "WinKeyboardController.h"

#include <iostream>
#include <list>

using namespace std;

int main()
{
	WinTerminalScreen screen;
	WinKeyboardController controller;

	int totalScore = 0;
	int maxScore = 0;

	while (1)
	{
		Board board(screen.getHeight() - 2, screen.getWidth());
		Snake snake(board.getCell((board.getNumOfRows() / 2), (board.getNumOfColumns() / 2)));
		Game game(&screen, &controller, &board, &snake);

		

		while (!game.isGameOver())
		{
			game.update();
			screen.writeString(screen.getHeight() - 2, 0, L"Current Score: " + std::to_wstring(game.getScore()));
			screen.writeString(screen.getHeight() - 2, screen.getWidth() / 3, L"Max Score: " + std::to_wstring(maxScore));
			screen.writeString(screen.getHeight() - 2, screen.getWidth() / 1.5, L"Total Score: " + std::to_wstring(totalScore));
		}

		totalScore += game.getScore();
		if (game.getScore() > maxScore)
		{
			maxScore = game.getScore();
		}

		screen.writeString(15, 47, L"PRESS 'SPACE' TO PLAY AGAIN");
		while (!controller.isSpacePressed());
	}
	return 0;
}