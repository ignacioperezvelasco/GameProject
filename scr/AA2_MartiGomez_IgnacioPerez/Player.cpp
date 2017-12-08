#include "stdafx.h"
#include "Player.h"

Player::Player(int numPlayer, int playerX1, int playerY1, int playerX2, int playerY2):
	identificador(numPlayer),
	punts(0),
	patins(false),
	casc(false),
	myBomb(nullptr)
{	
	if (identificador == 1) {

		Renderer::Instance()->LoadTexture(PLAYER1, PATH_IMG + "player1.png");
	}
	else if (identificador == 2)
	{	
		Renderer::Instance()->LoadTexture(PLAYER2, PATH_IMG + "player2.png");
	}

	framewidth = textwidth / 3;
	frameheigh = textheigh / 4;
	playerRect.x = framewidth*2;
	playerRect.y = frameheigh*2;
}

void Player::moveup() 
{
	playerPosition.y++;
}

void Player::movedown() 
{
	playerPosition.y--;
}

void Player::moveright() 
{
	playerPosition.x++;
}

void Player::moveleft() 
{
	playerPosition.x--;
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
	Renderer::Instance()->PushSprite(PLAYER1, playerRect, playerPosition);

	//Renderer::Instance()->PushSprite(PLAYER2, playerRect, playerPosition);
}

void Player::update() {}

Player::~Player()
{
}
