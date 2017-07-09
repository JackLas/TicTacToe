#ifndef BOARD_H
#define BOARD_H

#include <SFML\Graphics.hpp>
#include <map>
#include <string>

#include "Cell.hpp"
#include "winCombination.hpp"

class Board
{
private:
	std::map<std::string, sf::Texture> &textures;
	sf::Sprite *board;

	sf::Texture textureX;
	sf::Texture textureO;

	Cell *cell;
public:
	Board(std::map<std::string, sf::Texture> &tx, sf::Vector2f pos);
	~Board();

	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();

	void draw(sf::RenderWindow &window);

	int checkMove(sf::Event &event, sf::RenderWindow &window);
	bool checkUpdate(int cellID);
	void update(int cellID, state playerState);

	winCombination* checkWinner();

	void reset();

	bool checkFreeCell();
};

#endif //BOARD_H