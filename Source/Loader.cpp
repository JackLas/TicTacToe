#include "Loader.hpp"

typedef unsigned int uint;

Loader::Loader()
{
}

Loader::~Loader()
{
}

std::vector<RAWdata*> Loader::load(std::string file)
{
	FILE *arch = fopen(file.c_str(), "rb");
	std::vector<RAWdata*> alldata;

	if(arch)
	{
		while(true) 
		{
			char buffer;

			//reading size of filename
			size_t FNsize;
			if(!fread((char*)&FNsize, sizeof(char), sizeof(size_t), arch))
				break; //exit from loop

			//reading filename
			std::string filename;
			for(uint i = 0; i < FNsize; i++)
			{
				fread(&buffer, sizeof(char), sizeof(char), arch);
				filename += buffer;
			}

			//reading size of file
			size_t fsize;
			fread((char*)&fsize, sizeof(char), sizeof(size_t), arch);

			//reading file
			char *data = new char[fsize];
			for(uint i = 0; i < fsize; i++)
			{
				if(fread(&buffer, sizeof(char), sizeof(char), arch))
					data[i] = buffer;
				else break;
			}
			alldata.push_back(new RAWdata(filename, fsize, data));
		}
	}
	fclose(arch);
	return alldata;
}

std::map<std::string, sf::Texture> Loader::createTextureMap(std::vector<RAWdata*> data)
{
	std::map<std::string, sf::Texture> textures;
	for(auto current : data)
	{
		sf::Texture texture;
		texture.loadFromMemory(current->getData(), current->getFileSize()); 
		texture.setSmooth(true);
		textures.insert(std::pair<std::string, sf::Texture>(current->getFileName(), std::move(texture)));
		delete current;
	}
	return textures;
}

sf::Font Loader::createFont(std::vector<RAWdata*> data)
{
	sf::Font font;
	font.loadFromMemory(data[0]->getData(), data[0]->getFileSize());
	return font;
}
