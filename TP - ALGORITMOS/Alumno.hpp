#ifndef __ALUMNO_HPP__
#define __ALUMNO_HPP__
#include <iostream>
#include "Persona.hpp"
#include <string>
using namespace std;

class Alumno : public Persona{
private:
	unsigned short ciclo;
	string carrera;
public:
	Alumno(string nombre = "", string rol = "", string codigo = "", string correo = "", unsigned short edad = 25, string carrera = "", unsigned short ciclo = 1)
        : Persona(nombre, rol, codigo, correo, edad), carrera(carrera), ciclo(ciclo)
    {}

	~Alumno() {}

	string getCarrera(){
		return carrera;
	}

	unsigned short getCiclo(){
		return ciclo;
	}

	string toString() {
		return Persona::toString() + carrera + " " + ciclo + "\n";
	}
};
#endif // !__ALUMNO_HPP__