#pragma once
#include "IView.h"
#include "Presenter.h"
class View: public IView
{
	Presenter* m_presenter;
	std::map<WeaponType, Weapon*> m_weaponMenuItems;
	void showMainMenu();
	void runOptions(const char* option, bool& exitCondition);
public:
	View();
	~View();
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showMenuToTakeAWeapon();
	void setWeaponMenuItems(const std::map<WeaponType, Weapon*>& items) override;
	void selectWeapon(const char* option, bool& isValidOption);

};

