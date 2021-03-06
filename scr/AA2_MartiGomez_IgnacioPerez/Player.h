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
	bool jusDamaged;
	clock_t timer;
	
	//ATRIBUTOS 
	int vida;
	int playerX;
	int playerY;
	int counterRight;
	int counterLeft;
	int counterUp;
	int counterDown;


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
	void reciveDmg();

	void draw() override;
	void update() override;

};

