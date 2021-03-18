#pragma once
#include "Direction.h"
class Snake;
class Board;
class Cell;
class Game
{
private:
	Snake* snake;
	Board* board;
	Direction direction = Direction::NONE;
	bool gameOver = false;
	Cell* getNextCell(Cell* currentCell);
public:
	Game(Snake* snake, Board* board);
	Snake* getSnake() { return snake; }
	void setSnake(Snake* snake) { this->snake = snake; }
	Board* getBoard() { return board; }
	void setBoard(Board* board) { this->board = board; }
	bool isGameOver() { return gameOver; }
	void setGameOver(bool gameOver) { this->gameOver = gameOver; }
	Direction getDirection() { return direction; }
	void setDirection(Direction direction) { this->direction = direction; }
	void update();
	void placeFood();
	void placeSnake();
};

