#pragma once
#include "stdafx.h"
#include "MapObject.h"
#include "Renderer.h"
#include "Bomb.h"
#include <vector>

class Player:public MapObject
{
private:
	SDL_Rect playerRect, playerPosition;
	std::string id;

public:
	Player();
	Player(int numPlayer, int x, int y, int vid);
	~Player();

	//atributos
	int identificador;
	int punts;
	bool puedoPlantar;
	Bomb *myBomb;

	//ATRIBUTOS STATICOS
	int vida;
	int playerX;
	int playerY;


	//powerUps
	bool patins;
	bool casc;

	//Metodos
	void moveup();
	void movedown();
	void moveright();
	void moveleft();
	void plantBomb(int playerX, int playerY);
	void sumarPunts(int a);
	void PowerUpPatins();
	void PowerCasc();

	void draw();
	void update();

};

