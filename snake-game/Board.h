#pragma once
#include "CellType.h"
#include <vector>
class Cell;
class Board
{
private:
	int numOfRows = 0;
	int numOfColumns = 0;
	std::vector<std::vector<Cell>> cells;
public:
	Board(int numOfRows, int numOfColumns);
	int getNumOfRows() { return numOfRows; }
	void setNumOfRows(int numOfRows) { this->numOfRows = numOfRows; }
	int getNumOfColumns() { return numOfColumns; }
	void setNumOfColumns(int numOfColumns) { this->numOfColumns = numOfColumns; }
	Cell* getCell(int row, int column);
};

