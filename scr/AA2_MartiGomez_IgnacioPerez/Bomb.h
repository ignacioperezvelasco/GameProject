#pragma once
#include "Player.h"
#include "MapObject.h"

class Bomb :public MapObject
{
	public:
	//ATRIBUTOS
	float cooldown;

	//CONSTRUCTOR
	Bomb(int positionPlayerX, int positionPlayerY);

	//FUNCIONES
	void explotarBomba();
	void draw();
	void update();

	//DESCTRUCTOR
	~Bomb();
};

