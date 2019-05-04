#pragma once
#include <fstream>
class Player
{
public:
	Player();
	Player(char symbol);
	const char GetCharacter() const{ return this->turnCharacter; };
	bool operator ==(const  Player & player) const;
	bool operator !=(const  Player & player) const;
	
	inline void ResetResult() { this->score = 0; };
	inline void WinIncrementScore() { ++this->score; };
	friend std::ostream & operator << (std::ostream &out, const Player &c);

private:
	char turnCharacter;
	int score;
};


