#include <iostream>
#include "Controladora.hpp"
using namespace std;

int main() {
	CONTROLADORA* controller=new CONTROLADORA();
	controller->ejecutar();
	delete controller;
	cin.ignore();
	cin.get();
	return 0;
}