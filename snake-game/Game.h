#pragma once
#include "Direction.h"
class Screen;
class Controller;
class Cell;
class Board;
class Snake;
class Game
{
protected:
	Screen* screen;
	Controller* controller;
	Board* board;
	Snake* snake;
	bool gameOver = false;
	Direction direction = Direction::NONE;
	int score = 0;
public:
	Game(Screen* screen, Controller* controller, Board* board, Snake* snake);

	void update();
	void placeBorders();
	void placeSnake();
	void placeNewFood();
	void checkForNewDirection();
	Cell* getNextCell();

	Screen* getScreen() { return screen; }
	void setScreen(Screen* screen) { this->screen = screen; }
	Snake* getSnake() { return snake; }
	void setSnake(Snake* snake) { this->snake = snake; }
	Board* getBoard() { return board; }
	void setBoard(Board* board) { this->board = board; }
	bool isGameOver() { return gameOver; }
	void setGameOver(bool gameOver) { this->gameOver = gameOver; }
	Direction getDirection() { return direction; }
	void setDirection(Direction direction) { this->direction = direction; }
	int getScore() { return score; }
	void setScore(int score) { this->score = score; }
};

