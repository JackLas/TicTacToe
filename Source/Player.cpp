#include "Player.hpp"

Player::Player(state st)
{
	myState = st;
	myWins = 0;
}

Player::~Player()
{
}

int Player::checkMove(Board &board, sf::Event &event, sf::RenderWindow &window)
{
	return board.checkMove(event, window);
}

state Player::getState()
{
	return myState;
}

void Player::addWin(int win)
{	
	myWins += win;
}

int Player::getWins()
{
	return myWins;
}