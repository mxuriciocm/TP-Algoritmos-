#ifndef __CURSO_HPP__
#define __CURSO_HPP__
#include <iostream>
#include <string>
using namespace std;

class Curso{
	string nombre;
	string seccion;
	string codigoCurso;
	string carrera;
	unsigned short ciclo;
public:
	Curso(string nombre = "", string seccion="",string codigoCurso=""): nombre(nombre), seccion(seccion), codigoCurso(codigoCurso) {}
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

