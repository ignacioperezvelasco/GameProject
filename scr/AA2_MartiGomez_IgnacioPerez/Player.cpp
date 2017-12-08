#include "stdafx.h"
#include "Player.h"

Player::Player() {}

Player::Player(int numPlayer):
	identificador(numPlayer),
	punts(0),
	patins(false),
	casc(false),
	myBomb(nullptr)
{	
	/*
	framewidth = textwidth / 3;
	frameheigh = textheigh / 4;
	playerRect.x = framewidth*2;
	playerRect.y = frameheigh*2;*/

	if (identificador == 1)
	{
		//en el mapa pos
		sprite.x = SPRITEWIDTH;
		sprite.y = SPRITEHEIGHT + SPRITEZ;
		sprite.w = rect.w = SPRITEWIDTH;
		sprite.h = rect.h = SPRITEHEIGHT;
			//posicion en la imagen
		rect.x = SPRITEWIDTH;
		rect.y = SPRITEHEIGHT*2;
	}
	/*else if (identificador == 2) {
		rect.x = SPRITEWIDTH;
		rect.y = 0;
	}*/
	
}

void Player::moveup() 
{
	sprite.y-= SPRITEWIDTH;
}

void Player::movedown() 
{
	sprite.y+= SPRITEWIDTH;
}

void Player::moveright() 
{
	sprite.x+= SPRITEWIDTH;
}

void Player::moveleft() 
{
	sprite.x-= SPRITEWIDTH;
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
	else if (identificador == 2) {
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
