#include "WeaponFactory.h"
#include "Weapon.h"
#include "Revolver.h"
#include "Rifle.h"
#include "Shotgun.h"
WeaponFactory::WeaponFactory() = default;

Weapon* WeaponFactory::GetWeapon(WeaponType weaponSelected)
{
	auto weapons = GetWeaponList();
	if (weapons.count(weaponSelected) == 0) {
		return nullptr;
	}
	auto item = weapons[weaponSelected];
	return item;
}

std::map<WeaponType, Weapon*> WeaponFactory::GetWeaponList()
{
	auto shotgun = new Shotgun();
	auto rifle = new Rifle();
	auto revolver = new Revolver();

	return std::map<WeaponType, Weapon*> {
		{WeaponType::Revolver, revolver},
		{ WeaponType::Rifle, rifle },
		{ WeaponType::Shotgun, shotgun }
	};
}
