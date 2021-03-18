#include "Game.h"
#include "Board.h"
#include "Snake.h"
#include "Cell.h"
#include "CellType.h"
#include "Direction.h"

Game::Game(Snake* snake, Board* board)
{
	this->snake = snake;
	this->board = board;
	placeFood();
}

Cell* Game::getNextCell(Cell* currentCell)
{
	int row = currentCell->getRow();
	int column = currentCell->getColumn();

	if (direction == Direction::RIGHT) {
		column++;
	}
	else if (direction == Direction::LEFT) {
		column--;
	}
	else if (direction == Direction::UP) {
		row--;
	}
	else if (direction == Direction::DOWN) {
		row++;
	}

	Cell* nextCell = board->getCell(row, column);

	return nextCell;
}

void Game::update()
{
	placeSnake();
	if (!gameOver) {
		if (direction != Direction::NONE) {
			Cell* nextCell = getNextCell(snake->getHeadCell());

			if (snake->willCollide(nextCell)) {
				setDirection(Direction::NONE);
				gameOver = true;
			}
			else {
				snake->move(nextCell);
				if (nextCell->getCellType() == CellType::FOOD) {
					snake->grow();
					placeFood();
				}
			}
		}
	}
}

void Game::placeFood()
{
	int row = rand() % board->getNumOfRows();
	int column = rand() % board->getNumOfColumns();
	board->getCell(row, column)->setCellType(CellType::FOOD);
}

void Game::placeSnake()
{
	for (Cell* snakeCell : snake->getSnakeCells())
	{
		board->getCell(snakeCell->getRow(), snakeCell->getColumn())->setCellType(CellType::SNAKE_BODY);
	}
	board->getCell(snake->getHeadCell()->getRow(), snake->getHeadCell()->getColumn())->setCellType(CellType::SNAKE_HEAD);
}