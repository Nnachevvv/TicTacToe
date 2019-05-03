#include "Player.h"

Player::Player():turnCharacter(' '),score(0)
{
}

Player::Player(char symbol):turnCharacter(symbol),score(0)
{

}

std::ostream & operator<<(std::ostream & out, const Player & c)
{
	out << c.score;
	return out;
}
