#pragma once
#include "Bomb.h"
class Player
{
	
	
public:
	Player();
	~Player();
	//atributos
	int identificador;
	int vida;
	int position[2];
	int punts;
	bool puedoPlantar;
	Bomb *myBomb;
	//powerUps
	bool patins;
	bool casc;

	//Metodos
	void move(int input);
	void plantBomb();
	void sumarPunts(int a);
	void PowerUpPatins();
	void PowerCasc();
};

