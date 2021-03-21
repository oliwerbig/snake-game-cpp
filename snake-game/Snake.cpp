#include "Snake.h"
#include "Cell.h"
#include "CellType.h"

Snake::Snake(Cell* headCell)
{
	headCell->setCellType(CellType::SNAKE_HEAD);
	cells.push_front(headCell);
}

void Snake::grow(Cell* nextCell)
{
	getHeadCell()->setCellType(CellType::SNAKE_BODY);
	nextCell->setCellType(CellType::SNAKE_HEAD);
	cells.push_front(nextCell);
}

void Snake::move(Cell* nextCell)
{
	if (nextCell != getHeadCell())
	{
		getHeadCell()->setCellType(CellType::SNAKE_BODY);
		nextCell->setCellType(CellType::SNAKE_HEAD);
		cells.push_front(nextCell);
		cells.back()->setCellType(CellType::EMPTY);
		cells.pop_back();
	}
}

bool Snake::willCollide(Cell* nextCell)
{
	if (nextCell->getCellType() == CellType::BORDER)
	{
		return true;
	}
	else if (nextCell->getCellType() == CellType::SNAKE_BODY)
	{
		return true;
	}

	return false;
}
