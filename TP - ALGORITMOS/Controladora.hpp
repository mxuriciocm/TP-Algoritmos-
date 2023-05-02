#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include <iostream>

using std::endl;

class Controladora {
private:
	Registro* login;
public:
	Controladora() {
		login = new Registro();
	}
	~Controladora() {}

	void inicioPrograma() {
		login->menuRegistro();
	}

};

#endif 