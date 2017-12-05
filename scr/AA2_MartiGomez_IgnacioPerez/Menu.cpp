#include "stdafx.h"
#include "Menu.h"

Menu::Menu() :Escena::Escena(720, 704)
{
	
	//Estructura de fuente (Types.h)
	Font f;
	f.id = SAIYAN_80;
	f.path = "../../res/ttf/saiyan.ttf";
	f.size = 80;

	//Instanciamos la fuente en renderer
	Renderer::Instance()->LoadFont(f);

	//Recogemos las proporciones (Width & Height de la fuente)
	Vector2 textsize = Renderer::Instance()->GetTextureSize(f.id);

	//Play1
	Text play1;
	
	play1.id = MENU_TEXT_BUTTON_PLAY;
	play1.text = "Play Level 1";
	play1.color = Color{ 0,0,0,0 };
	play1.w = textsize.x;
	play1.h = textsize.y;
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTexture(f.id, play1.text);

	//Play2
	Text play2;
	play2.id = MENU_TEXT_BUTTON_PLAY2;
	play2.text = "Play Level 2";
	play2.color = Color{ 0,0,0,0 };
	play2.w = textsize.x;
	play2.h = textsize.y;
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTexture(f.id, play2.text);

	//Ranking
	Text ranking;
	ranking.id = MENU_TEXT_BUTTON_RANKING;
	ranking.text = "Ranking";
	ranking.color = Color{ 0,0,0,0 };
	ranking.w = textsize.x;
	ranking.h = textsize.y;
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTexture(f.id, ranking.text);

	//Sonido
	Text sonido;
	sonido.id = MENU_TEXT_BUTTON_MUTE;
	sonido.text = "Desactivar Sonido";
	sonido.color = Color{ 0,0,0,0 };
	sonido.w = textsize.x;
	sonido.h = textsize.y;
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTexture(f.id, sonido.text);

	//Exit
	Text exit;
	exit.id = MENU_TEXT_BUTTON_EXIT;
	exit.text = "Exit";
	exit.color = Color{ 0,0,0,0 };
	exit.w = textsize.x;
	exit.h = textsize.y;
	//Instanciamos las texturas en el renderer
	Renderer::Instance()->LoadTexture(f.id, exit.text);

	//SDL_RECT (Todas las opciones (Play1, Play2...)) (FALTAN LAS POSICIONES EN PANTALLA)
	Level1rect = SDL_Rect{ 0, 0, textsize.x, textsize.y };
	Level2rect = SDL_Rect{ 0, 0, textsize.x, textsize.y };
	Rankingrect = SDL_Rect{ 0, 0, textsize.x, textsize.y };
	D_Sorect = SDL_Rect{ 0, 0, textsize.x, textsize.y };
	Exitrect = SDL_Rect{ 0, 0, textsize.x, textsize.y };
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
	//SDL_Event e;

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
