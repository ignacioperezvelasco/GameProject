#pragma once
#include "stdafx.h"
#include "Renderer.h"
#include "Types.h"

namespace escenaEscena {
	enum Estado { Playing, Level1, Level2, RankingEscena, Exit };
}

class Escena
{
public:
	Escena();
	//Contructor
	Escena(int, int);

	//Desctructor
	~Escena();

	//Atributos
	escenaEscena::Estado estadoactual;

	//Funciones
	virtual void draw();
	virtual void update()=0;
	virtual void eHandler()=0;

	//Atributos
	private:
		SDL_Rect Background;		
};

