#pragma once

#include <map>
#include "WeaponFactory.h"
class Weapon
{
	friend class Shotgun;
	friend class Rifle;
	friend class Revolver;
private:
	const char* m_name;
public: 
	virtual ~Weapon() = default;
	virtual const char* shoot() = 0;

	/*La definición "const" al final de la firma de la función 
	indica que esta función no modificará el objeto "Weapon" actual.*/
	static Weapon* pickup(int weaponSelected);
	static std::map<WeaponType, Weapon*> getConstants();
	const char* getName() const;
};

