#include "GameScene.hpp"
#include "winCombination.hpp"
#include <to_string.hpp>

#include <iostream>

GameScene::GameScene(sf::RenderWindow &win, sf::Font &font, std::map<std::string, sf::Texture> &tx): window(win), textures(tx)
{
	bg = new sf::Sprite(textures["background.png"]);
	board = new Board(textures, sf::Vector2f(40, 40));

	playerX = new Player(state::X);
	XWinsTxt.setFont(font);
	XWinsTxt.setCharacterSize(60);
	XWinsTxt.setPosition(500, 50);
	XWinsTxt.setFillColor(sf::Color(153, 81, 23, 255));

	playerO = new Player(state::O);
	OWinsTxt.setFont(font);
	OWinsTxt.setPosition(500, 120);
	OWinsTxt.setCharacterSize(60);
	OWinsTxt.setFillColor(sf::Color(153, 81, 23, 255));

	timerTxt.setFont(font);
	timerTxt.setPosition(500, 400);
	timerTxt.setFillColor(sf::Color(153, 81, 23, 255));

	currentPlayer = playerX;

	wl = nullptr;
	isPaused = false;
}

GameScene::~GameScene()
{
	delete bg;
	delete board;
	delete playerX;
	delete playerO;
	delete wl;
}

void GameScene::swapPlayers()
{
	if(currentPlayer->getState() == X)
		currentPlayer = playerO;
	else currentPlayer = playerX;
}

Scene::sceneID GameScene::show()
{
	sf::Time time = clock.restart();
	sf::Event event;
	int cellID = -1;
	
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();

		if(!isPaused && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			board->reset();

		if(!isPaused)
			cellID = currentPlayer->checkMove(*board, event, window);
	}

	if(board->checkUpdate(cellID))
	{
		board->update(cellID, currentPlayer->getState());

		winCombination *winComb = board->checkWinner();
		
		if(winComb != nullptr)
		{
			wl = new WinnerLine(textures["winnerLine.png"], 250, winComb);
			wl->activate();
			delete winComb;
			currentPlayer->addWin();
			isPaused = true;
		}

		swapPlayers();
	}

	if(wl != nullptr)
	{
		wl->update(time.asSeconds());

		if(wl->isCompleted())
		{
			board->reset();

			delete wl;
			wl = nullptr;

			isPaused = false;
		}
	}

	XWinsTxt.setString("X: " + sf::String(to_string(playerX->getWins())));
	OWinsTxt.setString("O: " + sf::String(to_string(playerO->getWins())));

	timer.update(time.asSeconds());
	timerTxt.setString(timer.getString());

	window.clear();
		window.draw(*bg);
		board->draw(window);
		if(wl != nullptr)
			wl->draw(window);
		window.draw(XWinsTxt);
		window.draw(OWinsTxt);
		window.draw(timerTxt);
	window.display();

	return IDGameScene;
}