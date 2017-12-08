#pragma once
#include "Escena.h"
#include "Obstaculos.h"
#include "Player.h"
#include <iostream>
#include <string> 

//RAPIDXML
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream> 

class Level:public Escena
{
public:

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
	int tiempo;

	//ARRAY MAPA
	Obstaculos *mapaObstaculos[15][13];

	//Array de ints para comprobar
	int mapa[15][13];

	//Destructores
	~Level();
};

