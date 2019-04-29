#pragma once
class Player
{
public:
	Player();
	~Player();
	const char GetCharacter() const{ return this->turnCharacter; };
	bool operator ==(const  Player & player)
	{
		return turnCharacter == player.turnCharacter;
	}
	bool operator !=(const  Player & player)
	{
		return !(*this == player);
	}
private:
	char turnCharacter;

};


