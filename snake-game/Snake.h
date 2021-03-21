#pragma once
#include "Direction.h"
#include <list>
class Cell;
class Snake
{
private:
	std::list<Cell*> cells;
public:
	Snake(Cell* headCell);
	
	void grow(Cell* nextCell);
	void move(Cell* nextCell);
	
	bool willCollide(Cell* nextCell);
	
	std::list<Cell*> getCells() { return cells; }
	void setCells(std::list<Cell*> cells) { this->cells = cells; }
	Cell* getHeadCell() { return cells.front(); }
};

