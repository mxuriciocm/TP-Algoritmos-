#ifndef __EVALUACIONES_HPP__
#define __EVALUACIONES_HPP__
#include <iostream>

using namespace std;

class Evaluaciones {
	unsigned short porcentaje;
public:
	Evaluaciones(unsigned short porcentaje = 0) : porcentaje(porcentaje) {}
	~Evaluaciones() {}

void mostrarEvaluaciones(){
cout << "15% = Practica 1" << endl;
cout << "25% = Practica 2" << endl;
cout << "25% = Evaluacion Parcial" << endl;
cout << "35% = Evaluacion Final" << endl;
}


};
#endif // !__EVALUACIONES_HPP__