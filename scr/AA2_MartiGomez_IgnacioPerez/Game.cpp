#include "stdafx.h"
#include "Game.h"
#include "Escena.h"
#include "Menu.h"
#include "Level.h"
#include "Ranking.h"

Game::Game():EscenaViviente(escenagame::Menu), escena(nullptr)
{
	//escena = new Menu();
}

Game::~Game()
{
}

void Game::update()
{
	//BUCLE INFINITO HASTA QUE EL JUGADOR SALGA
}
