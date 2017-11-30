#pragma once
#include "Escena.h"
class Menu:public Escena
{
public:

	//Atributos
	SDL_Rect Level1rect;
	SDL_Rect Level2rect;
	SDL_Rect Rankingrect;
	SDL_Rect Exitrect;
	SDL_Rect D_Sorect;

	//Constructor
	Menu();

	//Destructor
	~Menu();

	//Funciones
	void cambioEscena();
	void exit();
	void d_volumen();

	//Funciones heredades
	void draw();
	void update();
	void eHandler();
};

