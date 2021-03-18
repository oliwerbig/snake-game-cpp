#pragma once
#include <list>
class Cell;
class Snake
{
private:
	std::list<Cell*> snakeCells;
	Cell* snakeHeadCell;
public:
	Snake(Cell* snakeHeadCell);
	void grow();
	void move(Cell* nextCell);
	bool willCollide(Cell* nextCell);
	std::list<Cell*> getSnakeCells() { return snakeCells; }
	void setSnakeCells(std::list<Cell*> snakeCells) { this->snakeCells = snakeCells; }
	Cell* getHeadCell() { return snakeHeadCell; }
	void setHeadCell(Cell* snakeHeadCell) { this->snakeHeadCell = snakeHeadCell; }
};

