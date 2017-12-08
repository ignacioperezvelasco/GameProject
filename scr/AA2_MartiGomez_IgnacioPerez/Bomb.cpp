#include "stdafx.h"
#include "Bomb.h"


Bomb::Bomb(int positionPlayerX, int positionPlayerY)
{
	sprite.x = (positionPlayerX * SPRITEWIDTH);
	sprite.y = (positionPlayerY * SPRITEHEIGHT) + (SPRITEZ);
	sprite.w = rect.w = SPRITEWIDTH;
	sprite.h = rect.h = SPRITEHEIGHT;
	rect.x = SPRITEWIDTH;
	rect.y = 0;
}

void Bomb::explotarBomba()
{
	//hacer countdown;
	//avisarmapa
	//Bomb::~Bomb();
}

void Bomb::draw()
{
	Renderer::Instance()->PushSprite(ITEMS, rect, sprite);
}

void Bomb::update()
{
}

Bomb::~Bomb()
{
}
