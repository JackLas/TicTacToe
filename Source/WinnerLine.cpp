#include "WinnerLine.hpp"
#include <cmath>

WinnerLine::WinnerLine(sf::Texture &texture, float step, float maxLength): myTexture(texture)
{
	mySprite = new sf::Sprite;
	mySprite->setTexture(myTexture);
	isRunning = false;
	isComplete = false;
	myStep = step;
	myMaxLength = maxLength;
	myCurrentLength = 0;
}

WinnerLine::WinnerLine(sf::Texture &texture, float step, winCombination *winComb): myTexture(texture)
{
	mySprite = new sf::Sprite;
	mySprite->setTexture(myTexture);
	isRunning = false;
	isComplete = false;
	myStep = step;
	myMaxLength = sqrt(pow((winComb->right.x - winComb->left.x), 2) + pow((winComb->right.y - winComb->left.y), 2)) + 100;
	myCurrentLength = 0;
	mySprite->setOrigin(myMaxLength/2, myTexture.getSize().y/2);
	mySprite->setTextureRect(sf::IntRect(0, 0, myCurrentLength, myTexture.getSize().y));

	mySprite->setRotation(atan((winComb->right.y - winComb->left.y)/(winComb->right.x - winComb->left.x))*180/3.14);
	mySprite->setPosition(winComb->middle);
}

WinnerLine::~WinnerLine()
{
	delete mySprite;
}

void WinnerLine::update(float deltaTime)
{
	if(isRunning && !isComplete)
	{
		mySprite->setTextureRect(sf::IntRect(0, 0, myCurrentLength, myTexture.getSize().y));
		myCurrentLength += myStep * deltaTime;

		if(myCurrentLength > myMaxLength)
			isComplete = true;
	}
}

void WinnerLine::activate()
{
	isRunning = true;
}

void WinnerLine::deactivate()
{
	isRunning = false;
}


bool WinnerLine::isCompleted()
{
	return isComplete;
}

void WinnerLine::reset()
{
	myCurrentLength = 0;
	isRunning = false;
	isComplete = false;
}

void WinnerLine::setMaxLength(float length)
{
	myMaxLength = length;
}

float WinnerLine::getMaxLength()
{
	return myMaxLength;
}

void WinnerLine::draw(sf::RenderWindow &window)
{
	window.draw(*mySprite);
}
