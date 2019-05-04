#include "Player.h"

Player::Player():turnCharacter(' '),score(0)
{
}

Player::Player(char symbol):turnCharacter(symbol),score(0)
{

}

bool Player::operator==(const Player & player) const
{
		return turnCharacter == player.turnCharacter;
}

bool Player::operator!=(const Player & player) const
{
	return !(*this == player);
}

std::ostream & operator<<(std::ostream & out, const Player & c)
{
	out << c.score;
	return out;
}
