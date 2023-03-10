#pragma once
#include "Weapon.h";
class Shotgun: public Weapon
{
public:
	Shotgun();
	const char* shoot() override;
};

