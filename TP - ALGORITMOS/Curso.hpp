#ifndef __CURSO_HPP__
#define __CURSO_HPP__
#include <iostream>
#include <string>
using namespace std;

class Curso{
	string nombre;
	string seccion;
	string codigoCurso;
public:
	Curso(string nombre = "", string seccion="",string codigo=""): nombre(nombre), seccion(seccion), codigo(codigo) {}
	~Curso(){}

	string toString(){
		return nombre + " " + seccion + " " + codigoCurso + "\n"; 
	}
};

#endif // !__CURSO_HPP__

