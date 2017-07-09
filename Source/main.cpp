#include <SFML\Graphics.hpp>

#include "Loader.hpp"
#include "GameScene.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Tic-Tac-Toe", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	Loader *loader = new Loader;
	std::map<std::string, sf::Texture> textures = loader->createTextureMap(loader->load("texture.dat"));
	sf::Font mainFont = loader->createFont(loader->load("font.dat"));
	delete loader;

	Scene *currentScene = new GameScene(window, mainFont, textures);

	while(window.isOpen())
	{
		currentScene->show();
	}

	delete currentScene;
	return 0;
}