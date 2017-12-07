#pragma once
#include <SDL_render.h>
#include <string>
class MapObject
{
public:

	//Atributos que cede a sus hijos
	int position[2];
	std::string id;
	SDL_Rect sprite;
	SDL_Rect rect;


	//Funciones
	virtual void draw();
	virtual void update();

	//Constructores
	MapObject();
	~MapObject();
};

