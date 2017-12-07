#include "stdafx.h"
#include "Obstaculos.h"


Obstaculos::Obstaculos()
{
}

Obstaculos::Obstaculos(tipoObj::tipo tip, int x, int y):
	type(tip)	
{
	sprite.x =  48;
	sprite.y =  48;
	sprite.h = rect.h = sprite.w = rect.w = 48;

	

	Obstaculos::draw();

}

void Obstaculos::draw()
{
	if (type == tipoObj::tipo::DEST)
	{			
		Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "bgCastle.jpg");
		Renderer::Instance()->PushSprite(ITEMS, rect, sprite);
	}
}

void Obstaculos::update()
{}
Obstaculos::~Obstaculos()
{
}
