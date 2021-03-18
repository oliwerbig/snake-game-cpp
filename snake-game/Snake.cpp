#include "Snake.h"
#include "Cell.h"
#include "CellType.h"

Snake::Snake(Cell* initialSnakeHeadCell)
{
	snakeHeadCell = initialSnakeHeadCell;
	snakeCells.push_back(snakeHeadCell);
}

void Snake::grow()
{
	snakeCells.push_back(snakeHeadCell);
}

void Snake::move(Cell* nextCell)
{
	Cell* tailCell = snakeCells.back();
	snakeCells.pop_back();
	tailCell->setCellType(CellType::EMPTY);
	snakeHeadCell = nextCell;
	snakeCells.push_front(snakeHeadCell);
}

bool Snake::willCollide(Cell* nextCell)
{
	for (Cell* cell : snakeCells)
	{
		if (cell == nextCell)
		{
			return true;
		}
	}

	return false;
}
