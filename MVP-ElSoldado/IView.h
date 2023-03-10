#pragma once
#include <string>;
#include <map>;

class Weapon;
enum class WeaponType;

class IView
{
public:
	/* La implementaci�n "= default" simplemente indica que se usar� la implementaci�n predeterminada 
	del destructor para la clase base.*/
	virtual ~IView() = default;
	/*En este caso, el argumento "text" de la funci�n "showText"
	se declara como un puntero a un car�cter (char*), lo que significa que "text" apunta a la primera posici�n
	en memoria de una cadena de caracteres. Al utilizar el operador "*", 
	se puede acceder al valor de la cadena de caracteres a la que apunta "text".*/
	virtual void showText(const char *text) = 0;
	/*La referencia constante permite que la funci�n "showText" acceda al argumento "text" 
	sin hacer una copia de la cadena de caracteres, lo que puede ahorrar tiempo y memoria en caso de 
	cadenas de caracteres grandes. 
	Adem�s, la referencia constante indica que la funci�n "showText" no modificar� el argumento "text".*/
	virtual void showText(const std::string& text) = 0;

	virtual void setWeaponMenuItems(const std::map<WeaponType, Weapon*>& items) = 0;

};

