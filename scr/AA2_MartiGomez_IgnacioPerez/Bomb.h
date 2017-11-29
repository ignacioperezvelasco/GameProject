#pragma once
class Bomb
{
	public:
	Bomb(int positionPlayer[2]);
	int position[2];
	int tiempo;
	
	///////////////////
	void explotarBomba();
	~Bomb();
};

