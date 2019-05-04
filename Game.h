#pragma once
#include "Board.h"
#include <iostream>
class Game
{
public:
	Game();
	void GetCommand();
private:
	void StartGame();
	void ChangeSizeOfGird();
	void ResetResult();
	void InitCharacter();
	void SetNextTurn();
	void Draw();
private:
	Board board;
	Player firstPlayer;
	Player secondPlayer;
	Player * currentPlayer;
};

