#include "Board.h"
#include <iostream>


Board::Board()
{
	currentTurn = &FirstPlayer;
	InitGird(DEFAULT_HEIGHT, DEFAULT_WIDTH);
}


Board::~Board()
{
	FreeMemory();
}



void Board::ChangeSize(int xy)
{
	if(SetGirdSize(xy))
	{
		InitGird(height, width);
	}
	else
	{
		std::cout << "Invalid parameters for new Gird" << std::endl;
	}
	
}

void Board::PlayTurn(int xy)
{
	//TO DO : CHECK IF GIRD CONTAINS POINT

	gird[0][0] = currentTurn->GetCharacter();
	SetNextTurn();
	CheckForFinish();
}

void Board::InitGird(int height, int width)
{
	if (height<DEFAULT_HEIGHT || width<DEFAULT_HEIGHT ||width>10 ||height>10)
	{
		std::cout << "Can't set gird with this size"<<std::endl;
		return;
	}
	FreeMemory();
	gird = new Point*[height];
	for (size_t i = 0; i < height; i++)
	{
		gird[i] = new Point[width];
		for (size_t j = 0; j < width; j++)
		{
			gird[i][j].Set_Point(i,j);
		}
	}
	this->height = height;
	this->width = width;
}

bool Board::SetGirdSize(int xy)
{
	if (xy < 10)
	{
		this->height = 0;
	}
	else
	{
		this->height = xy / 10;
	}
	this->width = xy % 10;
	if (height < 3 || width < 3 || height > 10 || width > 10)
	{
		return false;
	}
	return true;
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
	gird = nullptr;
}
