#pragma once
#include "MapObject.h"
#include "Renderer.h"
#include <iostream>
#include <ctime>
#include "Bomb.h"
#include "Constants.h"

 namespace tipoObj {
	enum tipo { DEST, NODEST,NONE, PLAYER, BOMB, ARRIBA1,ARRIBA2,DERECHA1,DERECHA2,IZQUIERDA1,IZQUIERDA2,ABAJO1,ABAJO2};
}

class Obstaculos :public MapObject
{
private:

	int tiempo;
	clock_t timer;
	int pos[2];
	
	Bomb* bomba;
	std::string objeto;
	

public:
	bool isDestruct;
	bool seDestruira;
	bool doDmg;
	Obstaculos();
	tipoObj::tipo type;
	Obstaculos(tipoObj::tipo tip,int x, int y);

	void draw();
	void update();

	~Obstaculos();
};

