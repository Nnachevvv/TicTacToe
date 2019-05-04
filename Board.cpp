#include "Board.h"
#include <iostream>


Board::Board():takenCells(0),gird(nullptr)
{
	this->size = DEFAULT_SIZE;
	InitGird();
}


Board::~Board()
{
	FreeMemory();
}



void Board::ChangeSize(int size)
{
	if(ValidSize(size))
	{
		FreeMemory();
		this->size = size;
		InitGird();
	}
	else
	{
		std::cout << "Invalid parameters for new Gird" << std::endl;
	}
	
}

void Board::PlayTurn(const Point & point,Player & player)
{
	gird[point.getX()][point.getY()].Marked(player.GetCharacter());
	++takenCells;
	
}

bool Board::ValidMove(const Point & point)
{
	int XCordinatePoint = point.getX();
	int YCordinatePoint = point.getY();

	if (XCordinatePoint < 0 || YCordinatePoint <0 
		|| XCordinatePoint >= this->size || YCordinatePoint >= this->size  )
	{
		std::cout << "Invalid Position!" << std::endl;
		return false;
	}
	if (point != gird[XCordinatePoint][YCordinatePoint])
	{
		std::cout << "This position is taken , can't place symbol here!Try again!" << std::endl;
		return false;
	}
	return true;
}

int Board::CheckBottom(int x, int y)
{
	int count = 0;
	int curr_x = x-1;
	while (curr_x >= 0 && gird[curr_x][y] == gird[x][y])
	{
		--curr_x;
		count++;
	}
	return count;
}

int Board::CheckLeft(int x, int y)
{
	int count = 0;
	int curr_y = y-1;
	while (curr_y >= 0 && gird[x][curr_y] == gird[x][y])
	{
		--curr_y;
		count++;
	}
	return count;
}

int Board::CheckRight(int x, int y)
{
	int count = 0;
	int curr_y = y+1;
	while (curr_y < size && gird[x][curr_y] == gird[x][y])
	{
		++curr_y;
		count++;
	}
	return count;
}

bool Board::CheckDiagonal(int x ,int y)
{
	for (int i = 0; i < size; i++)
	{
		if (gird[i][i]!=gird[x][y])
		{
			return false;
		}
	}
	return true;
}

bool Board::CheckAntiDiagonal(int x, int y)
{
	int jCounter = 0;
	for (int i = size-1; i >= 0; i--)
	{
		if (gird[i][jCounter] != gird[x][y])
		{
			return false;
		}
		++jCounter;
	}
	return true;
}

bool Board::isDraw()
{
	return this->takenCells == (size*size);
}

int Board::CheckUp(int x, int y)
{
	int count = 0;
	int curr_x = x+1;
	while (curr_x < size && (gird[curr_x][y] == gird[x][y]))
	{
		++curr_x;
		count++;
	}
	return count;
}

void Board::InitGird()
{
	gird = new Point*[size];
	for (int i = 0; i < size; i++)
	{
		gird[i] = new Point[size];
		for (int j = 0; j < size; j++)
		{
			gird[i][j].Set_Point(i,j);
		}
	}
}

bool Board::ValidSize(int size)
{
	if (size < DEFAULT_SIZE && size>MAX_SIZE)
	{
		return false;
	}
	return true;
}

bool Board::CheckForFinish(const Point & point)
{
	int x = point.getX();
	int y = point.getY();
	int winningPositions = 1;
	winningPositions += CheckUp(x, y);
	winningPositions += CheckBottom(x,y);
	if (winningPositions>=size)
	{
		return true;
	}
	winningPositions = 1;
	winningPositions += CheckLeft(x, y);
	winningPositions += CheckRight(x, y);
	if (winningPositions >= size)
	{
		return true;
	}
	if (CheckDiagonal(x,y) || CheckAntiDiagonal(x,y))
	{
		return true;
	}
	return false;


}

void Board::FreeMemory()
{
	takenCells = 0;
	for (int i = 0; i < size; i++)
	{
		delete[] gird[i];
	}
	delete[] gird;
	gird = nullptr;
}

std::ostream & operator<<(std::ostream & out, const Board & c)
{
	out << " ";
	for (int j = 0; j < c.size; j++)
	{
		out << "  "<< j << " ";
	}
	out << std::endl;
	for (int i = 0; i < c.size; i++)
	{
		out << " ";
		for (int j = 0; j < c.size; j++)
		{
			out << "+---";
		}
		out << "+" << std::endl;
		out << i;
		out << "|";
		for (int j = 0; j < c.size; j++)
		{
			out <<" "<< c.gird[i][j] << " |";
		}
		out << std::endl;
	}
	out << " ";
	for (int i = 0; i < c.size; i++)
	{
		out << "+---";
	}
	out << "+" << std::endl;
	return out;
}
