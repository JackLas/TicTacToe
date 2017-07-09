#ifndef CELL_H
#define CELL_H

#include <SFML\Graphics.hpp>
#include "state.hpp"

class Cell
{
private:
	sf::Sprite *sprite;	
	state myState;
	sf::Vector2f myPos;
	sf::IntRect myRect;
public:
	Cell(sf::Vector2f pos, int w, int h);
	Cell();
	~Cell();
	void initialize(sf::Vector2f pos, int w, int h);
	state getState();
	void setState(state state);
	bool isClicked(sf::Event &event, sf::RenderWindow &window);
	void setTexture(sf::Texture &texture);
	void draw(sf::RenderWindow &window);
	bool isFree();
	void update(sf::Texture &texture, state playerState);
	void reset();
	sf::Vector2f getPosition();
};

#endif //CELL_H