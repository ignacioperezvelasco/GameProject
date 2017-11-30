#include "stdafx.h"
#include "Escena.h"


Escena::Escena(int height, int width) : estadoactual(Estado::Playing), Background({ 0,0,0,0 })
{
	//Renderer::Instance()->LoadTexture(BG, "PATH");
	Background = SDL_Rect{ 0, 0, width, height };
}

Escena::~Escena()
{
}
