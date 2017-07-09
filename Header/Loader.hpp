#ifndef LOADER_H
#define LOADER_H

#include "RAWdata.hpp"
#include <SFML\Graphics.hpp>
#include <vector>
#include <map>

class Loader
{
private:
public:
	Loader();
	~Loader();

	std::vector<RAWdata*> load(std::string file);
	std::map<std::string, sf::Texture> createTextureMap(std::vector<RAWdata*> data);
	sf::Font createFont(std::vector<RAWdata*> data);
};

#endif //LOADER_H