#pragma once
#include "Weapon.h"
class Revolver: public Weapon
{
public: 
	Revolver();
	const char* shoot() override;
};

