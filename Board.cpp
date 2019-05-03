#include "Board.h"
#include <iostream>


Board::Board()
{
	InitGird(DEFAULT_SIZE);
}


Board::~Board()
{
	FreeMemory();
}



void Board::ChangeSize(int size)
{
	if(ValidSize(size))
	{
		InitGird(size);
	}
	else
	{
		std::cout << "Invalid parameters for new Gird" << std::endl;
	}
	
}

void Board::PlayTurn(int xy,Player & player)
{
	Point point(xy);
	gird[point.getX()][point.getY()].Marked(player.GetCharacter());
	if (CheckForFinish(point.getX(), point.getY()))
	{
		std::cout << "Player with symbol win " << player.GetCharacter()<<std::endl;
		player.WinIncrementScore();
		InitGird(size);
	};
}

bool Board::ValidMove(int xy)
{
	Point point(xy);
	if (point.getX() < 0 || point.getY() <0 || 
		point.getX()>=this->size || point.getY()>=this->size  )
	{
		std::cout << "Invalid Position!" << std::endl;
		return false;
	}
	if (point!=gird[point.getX()][point.getY()])
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
	while (curr_x > 0 && gird[curr_x][y] == gird[x][y])
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
	while (curr_y > 0 && gird[curr_y][y] == gird[x][y])
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
	while (curr_y < size && gird[curr_y][y] == gird[x][y])
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

void Board::InitGird(int size)
{
	FreeMemory();
	this->size = size;
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



bool Board::CheckForFinish(int x, int y)
{
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
	if (CheckDiagonal(x,y))
	{
		return true;
	}
	return false;


}



void Board::FreeMemory()
{
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
