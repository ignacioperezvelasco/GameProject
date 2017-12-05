#pragma once
#include "Escena.h"
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