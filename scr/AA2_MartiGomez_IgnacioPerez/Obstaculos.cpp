#include "stdafx.h"
#include "Obstaculos.h"


Obstaculos::Obstaculos()
{
}

Obstaculos::Obstaculos(tipoObj::tipo tip, int x, int y):
	type(tip),
	doDmg(false),
	seDestruira(false)	,
	isDestruct(false)
{
	pos[0]= x ;
	pos[1]=y;
	//Creacion de los rectangulos de los items
	if (tip == tipoObj::tipo::DEST)
	{
		sprite.x = (x * SPRITEWIDTH);
		sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = SPRITEWIDTH;
		rect.y = 0;
		objeto = ITEMS;
	}
	else if (tip == tipoObj::tipo::NODEST)
	{
		sprite.x = (x * SPRITEWIDTH);
		sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = 0;
		objeto = ITEMS;
	}
	else if (tip == tipoObj::tipo::NONE)
	{
		objeto = ITEMS;
		
	}
	else if (tip == tipoObj::tipo::BOMB)
	{
		sprite.x = (x* SPRITEWIDTH);
		sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		
	}
}

void Obstaculos::draw()
{		
	//Pusheamos OBJETOS al MAPA	
		Renderer::Instance()->PushSprite(objeto, rect, sprite);
}

void Obstaculos::update()
{
	
	if (type == tipoObj::tipo::BOMB)
	{		
		sprite.x = (pos[0]* SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}		
		if (bomba->existe) 
		{
			bomba->update(rect.x, rect.y, objeto, 0,seDestruira, isDestruct);
			if ((rect.x == -1) && (rect.y == -1))
			{
				rect.x = rect.y = 0;
				type = tipoObj::tipo::NONE;
				objeto = TRANSPARENTE;
			}
		}
		
	}
	else if (type == tipoObj::tipo::ARRIBA1)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y,objeto, 1, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::ARRIBA2)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 5, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::DERECHA1)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 2, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::DERECHA2)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 3, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::IZQUIERDA1)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 2, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::IZQUIERDA2)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 4, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::ABAJO1)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto,1, seDestruira, isDestruct);
	}
	else if (type == tipoObj::tipo::ABAJO2)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 6, seDestruira, isDestruct);
	}
	else if ((type == tipoObj::tipo::DEST) && (seDestruira == true))
	{
		
		if (bomba == nullptr)
		{
			bomba = new Bomb(sprite.x / SPRITEHEIGHT, sprite.y / SPRITEHEIGHT);
		}
		bomba->update(rect.x, rect.y, objeto, 7, seDestruira, isDestruct);
		rect.x = SPRITEWIDTH;
		rect.y = 0;
		
		
	}
	else if (type == tipoObj::tipo::NONE)
	{
		sprite.x = (pos[0] * SPRITEWIDTH);
		sprite.y = (pos[1] * SPRITEHEIGHT) + (SPRITEZ);
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		rect.x = 0;
		rect.y = SPRITEHEIGHT;
		objeto = TRANSPARENTE;
	}
	if (isDestruct == true)
	{
		type = tipoObj::tipo::NONE;
		bomba = nullptr;
	}
	if (objeto == EXPLOSION)
	{
		doDmg = true;
	}
	else
	{
		doDmg = false;
	}	
}
Obstaculos::~Obstaculos()
{
}
