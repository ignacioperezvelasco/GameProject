#pragma once
#include "Escena.h"
class Level:public Escena
{
public:

	//Constructores
	Level();
	Level(int num);

	void draw();
	void update();
	void eHandler();

	//Atributos
	SDL_Rect Background;

	//Destructores
	~Level();
};

