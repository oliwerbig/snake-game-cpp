#include "Board.h"
#include "Cell.h"
#include "CellType.h"

#include <vector>

Board::Board(int numOfRows, int numOfColumns)
{
	this->numOfRows = numOfRows;
	this->numOfColumns = numOfColumns;

	for (int row = 0; row < numOfRows; row++) {
		std::vector<Cell> temp;
		for (int column = 0; column < numOfColumns; column++) {
			Cell cell(row, column, CellType::EMPTY);
			temp.push_back(cell);
		}
		cells.push_back(temp);
	}
}

Cell* Board::getCell(int row, int column)
{
	return &cells[row][column];
}