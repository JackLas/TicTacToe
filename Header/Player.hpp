#ifndef PLAYER_H
#define PLAYER_H

#include "state.hpp"
#include "Board.hpp"

class Player
{
private:
	state myState;

	int myWins;
public:
	Player(state st);
	~Player();

	int checkMove(Board &board, sf::Event &event, sf::RenderWindow &window);
	state getState();
	void addWin(int win = 1);
	int getWins();
};

#endif //PLAYER_h