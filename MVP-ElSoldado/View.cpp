#include <iostream>
#include <windows.h>
#include "View.h"
#include "Weapon.h"


const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opci�n ingresada es inv�lida, por favor reintente.";

View::View() {
	SetConsoleTitleW(L"The Soldier");
	m_presenter = new Presenter(this);
	showMainMenu();
}
View::~View() {
	delete m_presenter;
}

void View::showText(const char* text) {
	std::cout << text << std::endl;
}
void View::showText(const std::string& text) {
	std::cout << text << std::endl;
}


void View::showMainMenu() {
	std::string option;
	bool exitCondition = false;

	do {
		std::system("cls");
		showText("-== Bienvenido al campo de entrenamiento, Soldado ==-");
		showText("�Qu� desea hacer?");
		showText("");
		showText("1- Recoger Arma");
		showText("2- Dejar Arma");
		showText("3- Disparar");
		showText("4- Ver Arma en uso");
		showText("X- Salir");
		std::cin >> option;
		std::system("cls");
		runOptions(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOptions(const char* option, bool& exitCondition) {
	auto str_option = std::string(option);

	if (str_option == "1") {
		showMenuToTakeAWeapon();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		m_presenter->dropCurrentWeapon();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		m_presenter->shoot();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "4")
	{
		m_presenter->seeCurrentWeapon();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "x" || str_option == "X")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

void View::showMenuToTakeAWeapon() {
	std::string optionString = "";
	bool isValidOption = true;

	do {
		std::system("cls");
		showText("Por favor, escoja el arma que desea utilizar:");
		showText("");
		m_presenter->getListOfWeaponMenuItems();


		for (const auto& item : m_weaponMenuItems)
		{
			const auto* weapon = m_weaponMenuItems[item.first];
			std::string weaponName = weapon->getName();
			auto numberOfItem = (int)item.first;
			std::string  str_numberOfItem = std::to_string(numberOfItem);
			std::string menuItem = str_numberOfItem + "- " + weaponName; // constru�mos el �tem/opci�n de men� (por ejemplo: "2- Rifle")
			showText(menuItem.c_str());
		}

		showText("X- Volver atr�s...");
		std::cin >> optionString;
		selectWeapon(optionString.c_str(), isValidOption);
		std::cin.get();
	} while (!isValidOption);
}

void View::setWeaponMenuItems(const std::map<WeaponType, Weapon*>& items)
{
	if (items.empty()) {
		showText("Ups!... parece que no hay armas disponibles por aqu�...");
	}
	else {
		m_weaponMenuItems = items;
	}
}

void View::selectWeapon(const char* option, bool& isValidOption)
{
	try
	{
		int optionInt = std::stoi(option);
		for (const auto& item : m_weaponMenuItems)
		{
			if (optionInt == (int)item.first)
			{
				m_presenter->pickupWeapon(optionInt);
				isValidOption = true;
				std::cin.get();
				break;
			}
			else
			{
				isValidOption = false;
			}
		}
		if (!isValidOption)
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
		}
	}
	catch (std::invalid_argument)
	{
		auto str_option = std::string(option);
		if (str_option == "x" || str_option == "X")
		{
			isValidOption = true;
			std::system("cls");
			showText("Okay, el soldado no recogi� ning�n arma... Volveremos al men� principal.");
			std::cin.get();
		}
		else
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			isValidOption = false;
		}
	}

	showText("");
	showText(ANY_KEY_MESSAGE);
}
