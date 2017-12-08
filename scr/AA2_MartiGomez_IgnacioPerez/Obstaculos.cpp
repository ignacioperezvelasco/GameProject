#include "stdafx.h"
#include "Obstaculos.h"


Obstaculos::Obstaculos()
{
}

Obstaculos::Obstaculos(tipoObj::tipo tip, int x, int y):
	type(tip)	
{
	//Creacion de los rectangulos de los items
	if (tip == tipoObj::tipo::DEST)
	{
		sprite.x = (x * SPRITEWIDTH);
		sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = SPRITEWIDTH;
		rect.y = 0;
	}
	else if (tip == tipoObj::tipo::NODEST)
	{
		sprite.x = (x * SPRITEWIDTH);
		sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = 0;
	}
	else if (tip == tipoObj::tipo::NONE)
	{

	}
}

void Obstaculos::draw()
{		

	//Pusheamos OBJETOS al MAPA
	Renderer::Instance()->PushSprite(ITEMS, rect, sprite);
}

void Obstaculos::update()
{}
Obstaculos::~Obstaculos()
{
}
