#pragma once
#include <SDL_render.h>

class MapObject
{
public:
	int position[2];
	SDL_Rect sprite;
	void draw();
	void update();
	MapObject();
	~MapObject();
};

