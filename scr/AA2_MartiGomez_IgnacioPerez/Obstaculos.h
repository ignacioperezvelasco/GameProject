#pragma once
#include "MapObject.h"
#include "Renderer.h"
#include <iostream>
#include "Constants.h"

 namespace tipoObj {
	enum tipo { DEST, NODEST,NONE, PLAYER };
}

class Obstaculos :public MapObject
{
private:
	bool isDestruct;
public:
	Obstaculos();
	tipoObj::tipo type;
	Obstaculos(tipoObj::tipo tip,int x, int y);

	void draw();
	void update();

	~Obstaculos();
};

