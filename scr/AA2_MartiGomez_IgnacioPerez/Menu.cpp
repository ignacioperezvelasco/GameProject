#include "stdafx.h"
#include "Menu.h"

Menu::Menu() :
	Escena::Escena(SCREEN_WIDTH, SCREEN_HEIGHT), 
	isrunning(true)
{
	estadoactual = escenaEscena::Estado::Menu;
	//Fondo
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG + "bgGame.jpg");
	Background = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Estructura de fuente (Types.h)
	Font f;
	f.id = SAIYAN_80;
	f.path = PATH_FONT + "saiyan.ttf";
	f.size = 80;

	//Instanciamos la fuente en renderer
	Renderer::Instance()->LoadFont(f);

	//Recogemos las proporciones (Width & Height de la fuente)
	//Vector2 textsize = Renderer::Instance()->GetTextureSize(f.id);

	//Play1
	Text play1;
	play1.id = MENU_TEXT_BUTTON_PLAY;
	play1.text = "Play Level A";
	play1.color = Color{ 0,0,0,0 };
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTextureText(f.id, play1);
	Vector2 play1Size = Renderer::Instance()->GetTextureSize(play1.id);
	play1.w = play1Size.x;
	play1.h = play1Size.y;
	
	//Play2
	Text play2;
	play2.id = MENU_TEXT_BUTTON_PLAY2;
	play2.text = "Play Level B";
	play2.color = Color{ 0,0,0,0 };
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTextureText(f.id, play2);
	Vector2 play2Size = Renderer::Instance()->GetTextureSize(play2.id);
	play2.w = play1Size.x;
	play2.h = play1Size.y;

	//Ranking
	Text ranking;
	ranking.id = MENU_TEXT_BUTTON_RANKING;
	ranking.text = "Ranking";
	ranking.color = Color{ 0,0,0,0 };
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTextureText(f.id, ranking);
	Vector2 rankingSize = Renderer::Instance()->GetTextureSize(ranking.id);
	ranking.w = rankingSize.x;
	ranking.h = rankingSize.y;

	//Sonido
	Text sonido;
	sonido.id = MENU_TEXT_BUTTON_MUTE;
	sonido.text = "Desactivar Sonido";
	sonido.color = Color{ 0,0,0,0 };
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTextureText(f.id, sonido);
	Vector2 sonidoSize = Renderer::Instance()->GetTextureSize(sonido.id);
	sonido.w = sonidoSize.x;
	sonido.h = sonidoSize.y;

	//Exit
	Text exit;
	exit.id = MENU_TEXT_BUTTON_EXIT;
	exit.text = "Exit";
	exit.color = Color{ 0,0,0,0 };
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTextureText(f.id, exit);
	Vector2 exitSize = Renderer::Instance()->GetTextureSize(exit.id);
	exit.w = exitSize.x;
	exit.h = exitSize.y;

	//SDL_RECT (Todas las opciones (Play1, Play2...)) (FALTAN LAS POSICIONES EN PANTALLA)
	Level1rect = SDL_Rect{ (SCREEN_WIDTH/2) - (play1.w / 2), ((SCREEN_WIDTH / 6)*1) - (play1.h / 2), play1.w, play1.h };
	Level2rect = SDL_Rect{ (SCREEN_WIDTH / 2) - (play2.w / 2), ((SCREEN_WIDTH / 6) * 2) - (play2.h / 2), play2.w, play2.h };
	Rankingrect = SDL_Rect{ (SCREEN_WIDTH / 2) - (ranking.w / 2), ((SCREEN_WIDTH / 6) * 3) - (ranking.h / 2), ranking.w, ranking.h };
	D_Sorect = SDL_Rect{ (SCREEN_WIDTH / 2) - (sonido.w / 2), ((SCREEN_WIDTH / 6) * 4) - (sonido.h / 2), sonido.w, sonido.h };
	Exitrect = SDL_Rect{ (SCREEN_WIDTH / 2) - (exit.w/2), ((SCREEN_WIDTH / 6) * 5) - (exit.h/2), exit.w, exit.h };
	


}

Menu::~Menu()
{
}

void Menu::draw()
{
	Renderer::Instance()->Clear();
	//Dibujar los SDL_RECTS
	Renderer::Instance()->PushImage(MENU_BG, Background);
	Renderer::Instance()->PushImage(MENU_TEXT_BUTTON_PLAY, Level1rect);
	Renderer::Instance()->PushImage(MENU_TEXT_BUTTON_PLAY2, Level2rect);
	Renderer::Instance()->PushImage(MENU_TEXT_BUTTON_RANKING, Rankingrect);
	Renderer::Instance()->PushImage(MENU_TEXT_BUTTON_MUTE, D_Sorect);
	Renderer::Instance()->PushImage(MENU_TEXT_BUTTON_EXIT, Exitrect);
	Renderer::Instance()->Render();
}

void Menu::update()
{
}

void Menu::eHandler()
{
	SDL_Event e;
	while (isrunning)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				//SEGUN DONDE PULSEMOS (X e Y) realizamos alguna acci�n <>
				int positionMouseX, positionMouseY;
				SDL_GetMouseState(&positionMouseX, &positionMouseY);

				if ((positionMouseX < Level1rect.x + Level1rect.w) && (positionMouseX > Level1rect.x) && ((positionMouseY < Level1rect.h + Level1rect.y) && (positionMouseY > Level1rect.y)))
				{
					//std::cout << "HOLA Level1" << std::endl;
					estadoactual = escenaEscena::Estado::Level1;
					isrunning = false;
				}
				else if ((positionMouseX < Level2rect.x + Level2rect.w) && (positionMouseX > Level2rect.x) && ((positionMouseY < Level2rect.h + Level2rect.y) && (positionMouseY > Level2rect.y)))
				{
					//std::cout << "HOLA Level2" << std::endl;
					estadoactual = escenaEscena::Estado::Level2;
					isrunning = false;
				}
				else if ((positionMouseX < Rankingrect.x + Rankingrect.w) && (positionMouseX > Rankingrect.x) && ((positionMouseY < Rankingrect.h + Rankingrect.y) && (positionMouseY > Rankingrect.y)))
				{
					//std::cout << "HOLA Ranking" << std::endl;
					estadoactual = escenaEscena::Estado::RankingEscena;
					isrunning = false;
				}
				else if ((positionMouseX < D_Sorect.x + D_Sorect.w) && (positionMouseX > D_Sorect.x) && ((positionMouseY < D_Sorect.h + D_Sorect.y) && (positionMouseY > D_Sorect.y)))
				{
					//std::cout << "HOLA Sonido" << std::endl;
					estadoactual = escenaEscena::Estado::Mute;
					isrunning = false;
				}
				else if ((positionMouseX < Exitrect.x + Exitrect.w) && (positionMouseX > Exitrect.x) && ((positionMouseY < Exitrect.h + Exitrect.y) && (positionMouseY > Exitrect.y)))
				{
					//std::cout << "HOLA Exit" << std::endl;
					estadoactual = escenaEscena::Estado::Exit;
					isrunning = false;
				}
			
			}

		}
	}
}
