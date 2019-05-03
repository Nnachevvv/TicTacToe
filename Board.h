#pragma once
#include "Point.h"

#include <iostream>
#include <fstream>
#include "Player.h"

const int DEFAULT_SIZE = 3;
const int MAX_SIZE = 10;
class Board
{
public:
	Board();
	~Board();
	Board(const Board & board) = delete;
	Board & operator = (const Board & board)=delete;
	friend std::ostream & operator << (std::ostream &out, const Board &c);

public:
	void ChangeSize(int xy);
	void PlayTurn(int xy,Player & player);
	bool ValidMove(int xy);
private:
	bool CheckForFinish(int x, int y);
	int CheckUp(int x, int y);
	int CheckBottom(int x, int y);
	int CheckLeft(int x, int y);
	int CheckRight(int x , int y);
	bool CheckDiagonal(int x, int y);
private:
	Point ** gird;
	int size;
	
private:
	void InitGird(int size);
	bool ValidSize(int size);
	void FreeMemory();
};

