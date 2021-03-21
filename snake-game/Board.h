#pragma once
#include "CellType.h"
#include <vector>
class Cell;
class Board
{
protected:
	int numOfRows = 0;
	int numOfColumns = 0;
private:
	std::vector<std::vector<Cell>> cells;
public:
	Board(int numOfRows, int numOfColumns);

	int getNumOfRows() { return numOfRows; }
	int getNumOfColumns() { return numOfColumns; }
	Cell* getCell(int row, int column);
};

