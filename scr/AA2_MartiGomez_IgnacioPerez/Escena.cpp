#include "stdafx.h"
#include "Escena.h"
#include <iostream>

Escena::Escena() {}
Escena::Escena(int height, int width) : estadoactual(Estado::Playing), Background({ 0,0,0,0 })
{
	//Renderer::Instance()->LoadTexture(BG, "PATH");
	Background = SDL_Rect{ 0, 0, width, height };
}

/*void Escena::draw() 
{
	
		std::cout << "ESCENA" << std::endl;
	
}

void Escena::update() {}

void Escena::eHandler() {}
*/
Escena::~Escena()
{
}
