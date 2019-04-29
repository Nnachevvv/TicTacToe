#include "Board.h"



Board::Board()
{
	currentTurn = &FirstPlayer;
	InitGird(DEFAULT_HEIGHT, DEFAULT_WIDTH);
}


Board::~Board()
{
	FreeMemory();
}



void Board::ChangeSize(int height, int width)
{
	InitGird(height, width);
}

void Board::PlayTurn(int x, int y)
{
	if (x>=height || y>=width || x<0 || y<0)
	{
		std::cout << "Invalid position!" << std::endl;
		return;
	}
	gird[x][y] = currentTurn->GetCharacter();
	SetNextTurn();
	CheckForFinish();
}

void Board::InitGird(int height, int width)
{
	gird = new char *[height];
	for (int i = 0; i < height; i++)
	{
		gird[height] = new char[width];
	}
	this->height = height;
	this->width = width;
}

void Board::SetNextTurn()
{
	if (*currentTurn == FirstPlayer)
	{
		currentTurn == &SecondPlayer;
	}
	else
	{
		currentTurn == &FirstPlayer;
	}
}

void Board::CheckForFinish()
{
}

void Board::FreeMemory()
{
	for (int i = 0; i < height; i++)
	{
		delete[] gird[i];
	}
	delete[] gird;
}
