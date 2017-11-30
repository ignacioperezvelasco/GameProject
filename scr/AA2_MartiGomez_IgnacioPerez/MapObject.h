#pragma once
class MapObject
{
public:
	int position[2];

	//Sprite,size...
	virtual void draw();
	virtual void update();
	MapObject();
	~MapObject();
};

