#pragma once
#include "Escena.h"
#include "Menu.h"
#include "Level.h"
#include "Ranking.h"

namespace escenaa {
	enum escenagame { MenuEscena, Play, RankingEscena, ExitEscena };
}
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
	escenaa::escenagame EscenaViviente;
	Escena *escena;

};