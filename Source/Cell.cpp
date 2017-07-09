#include "Cell.hpp"

Cell::Cell(sf::Vector2f pos, int w, int h)
{
	sprite = nullptr;
	myState = Null;
	initialize(pos, w, h);
}

Cell::Cell()
{	
	sprite = nullptr;
	myPos = sf::Vector2f(0,0);
	myState = Null;
}

Cell::~Cell()
{
	delete sprite;
}

void Cell::initialize(sf::Vector2f pos, int w, int h)
{
	myRect = sf::IntRect(pos.x, pos.y, w, h);
	myPos = sf::Vector2f(pos.x+60, pos.y+60);
}

state Cell::getState()
{
	return myState;
}

void Cell::setState(state state)
{
	myState = state;
}

bool Cell::isClicked(sf::Event &event, sf::RenderWindow &window)
{
	if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		return (myRect.contains(mousePos.x, mousePos.y));
	}
	else
		return false;
}

void Cell::setTexture(sf::Texture &texture)
{
	sprite = new sf::Sprite;
	sprite->setTexture(texture);
	sprite->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
	sprite->setPosition(myRect.left + myRect.width/2, myRect.top + myRect.height/2);
}

void Cell::draw(sf::RenderWindow &window)
{
	if(sprite != nullptr)
		window.draw(*sprite);
}

bool Cell::isFree()
{
	return (myState == Null);
}

void Cell::update(sf::Texture &texture, state playerState)
{
	myState = playerState;
	sprite = new sf::Sprite;
	sprite->setTexture(texture);
	sprite->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
	sprite->setPosition(myPos);
}

void Cell::reset()
{
	delete sprite;
	sprite = nullptr;
	myState = Null;
}

sf::Vector2f Cell::getPosition()
{
	return myPos;
}