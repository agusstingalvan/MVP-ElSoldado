#pragma once
#include <string>;
#include <map>;

class Weapon;
enum class WeaponType;

class IView
{
public:
	/* La implementación "= default" simplemente indica que se usará la implementación predeterminada 
	del destructor para la clase base.*/
	virtual ~IView() = default;
	/*En este caso, el argumento "text" de la función "showText"
	se declara como un puntero a un carácter (char*), lo que significa que "text" apunta a la primera posición
	en memoria de una cadena de caracteres. Al utilizar el operador "*", 
	se puede acceder al valor de la cadena de caracteres a la que apunta "text".*/
	virtual void showText(const char *text) = 0;
	/*La referencia constante permite que la función "showText" acceda al argumento "text" 
	sin hacer una copia de la cadena de caracteres, lo que puede ahorrar tiempo y memoria en caso de 
	cadenas de caracteres grandes. 
	Además, la referencia constante indica que la función "showText" no modificará el argumento "text".*/
	virtual void showText(const std::string& text) = 0;

	virtual void setWeaponMenuItems(const std::map<WeaponType, Weapon*>& items) = 0;

};

