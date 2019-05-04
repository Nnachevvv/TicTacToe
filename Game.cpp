#include "Game.h"
#include <fstream>
#include "Point.h"

Game::Game()
{
	InitCharacter();
	currentPlayer = &firstPlayer;
	GetCommand();
}


void Game::StartGame()
{
	Draw();

	int xy;
	while (true)
	{
		std::cout << "Enter position for next move:" << std::endl;
		std::cin >> xy;
		Point point(xy);
		if (board.ValidMove(point))
		{
			board.PlayTurn(point, *currentPlayer);
			if (board.CheckForFinish(point))
			{
				currentPlayer->WinIncrementScore();
				Draw();
				std::cout << "Player with symbol "<< currentPlayer->GetCharacter() << " win!"<< std::endl;
				SetNextTurn();
				board.InitGird();
				GetCommand();
				break;
			}
			else if (board.isDraw())
			{
					Draw();
					std::cout << "Draw!" << std::endl;
					board.InitGird();
					GetCommand();
					break;
			}
			SetNextTurn();
			
			Draw();
		}
	}
}

void Game::ChangeSizeOfGird()
{
	int size;
	std::cout << "Enter new size of gird.";
	std::cin >> size;
	board.ChangeSize(size);
}

void Game::ResetResult()
{
	this->firstPlayer.ResetResult();
	this->secondPlayer.ResetResult();
}


void Game::InitCharacter()
{
	std::cout << "Enter X or O:" << std::endl;
	char symbol;
	std::cin >> symbol;
	while (symbol != 'X' && symbol != 'O')
	{
		std::cout << "Only X or O are allowed." << std::endl;
		std::cin >> symbol;
	}
	if (symbol == 'X')
	{
		this->firstPlayer = Player('X');
		this->secondPlayer = Player('O');
	}
	else
	{
		this->firstPlayer = Player('O');
		this->secondPlayer = Player('X');
	}
	system("cls");
}
void Game::SetNextTurn()
{
	if (*currentPlayer == firstPlayer)
	{
		currentPlayer = &secondPlayer;
	}
	else
	{
		currentPlayer = &firstPlayer;
	}
}

void Game::Draw()
{
	system("cls");
	std::cout << "Player 1      Player 2" << std::endl;
	std::cout << "   "<< firstPlayer<<"            " <<"   "<< secondPlayer<<std::endl;
	std::cout << board;
	std::cout << std::endl;
}

void Game::GetCommand()
{
	std::cout << "Enter command : Play  | ChangeGird | ResetScore | Quit" << std::endl;
	char buffer[64];
	std::cin >> buffer;
	while (true)
	{
		if (!strcmp(buffer,"Play"))
		{
			this->StartGame();
		}
		else if (!strcmp(buffer, "ResetScore"))
		{
			this->ResetResult();
		}
		else if (!strcmp(buffer, "ChangeGird"))
		{
			this->ChangeSizeOfGird();
		}
		else if (!strcmp(buffer, "Quit"))
		{
			return;
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}
		std::cout << "Enter command : Play  | ChangeGird | ResetScore " << std::endl;
		std::cin >> buffer;
		system("cls");
	}
}
