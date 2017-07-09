#include "Board.hpp"

Board::Board(std::map<std::string, sf::Texture> &tx, sf::Vector2f pos): textures(tx)
{
	board = new sf::Sprite(textures["board.png"]);
	board->setPosition(pos);

	cell = new Cell[9];

	int i = 0;
	for(int y = 50; y < 440; y += 130)
	{
		for(int x = 50; x < 440; x += 130)
		{
			cell[i].initialize(sf::Vector2f(x, y), 120, 120);
			i++;
		}
	}
}

Board::~Board()
{
	delete[] cell;
	delete board;
}

void Board::setPosition(sf::Vector2f pos)
{
	board->setPosition(pos);
}

void Board::setPosition(float x, float y)
{
	board->setPosition(x, y);	
}

sf::Vector2f Board::getPosition()
{
	return board->getPosition();
}

void Board::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < 9; i++)
		cell[i].draw(window);
	window.draw(*board);
}

int Board::checkMove(sf::Event &event, sf::RenderWindow &window)
{
	for(int i = 0; i < 9; i++)
		if(cell[i].isClicked(event, window))
			return i;

	return -1;
}

bool Board::checkUpdate(int cellID)
{
	if(cellID != -1)
		return cell[cellID].isFree();
	else return false;
}

void Board::update(int cellID, state playerState)
{
	switch(playerState)
	{
		case X:
			cell[cellID].update(textures["x.png"], playerState);
			break;

		case O:
			cell[cellID].update(textures["o.png"], playerState);
			break;

		default:
			break;
	}
}

winCombination* Board::checkWinner()
{
	for(int i = 3; i < 6; i++) //check  vertical
	{
		if(cell[i].getState() != Null && cell[i].getState() == cell[i-3].getState() && cell[i].getState() == cell[i+3].getState())
		{
			winCombination *winComb = new winCombination;
			winComb->left = cell[i-3].getPosition();
			winComb->middle = cell[i].getPosition();
			winComb->right = cell[i+3].getPosition();
			return winComb;
		}		
	}

	for(int i = 1; i < 9; i+=3) //check horizontal
	{
		if(cell[i].getState() != Null && cell[i].getState() == cell[i-1].getState() && cell[i].getState()  == cell[i+1].getState())
		{
			winCombination *winComb = new winCombination;
			winComb->left = cell[i-1].getPosition();
			winComb->middle = cell[i].getPosition();
			winComb->right = cell[i+1].getPosition();
			return winComb;
		}
	}
	
	if(cell[4].getState() != Null && cell[4].getState() == cell[0].getState() && cell[4].getState() == cell[8].getState())
	{
		winCombination *winComb = new winCombination;
		winComb->left = cell[0].getPosition();
		winComb->middle = cell[4].getPosition();
		winComb->right = cell[8].getPosition();
		return winComb;
	}

	if(cell[4].getState() != Null && cell[4].getState() == cell[2].getState() && cell[4].getState() == cell[6].getState())
	{
		winCombination *winComb = new winCombination;
		winComb->left = cell[6].getPosition();
		winComb->middle = cell[4].getPosition();
		winComb->right = cell[2].getPosition();
		return winComb;
	}

	return nullptr;
}

void Board::reset()
{
	for(int i = 0; i < 9; i++)
		cell[i].reset();
}

bool Board::checkFreeCell()
{
	for(int i = 0; i < 9; i++)
		if(cell[i].getState() == Null)
			return true;

	return false;
}