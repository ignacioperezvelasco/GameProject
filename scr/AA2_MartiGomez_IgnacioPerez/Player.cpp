#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include <vector>


Player::Player(int numPlayer,Renderer rend):
	identificador(numPlayer),
	vida(3),
	punts(0),
	patins(false),
	casc(false),
	myBomb(nullptr),
	myRenderer(rend)
{	
	if (identificador == 1) {
		playerPosition.x = 0;	//Se ha de cambiar segun xml
		playerPosition.y = 0;	//Se ha de cambiar segun xml
		id = "player1";
		Renderer::Instance()->LoadTexture(id, "../../res/ing/player1.png");
		SDL_QueryTexture(playerTexture, NULL, NULL, &textwidth, &textheigh);
		
	}
	else if (identificador == 2)
	{
		playerPosition.x = 0;	//Se ha de cambiar segun xml
		playerPosition.y = 0;	//Se ha de cambiar segun xml
		id = "player2";
		Renderer::Instance()->LoadTexture(id, "../../res/ing/player2.png");
		SDL_QueryTexture(playerTexture, NULL, NULL, &textwidth, &textheigh);
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

		Renderer::Instance()->PushSprite(id, playerRect, playerPosition);

}

void Player::update() {}

Player::~Player()
{
}
