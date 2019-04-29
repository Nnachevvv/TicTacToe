#pragma once
#include "Board.h"
#include <iostream>
class Game
{
public:
	Game();
	~Game();
	
	void StartGame();
	void ChangeSizeOfGird(int xy);
	void ResetResult();
	void PlayTurn(int xy);
private:
	Board board;
	int FirstPlayerResult;
	int SecondPlayerResult;
	void Draw();
};

