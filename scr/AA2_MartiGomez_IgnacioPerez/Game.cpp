#include "stdafx.h"
#include "Game.h"
#include "Escena.h"
#include "Menu.h"
#include "Level.h"
#include "Ranking.h"

Game::Game():EscenaViviente(escenaa::escenagame::MenuEscena), escena(nullptr)
{
	escena = new Menu();
}

Game::~Game()
{
}

void Game::update()
{
	//BUCLE INFINITO HASTA QUE EL JUGADOR SALGA
	while (EscenaViviente != escenaa::escenagame::ExitEscena)
	{
		escena->draw();
		escena->update();
		escena->eHandler();

		if (escenaEscena::Estado::Playing)
		{

		}
		else if (escenaEscena::Estado::Level1)
		{

		}
		else if (escenaEscena::Estado::Level2)
		{

		}
		else if (escenaEscena::Estado::RankingEscena)
		{

		}
		else if (escenaEscena::Estado::Exit)
		{

		}

	}
}
