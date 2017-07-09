#ifndef WINNERLINE_H
#define WINNERLINE_H

#include <SFML\Graphics.hpp>
#include "winCombination.hpp"

class WinnerLine
{
private:
	sf::Sprite *mySprite;
	sf::Texture &myTexture;
	bool isRunning;
	bool isComplete;
	float myStep;
	float myMaxLength;
	float myCurrentLength;

public:
	WinnerLine(sf::Texture &texture, float step, float maxLength);
	WinnerLine(sf::Texture &texture, float step, winCombination *winComb);
	~WinnerLine();

	void update(float deltaTime);
	void activate();
	void deactivate();

	bool isCompleted();

	void reset();

	void setMaxLength(float length);
	float getMaxLength();

	void draw(sf::RenderWindow &window);
};

#endif //WINNERLINE_H