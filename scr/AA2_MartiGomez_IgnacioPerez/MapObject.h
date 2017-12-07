#pragma once
#include <SDL_render.h>

class MapObject
{
public:

	//Atributos que cede a sus hijos
	int position[2];
	SDL_Rect sprite;


	//Funciones
	virtual void draw();
	virtual void update();

	//Constructores
	MapObject();
	~MapObject();
};

