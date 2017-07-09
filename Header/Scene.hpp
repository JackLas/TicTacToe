#ifndef SCENE_H
#define SCENE_H

#include <SFML\Graphics.hpp>

class Scene
{
protected:
public:
	enum sceneID
	{
		ID_NULL,
		IDGameScene,
		IDMainMenuScene,
	};

	Scene(){};
	virtual ~Scene(){};
	virtual sceneID show() = 0;
};

#endif //SCENE_H