#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include <vector>


Player::Player()
{
	vida = 3;
	punts=0;
	patins = false;
	casc = false;
	position[0]=0;
	position[1] = 0;
}

void Player::move(int input) 
{
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

void Player::MapObject::draw() 
{

}

Player::~Player()
{
}
