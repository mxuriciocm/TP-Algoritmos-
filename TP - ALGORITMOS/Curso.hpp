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
	int notaFinal;
	int idx;
public:
	Curso(string nombre = "", string seccion="",string codigoCurso="", unsigned short ciclo = 1, int idx = 0, int notaFinal = 0):notaFinal(notaFinal), idx(idx), ciclo(ciclo), nombre(nombre), seccion(seccion), codigoCurso(codigoCurso), carrera(carrera){
		this->notaFinal = rand() % 21;
	}
	~Curso(){
	}

	string toString(){
		return nombre + " " + seccion + " " + codigoCurso + "\n"; 
	}
	string getCodigoCurso() {
		return codigoCurso;
	}
	string getNotaFinal() {
		return to_string(notaFinal);
	}
	int getNota() {
		return notaFinal;
	}

	string getNombre() {
		return nombre;
	}

	int getIdx() {
		return idx;
	}

	string getCarrera() {
		return carrera;
	}

	unsigned short getCiclo() {
		return ciclo;
	}

	
};

#endif // !__CURSO_HPP__

