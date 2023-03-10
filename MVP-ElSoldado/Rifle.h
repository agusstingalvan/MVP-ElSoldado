#pragma once
#include "Weapon.h"
class Rifle: public Weapon
{
public:
	Rifle();
	const char* shoot() override;
};

