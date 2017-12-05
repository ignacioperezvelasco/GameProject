#pragma once
#include "Escena.h"
class Ranking:public Escena
{
public:
	//Atributos
	int Player[2];
	int boto_tornar;

	//Constructor
	Ranking();
	void draw();
	void update();
	void eHandler();

	//Destructor
	~Ranking();
};

