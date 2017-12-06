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

	//Destructores
	~Level();
};

