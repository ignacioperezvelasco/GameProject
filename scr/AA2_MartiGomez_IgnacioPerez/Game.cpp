#include "stdafx.h"
#include <iostream>
#include "Game.h"


Game::Game():
	EscenaViviente(escenaa::escenagame::MenuEscena)
{
	escena = new Menu();
	escena->estadoactual = escenaEscena::Estado::Menu;
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

		switch (escena->estadoactual)
		{
		case escenaEscena::Estado::Level1:
			escena->~Escena();
			escena = new Level(1);
			EscenaViviente = escenaa::escenagame::Play;
			break;
		case escenaEscena::Estado::Level2:
			escena->~Escena();
			escena = new Level(2);
			EscenaViviente = escenaa::escenagame::Play;
			break;
		case escenaEscena::Estado::RankingEscena:
			escena->~Escena();
			escena = new Ranking();
			EscenaViviente = escenaa::escenagame::Play;
			break;
		case escenaEscena::Estado::Playing:
			
			break;
		default:
			break;
		}


		/*
		if (escena->estadoactual== escenaEscena::Estado::Level1)
		{
			escena->~Escena();
			escena = new Level(1);
			EscenaViviente = escenaa::escenagame::Play;
		}
		else if (escenaEscena::Estado::Level2)
		{
			escena->~Escena();
			escena = new Level(2);
			EscenaViviente = escenaa::escenagame::Play;
		}
		else if (escenaEscena::Estado::RankingEscena)
		{
			escena->~Escena();
			escena = new Ranking();
			EscenaViviente = escenaa::escenagame::RankingEscena;
		}
		/*else if (escenaEscena::Estado::Exit)
		{
			escena->~Escena();
			escena = new Exit();
			EscenaViviente = escenaa::escenagame::ExitEscena;
		}*/
		
	}
}
