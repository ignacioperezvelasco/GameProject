#pragma once
#include "MapObject.h"
#include "Renderer.h"
#include "Bomb.h"
class Player:public MapObject
{
private:
	SDL_Texture * playerTexture;
	SDL_Rect playerRect, playerPosition;
	int textwidth, textheigh, framewidth, frameheigh;
	Renderer myRenderer;
	std::string id;
public:
	


	Player(int numPlayer,Renderer Rend);
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

	void draw();
	void update();

};

