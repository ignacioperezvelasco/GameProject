#pragma once
#include "MapObject.h"
#include "Bomb.h"
class Player:public MapObject
{
	
	
public:
	Player(int numPlayer);
	~Player();
	//atributos
	int identificador;
	int vida;
	int punts;
	bool puedoPlantar;
	Bomb *myBomb;
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

};

