#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "WinnerLine.hpp"
#include "Timer.hpp"

class GameScene: public Scene
{
private:
	sf::RenderWindow &window;
	std::map<std::string, sf::Texture> &textures;

	sf::Sprite *bg;
	Board *board;

	Player *playerX;
	Player *playerO;
	Player *currentPlayer;
	WinnerLine *wl;

	sf::Clock clock;
	Timer timer;
	sf::Text timerTxt;

	sf::Text XWinsTxt;
	sf::Text OWinsTxt;

	bool isPaused; 

public:
	GameScene(sf::RenderWindow &win, sf::Font &font, std::map<std::string, sf::Texture> &tx);
	~GameScene();

	sceneID show();
private:
	void swapPlayers();
};

#endif //GAMESCENE_H