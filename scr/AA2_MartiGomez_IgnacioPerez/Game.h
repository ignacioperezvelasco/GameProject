#pragma once
#include "Escena.h"

enum escenagame { Menu, Play, Ranking, Exit };
class Game
{
public:

	//Contructor
	Game();

	//Destructor
	~Game();

	//Funciones
	void update();

private:
	//Atributos privados
	escenagame EscenaViviente;
	Escena *escena;

};