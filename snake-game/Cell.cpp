#include "Cell.h"

Cell::Cell()
{
	//ctor
}

Cell::Cell(int row, int column, CellType cellType)
{
	this->row = row;
	this->column = column;
	this->cellType = cellType;
};