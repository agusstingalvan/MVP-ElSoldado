#pragma once
#include <map>;

class Weapon;
enum class WeaponType { Revolver = 1, Rifle, Shotgun };
class WeaponFactory
{
public:
	WeaponFactory();
	~WeaponFactory() = default;
	static Weapon* GetWeapon(WeaponType weaponSelected);
	static std::map<WeaponType, Weapon*> GetWeaponList();
};

