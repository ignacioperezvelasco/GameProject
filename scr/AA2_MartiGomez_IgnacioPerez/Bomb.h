#pragma once
#include "stdafx.h"
#include "MapObject.h"
#include <ctime>
#include <string>
#include <iostream>
#include "Player.h"
#include "Constants.h"
class Bomb:public MapObject
{
	public:
	Bomb();
	Bomb(int x,int y);
	int tiempo;
	bool existe;
	clock_t timer;
	///////////////////
	bool explotarBomba;

	void draw();
	void update(int &x, int &y, std::string &nombreImg,int indicador, bool &dest, bool &acabado);

	~Bomb();
};

