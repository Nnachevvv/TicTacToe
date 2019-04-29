#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::StartGame()
{

}

void Game::ChangeSizeOfGird(int xy)
{
	int x = xy / 10;
	int y = xy % 5;
	if (x>10 || x<3 || x>y)
	{
		std::cout << "Error, can't create board with these size! Give values between 3 and 10!"<<std::endl;
		return;
	}
	board.ChangeSize(x, y);
}

void Game::ResetResult()
{
	this->FirstPlayerResult = 0;
	this->SecondPlayerResult = 0;
}

void Game::PlayTurn(int xy)
{
	int x = xy / 10;
	int y = xy % 5;
	board.PlayTurn(x, y);
}
