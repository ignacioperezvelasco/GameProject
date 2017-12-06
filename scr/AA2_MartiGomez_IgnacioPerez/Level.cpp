#include "stdafx.h"
#include "Level.h"


Level::Level()
{
}

Level::Level(int num):Escena::Escena(SCREEN_WIDTH, SCREEN_HEIGHT)
{
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG + "bgGame.jpg");
	Background = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

void Level::draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(MENU_BG, Background);
	Renderer::Instance()->Render();

}
void Level::update()
{}
void Level::eHandler() 
{}

Level::~Level()
{}
