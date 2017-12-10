#include "stdafx.h"
#include "Player.h"

Player::Player() {}

Player::Player(int numPlayer, int x, int y, int vid):
	vida(vid),
	identificador(numPlayer),
	punts(0),
	patins(false),
	casc(false),
	playerX(x),
	playerY(y),
	puedoPlantar(true),
	jusDamaged(false),
	timer (clock())
{	
	//CONTADORES PARA LOS SPRITES
	counterRight = 0;
	counterLeft = 0;
	counterUp = 0;
	counterDown = 0;

	if (identificador == 1)
	{
		//en el mapa pos
		sprite.x = playerX*SPRITEWIDTH;
		sprite.y = (playerY*SPRITEHEIGHT) + SPRITEZ;
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		//posicion en la imagen
		rect.x = SPRITEWIDTH;
		rect.y = SPRITEHEIGHT*2;
	}

	else if (identificador == 2) {
		sprite.x = playerX*SPRITEWIDTH;
		sprite.y = (playerY*SPRITEHEIGHT) + SPRITEZ;
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
		//posicion en la imagen
		rect.x = SPRITEWIDTH;
		rect.y = SPRITEHEIGHT * 2;
	}
	
}

void Player::moveup() 
{
	sprite.y-= 6;

	//RECTANGULO
	if (counterUp == 0)
	{
		rect.x = SPRITEWIDTH * 0;
		rect.y = SPRITEHEIGHT * 0;
		counterUp++;
	}
	else if (counterUp == 1)
	{
		rect.x = SPRITEWIDTH * 1;
		rect.y = SPRITEHEIGHT * 0;
		counterUp++;
	}
	else
	{
		rect.x = SPRITEWIDTH * 2;
		rect.y = SPRITEHEIGHT * 0;
		counterUp = 0;
	}
}

void Player::movedown() 
{
	sprite.y+= 6;

	//RECTANGULO
	if (counterDown == 0)
	{
		rect.x = SPRITEWIDTH * 0;
		rect.y = SPRITEHEIGHT * 2;
		counterDown++;
	}
	else if (counterDown == 1)
	{
		rect.x = SPRITEWIDTH * 1;
		rect.y = SPRITEHEIGHT * 2;
		counterDown++;
	}
	else
	{
		rect.x = SPRITEWIDTH * 2;
		rect.y = SPRITEHEIGHT * 2;
		counterDown = 0;
	}
}

void Player::moveright() 
{
	sprite.x+= 6;

	//RECTANGULO
	if (counterRight == 0)
	{
		rect.x = SPRITEWIDTH * 0;
		rect.y = SPRITEHEIGHT * 3;
		counterRight++;
	}
	else if(counterRight == 1)
	{
		rect.x = SPRITEWIDTH * 1;
		rect.y = SPRITEHEIGHT * 3;
		counterRight++;
	}
	else
	{
		rect.x = SPRITEWIDTH * 2;
		rect.y = SPRITEHEIGHT * 3;
		counterRight = 0;
	}
}

void Player::moveleft() 
{
	sprite.x-= 6;

	//RECTANGULO
	if (counterLeft == 0)
	{
		rect.x = SPRITEWIDTH * 0;
		rect.y = SPRITEHEIGHT * 1;
		counterLeft++;
	}
	else if (counterLeft == 1)
	{
		rect.x = SPRITEWIDTH * 1;
		rect.y = SPRITEHEIGHT * 1;
		counterLeft++;
	}
	else
	{
		rect.x = SPRITEWIDTH * 2;
		rect.y = SPRITEHEIGHT * 1;
		counterLeft = 0;
	}
}

void Player::plantBomb() 
{
	puedoPlantar = false;
}

void Player::sumarPunts(int a) 
{
	punts += a;
}

void Player::PowerUpPatins() 
{
	patins = true;
	casc = false;
}

void Player::PowerCasc() 
{
	casc = true;
	patins = false;
}

void Player::draw()
{
	if(identificador == 1) 
	{
		Renderer::Instance()->PushSprite(PLAYER1, rect, sprite);
	}
	else if (identificador == 2) 
	{
		Renderer::Instance()->PushSprite(PLAYER2, rect, sprite);
	}
	else 
	{
		throw "error subiendo a renderer Player";
	}

}

void Player::reciveDmg()
{
	if (jusDamaged)
	{
		vida--;
		jusDamaged = true;
	}
	if (clock() - timer >= CLOCKS_PER_SEC * 4)
	{
		jusDamaged = false;
	}
}

void Player::update() {}

Player::~Player()
{
}
