#pragma once
#include "IView.h"
#include "Soldier.h"
class Presenter
{
	IView *m_view = nullptr;
	Soldier* m_soldier = nullptr;
public:
	explicit Presenter(IView *view);
	~Presenter();
	void pickupWeapon(int option);
	void getListOfWeaponMenuItems();
	void shoot();
	void seeCurrentWeapon();
	void dropCurrentWeapon();
};

