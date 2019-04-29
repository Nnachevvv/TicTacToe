#pragma once
const int DEFAULT_HEIGHT = 3;
const int DEFAULT_WIDTH = 3;
#include <iostream>
#include "Player.h"
class Board
{
public:
	Board();
	~Board();
	Board(const Board & board) = delete;
	Board & operator = (const Board & board)=delete;

public:
	void ChangeSize(int height,int width);
	void PlayTurn(int x,int y);
private:
	char ** gird;
	int height;
	int width;
	Player FirstPlayer;
	Player SecondPlayer;
	Player * currentTurn;
private:
	void InitGird(int height, int width);
	void SetNextTurn();
	void CheckForFinish();
	void FreeMemory();
};

