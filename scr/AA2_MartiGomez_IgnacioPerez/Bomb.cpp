#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb()
{}

Bomb::Bomb(int x,int y)
{
	sprite.x = ( x* SPRITEWIDTH);
	sprite.y = (y * SPRITEHEIGHT) + (SPRITEZ);
	sprite.w = rect.w = SPRITEWIDTH;
	sprite.h = rect.h = SPRITEHEIGHT;
	rect.x = 0;
	rect.y = SPRITEHEIGHT;
	timer = clock();
	existe = true;
}

void Bomb::draw() 
{
}

void Bomb::update(int &x, int &y, std::string &nombreImg,int indicador, bool &dest, bool &acabado)
{	
	//centroBomba
	if (indicador == 0) {
		nombreImg = ITEMS;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = 0;
			nombreImg = EXPLOSION;
			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//BombaArriba Y ABAJO
	else if (indicador == 1)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT*6;
			nombreImg = EXPLOSION;
			
			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//bomba izq y derech
	else if (indicador == 2)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT * 5;
			nombreImg = EXPLOSION;

			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//bomba puntaderech
	else if (indicador == 3)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT * 2;
			nombreImg = EXPLOSION;

			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//Bomba puntaizq
	else if (indicador == 4)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT ;
			nombreImg = EXPLOSION;

			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//bombapuntaarib
	else if (indicador == 5)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT * 3;
			nombreImg = EXPLOSION;

			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//bomba puntaabajo
	else if (indicador == 6)
	{
		nombreImg = TRANSPARENTE;
		x = 0;
		y = SPRITEHEIGHT;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			x = 0;
			y = SPRITEHEIGHT * 4;
			nombreImg = EXPLOSION;

			if (clock() - timer >= CLOCKS_PER_SEC * 2)
			{
				x = SPRITEWIDTH;
				if (clock() - timer >= CLOCKS_PER_SEC * 3)
				{
					x = 2 * SPRITEWIDTH;
					if (clock() - timer >= CLOCKS_PER_SEC * 4)
					{
						x = 3 * SPRITEWIDTH;
						if (clock() - timer >= CLOCKS_PER_SEC * 5)
						{
							nombreImg = TRANSPARENTE;
							x = -1;
							y = -1;
							existe = false;

						}
					}
				}
			}
		}
	}
	//destruyendo
	else if (indicador == 7)
	{
		nombreImg = ITEMS;
		rect.x = 0;
		rect.y = SPRITEWIDTH;
		if (clock() - timer >= CLOCKS_PER_SEC * 1)
		{
			rect.x = 2 * SPRITEWIDTH;
			if (clock() - timer >= CLOCKS_PER_SEC * 5)
			{
				nombreImg = TRANSPARENTE;
				rect.x = rect.y = 0;
				dest = false;
				acabado = true;
				
			}
		}
	}
}

Bomb::~Bomb()
{
}
