#pragma once
#include "MapObject.h"
class PowerUp:public MapObject
{
public:
	enum type{Casc,Patins};

	PowerUp();
	~PowerUp();
};

