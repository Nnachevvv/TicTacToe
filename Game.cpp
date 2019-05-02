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
	board.ChangeSize(xy);
}

void Game::ResetResult()
{
	this->FirstPlayerResult = 0;
	this->SecondPlayerResult = 0;
}

void Game::PlayTurn(int xy)
{
	
	board.PlayTurn(xy);
}
