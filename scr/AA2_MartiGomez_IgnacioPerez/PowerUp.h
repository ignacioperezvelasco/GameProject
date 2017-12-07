#pragma once
#include "MapObject.h"
class PowerUp:public MapObject
{
public:
	enum type{Casc,Patins};

	type tipo;
	PowerUp();
	~PowerUp();

	void draw();
	void update();
};

