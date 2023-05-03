#ifndef __CURSO_HPP__
#define __CURSO_HPP__
#include <iostream>
#include <string>
#include "Evaluaciones.hpp"
#include "stack.hpp"
#include "Alumno.hpp"

using namespace std;

class Curso{
	string nombre;
	string seccion;
	string codigoCurso;
	string carrera;
	unsigned short ciclo;
public:
	Curso(string nombre = "", string seccion="",string codigoCurso="", unsigned short ciclo = 1): ciclo(ciclo), nombre(nombre), seccion(seccion), codigoCurso(codigoCurso), carrera(carrera){}
	~Curso(){}

	string toString(){
		return nombre + " " + seccion + " " + codigoCurso + "\n"; 
	}

	string getNombre() {
		return nombre;
	}

	string getCarrera() {
		return carrera;
	}

	unsigned short getCiclo() {
		return ciclo;
	}
	
};

#endif // !__CURSO_HPP__

