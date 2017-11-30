#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include <vector>


Player::Player(int numPlayer):
	identificador(numPlayer),
	vida(3),
	punts(0),
	patins(false),
	casc(false),
	myBomb(nullptr)
{	
	if (identificador == 1) {
		position[0] = 0;
		position[1] = 0;
	}
	else if (identificador == 2)
	{
		position[0] = 10;
		position[1] = 10;
	}
}

void Player::moveup() 
{
	position[1]++;
}
void Player::movedown() 
{
	position[1]--;
}
void Player::moveright() 
{
	position[0]++;
}
void Player::moveleft() 
{
	position[0]--;
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

void MapObject::draw()
{
	
}

Player::~Player()
{
}
