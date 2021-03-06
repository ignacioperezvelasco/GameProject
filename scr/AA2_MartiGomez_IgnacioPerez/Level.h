#pragma once
#include "Escena.h"
#include "Obstaculos.h"
#include "Bomb.h"
#include "Player.h"
#include <iostream>
#include <string> 
#include <time.h>

//RAPIDXML
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream> 

class Level:public Escena
{
public:


	clock_t lastTime;
	float timeDown;
	float deltaTime;

	//Constructores
	Level();
	Level(int num);

	void draw();
	void update();
	void eHandler();

	//Atributos
	SDL_Rect Background;
	int filas; 
	int columnas;
	float tiempo;

	//CONVERSION DEL TIEMPO y SU DISMINUCION
	int min;
	int secs;
	//float deltaTime;*/
	

	//HUD
	SDL_Rect score1;
	SDL_Rect score2;
	SDL_Rect timeRect;
	SDL_Rect vida1;
	SDL_Rect vida2;

	//TEXTOS
	Text scorePlayer1;
	Text scorePlayer2;
	Text lifesPlayer1;
	Text lifesPlayer2;
	Text time;
	Font f;

	//ARRAY MAPA
	Obstaculos *mapaObstaculos[15][13];

	//Jugadores
	Player firstPlayer;
	Bomb firstPlayerBomb;
	int timerBomba;
	Player secondPlayer;
	Bomb secondPlayerBomb;

	//Array de ints para comprobar
	int mapa[15][13];

	//Destructores
	~Level();
};

