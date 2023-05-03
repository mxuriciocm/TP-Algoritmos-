#ifndef __PERSONA_HPP__
#define __PERSONA_HPP__
#include <iostream>
#include <string>

using std::string;
using std::to_string;

class Persona {
	string nombre;
	string rol;
	string codigo;
	string correo;
	unsigned short edad;
public:
	Persona(string nombre = " ", string rol = "", string codigo = " ", string correo = " ", unsigned short edad = 1) : nombre(nombre), rol(rol), codigo(codigo), correo(correo), edad(edad) 
	{}
	virtual string getNombre() {
		return nombre;
	}

	virtual string getCodigo(){
		return codigo;
	}

	virtual string getCorreo(){
		return correo;
	}
};

#endif // !__PERSONA_HPP__

