#ifndef __LIBROS_HPP__
#define __LIBROS_HPP__
#include <iostream>

using namespace std;

class Libros {
	string titulo;
	string codigoLibro;

public:
	Libros(string titulo = " ", string codigoLibro = " ", string correo = " ") : codigoLibro(codigoLibro) 
	{}
	
	virtual string toString() {
		return nombre + " " + rol + " " + to_string(edad) + "\n";
	}


#endif
