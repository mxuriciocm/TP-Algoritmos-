#ifndef __PROFESOR_HPP__
#define __PROFESOR_HPP__
#include "Persona.hpp"

class Profesor : public Persona {
	string curso;
public:
	Profesor(string nombre = "", string rol = "", string codigo = "", string correo = "", unsigned short edad = 25, string curso = "")
		: Persona(nombre, rol, codigo, correo, edad)
	{}

	string getCurso() {
		return curso;
	}

	string toString() {
		return Persona::toString() + "Curso Dictado: " + curso + "\n";
	}
};

#endif // !__PROFESOR_HPP__

