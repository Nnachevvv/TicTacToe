#pragma once
#include "Point.h"
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
	void ChangeSize(int xy);
	void PlayTurn(int xy);
private:
	Point ** gird;
	int height;
	int width;
	Player FirstPlayer;
	Player SecondPlayer;
	Player * currentTurn;
private:
	void InitGird(int height, int width);
	bool SetGirdSize(int xy);
	void SetNextTurn();
	void CheckForFinish();
	void FreeMemory();
};

