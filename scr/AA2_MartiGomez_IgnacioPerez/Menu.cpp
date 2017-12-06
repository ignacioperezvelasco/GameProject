#include "stdafx.h"
#include "Menu.h"

Menu::Menu() :Escena::Escena(SCREEN_WIDTH, SCREEN_HEIGHT)
{
	
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
	Level1rect = SDL_Rect{ 400 - (play1.w / 2), 100 - (play1.h / 2), play1.w, play1.h };
	Level2rect = SDL_Rect{ 400 - (play2.w / 2), 200 - (play2.h / 2), play2.w, play2.h };
	Rankingrect = SDL_Rect{ 400 - (ranking.w / 2), 300 - (ranking.h / 2), ranking.w, ranking.h };
	D_Sorect = SDL_Rect{ 400 - (sonido.w / 2), 400 - (sonido.h / 2), sonido.w, sonido.h };
	Exitrect = SDL_Rect{ 400 - (exit.w/2), 500 - (exit.h/2), exit.w, exit.h };
}

Menu::~Menu()
{
}

void Menu::draw()
{
	Renderer::Instance()->Clear();
	//Dibujar los SDL_RECTS
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

	/*switch (e.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			//SEGUN DONDE PULSEMOS (X e Y) realizamos alguna acción
			if ()
			{

			}
			else if ()
			{

			}
			else if ()
			{

			}
			else if ()
			{

			}
			else if ()
			{

			}

		break;
		default:
		break;
	}*/
}
