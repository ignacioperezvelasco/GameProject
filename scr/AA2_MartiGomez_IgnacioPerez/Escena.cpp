#include "stdafx.h"
#include "Escena.h"
#include <iostream>

Escena::Escena() {}
Escena::Escena(int, int): estadoactual(escenaEscena::Estado::Playing), Background({ 0,0,0,0 })
{
	/*Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG + "bgGame.jpg");
	Background = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };*/
}

Escena::~Escena()
{
}

void Escena::draw()
{
	//Renderer::Instance()->PushImage(MENU_BG, Background);
}
