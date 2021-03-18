#pragma once
#include "CellType.h"
class Cell
{
private:
	int row = 0;
	int column = 0;
	CellType cellType = CellType::EMPTY;
public:
	Cell();
	Cell(int row, int column, CellType cellType);
	int getRow() { return row; }
	void setRow(int row) { this->row = row; }
	int getColumn() { return column; }
	void setColumn(int row) { this->column = column; }
	CellType getCellType() { return cellType; }
	void setCellType(CellType cellType) { this->cellType = cellType; }
};

