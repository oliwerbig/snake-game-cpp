#include "Game.h"
#include "Screen.h"
#include "Controller.h"
#include "Board.h"
#include "Snake.h"
#include "Cell.h"

#include <random>
#include <chrono>
#include <thread>

Game::Game(Screen* screen, Controller* controller, Board* board, Snake* snake)
{
	this->board = board;
	this->snake = snake;
	this->screen = screen;
	this->controller = controller;
	placeBorders();
	placeSnake();
	placeNewFood();
}

void Game::update()
{
	checkForNewDirection();
	Cell* nextCell = getNextCell();

	placeSnake();

	if (snake->willCollide(nextCell))
	{
		setDirection(Direction::NONE);
		gameOver = true;
	}
	else
	{
		if (nextCell->getCellType() == CellType::FOOD) {
			score++;
			snake->grow(nextCell);
			placeNewFood();
		}
		else
		{
			snake->move(nextCell);
		}
	}

	screen->renderBoard(board);

	switch (direction)
	{
	case Direction::NONE:
		break;
	case Direction::RIGHT:
	case Direction::LEFT:
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
		break;
	case Direction::UP:
	case Direction::DOWN:
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
		break;
	default:
		break;
	}
	
}

void Game::placeBorders()
{
	for (int i = 0; i < board->getNumOfColumns(); i++)
	{
		board->getCell(0, i)->setCellType(CellType::BORDER);
	}

	for (int i = 0; i < board->getNumOfRows(); i++)
	{
		board->getCell(i, 0)->setCellType(CellType::BORDER);
		board->getCell(i, board->getNumOfColumns()-1)->setCellType(CellType::BORDER);
	}

	for (int i = 0; i < board->getNumOfColumns(); i++)
	{
		board->getCell(board->getNumOfRows()-1, i)->setCellType(CellType::BORDER);
	}
}

void Game::placeSnake()
{
	for (Cell* cell : snake->getCells())
	{
		board->getCell(cell->getRow(), cell->getColumn())->setCellType(cell->getCellType());
	}
}

void Game::placeNewFood()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> rowDist(0, board->getNumOfRows());
	std::uniform_real_distribution<double> columnDist(0, board->getNumOfColumns());
	int row = (int)rowDist(rd);
	int column = (int)columnDist(rd);
	while (board->getCell(row, column)->getCellType() != CellType::EMPTY)
	{
		row = (int)rowDist(rd);
		column = (int)columnDist(rd);
	}
	board->getCell(row, column)->setCellType(CellType::FOOD);
}

Cell* Game::getNextCell()
{
	int row = snake->getHeadCell()->getRow();
	int column = snake->getHeadCell()->getColumn();

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

void Game::checkForNewDirection()
{
	Direction newDirection = Direction::NONE;
	if (controller->isUpPressed())
	{
		newDirection = Direction::UP;
	}
	if (controller->isDownPressed())
	{
		newDirection = Direction::DOWN;
	}
	if (controller->isLeftPressed())
	{
		newDirection = Direction::LEFT;
	}
	if (controller->isRightPressed())
	{
		newDirection = Direction::RIGHT;
	}

	if (newDirection != Direction::NONE)
	{
		direction = newDirection;
	}
}