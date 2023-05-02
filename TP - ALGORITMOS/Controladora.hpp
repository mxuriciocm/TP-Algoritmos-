#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include <iostream>
#include <string>

using std::endl;
using std::string;

class Controladora {
private:
	Registro* login;
	string rol;
	string usuario;
public:
	Controladora(string rol = ""): rol(rol) {
		login = new Registro();
	}
	~Controladora() {}

	void inicioPrograma() {
		login->menuRegistro();
		rol = login->getRol();
		Controladora::inicio();
	}

	void inicio(){
		if(rol == "alumno"){
			cout << "menu alumno";
		}else if(rol == "profesor"){
			cout << "menu profesor";
		}
	}

};

#endif 