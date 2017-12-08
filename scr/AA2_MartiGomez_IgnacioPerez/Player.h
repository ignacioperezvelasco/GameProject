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
	int textwidth, textheigh, framewidth, frameheigh;
	std::string id;

public:
	
	Player(int numPlayer, int playerX1, int playerY1, int playerX2, int playerY2);
	~Player();

	//atributos
	int identificador;
	int punts;
	bool puedoPlantar;
	Bomb *myBomb;

	//ATRIBUTOS STATICOS
	int vida;
	int playerX1;
	int playerY1;
	int playerX2;
	int playerY2;

	//powerUps
	bool patins;
	bool casc;

	//Metodos
	void moveup();
	void movedown();
	void moveright();
	void moveleft();
	void plantBomb();
	void sumarPunts(int a);
	void PowerUpPatins();
	void PowerCasc();

	void draw();
	void update();

};

