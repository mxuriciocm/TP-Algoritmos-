#ifndef __PERSONA_HPP__
#define __PERSONA_HPP__
#include <iostream>
#include <string>
using namespace std;

class Persona {
	string nombre;
	string rol;
	string codigo;
	string correo;
	unsigned short edad;
public:
	Persona(string nombre = " ", string rol = "", string codigo = " ", string correo = " ", unsigned short edad = 25) : nombre(nombre), rol(rol), codigo(codigo), correo(correo), edad(edad) 
	{}
	virtual string toString() {
		return nombre + " " + rol + " " + to_string(edad) + "\n";
	}
};

#endif // !__PERSONA_HPP__

