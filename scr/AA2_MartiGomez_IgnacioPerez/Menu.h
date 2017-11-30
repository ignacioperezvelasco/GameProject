#pragma once
#include "Escena.h"
class Menu:public Escena
{
public:

	//Atributos
	int play1;
	int play2;
	int ranking;
	int menu;

	//Constructor
	Menu();

	//Destructor
	~Menu();

	//Funciones
	void exit();
	void d_volumen();
};

