#include "stdafx.h"
#include "Bomb.h"
#include "Player.h"


Bomb::Bomb(int positionPlayer[2])
{
	position[0] = positionPlayer[0];
	position[1] = positionPlayer[1];
	tiempo = 5;
	explotarBomba();
}

void Bomb::explotarBomba()
{
	//hacer countdown;
	//avisarmapa
	//Bomb::~Bomb();
}

Bomb::~Bomb()
{
}
