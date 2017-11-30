#pragma once
class MapObject
{
public:
	int position[2];
	//SDLRects 
	//Sprite,size...
	void draw();
	void update();
	MapObject();
	~MapObject();
};

