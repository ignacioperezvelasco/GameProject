#pragma once
#include "Renderer.h"
#include "Types.h"

enum Estado {Playing, Level1, Level2, RankingEscena, Exit};

class Escena
{
public:
	Escena();
	//Contructor
	 Escena(int height, int width);

	//Desctructor
	~Escena();

	//Atributos
	Estado estadoactual;

	//Funciones
	virtual void draw()=0;
	virtual void update()=0;
	virtual void eHandler()=0;

	//Atributos
	private:
		SDL_Rect Background;		
};

