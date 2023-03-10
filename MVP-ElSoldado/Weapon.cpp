#include "Weapon.h"
#include "WeaponFactory.h"



Weapon* Weapon::pickup(int weaponSelected)
{
	return WeaponFactory::GetWeapon((WeaponType)weaponSelected);
}

std::map<WeaponType, Weapon*> Weapon::getConstants()
{
	return WeaponFactory::GetWeaponList();
}

const char* Weapon::getName() const {
	return m_name;
}