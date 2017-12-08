#include "stdafx.h"
#include "Player.h"

Player::Player() {}

Player::Player(int numPlayer, int x, int y, int vid):
	vida(vid),
	identificador(numPlayer),
	punts(0),
	patins(false),
	casc(false),
	myBomb(nullptr),
	playerX(x),
	playerY(y)
{	


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
}

void Player::movedown() 
{
	sprite.y+= 6;
}

void Player::moveright() 
{
	sprite.x+= 6;
}

void Player::moveleft() 
{
	sprite.x-= 6;
}

void Player::plantBomb() 
{
	myBomb= new Bomb(position);
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

void Player::update() {}

Player::~Player()
{
}
