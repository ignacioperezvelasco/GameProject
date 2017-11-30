#pragma once
#include <SDL_render.h>
enum Estado {Playing, Level1, Level2, Ranking, Exit};

class Escena
{
public:

	//Contructor
	Escena(int height, int width);

	//Desctructor
	~Escena();

	//Atributos
	Estado estadoactual;

	//Funciones
	virtual void draw();
	virtual void update();
	virtual void eHandler();

	//Atributos
	private:
		SDL_Rect Background;
};

