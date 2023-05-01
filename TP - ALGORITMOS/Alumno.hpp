#ifndef __ALUMNO_HPP__
#define __ALUMNO__HPP__
#include "Persona.hpp"

class Alumno : public Persona{
	string carrera;
	unsigned short ciclo;
public:
    Alumno(string nombre = "", string rol = "", string codigo = "", string correo = "", unsigned short edad = 25, string carrera = "", unsigned short ciclo = 1)
        : Persona(nombre, rol, codigo, correo, edad), carrera(carrera), ciclo(ciclo)
    {}

    string getCarrera()  {
        return carrera;
    }

    unsigned short getCiclo()  {
        return ciclo;
    }

    string toString() {
        return Persona::toString() + "Carrera: " + carrera + "\nCiclo: " + to_string(ciclo) + "\n";
    }
};
#endif // !__ALUMNO_HPP__
