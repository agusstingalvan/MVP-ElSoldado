#pragma once
class Weapon;

class Soldier
{
public:
	bool hasWeapon() const;
	const char* shoot();
	const char* dropCurrentWeapon();
	const char* seeCurrentWeapon() const;
	const char* pickupWeapon(int option);
private:
	Weapon* m_weapon;
};

