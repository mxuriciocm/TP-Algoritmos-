#ifndef __ALUMNO_HPP__
#define __ALUMNO_HPP__
#include "Persona.hpp"
#include "Curso.hpp"
#include <vector>
using namespace std;

class Alumno : public Persona{
private:
	unsigned int ciclo;
	string carrera;
	vector<Curso*> cursos;
public:
	Alumno(string nombre = "", string codigo = "", string correo = "", unsigned short edad = 25, string carrera = "", unsigned short ciclo = 10)
        : Persona(nombre, "alumno", codigo, correo, edad), carrera(carrera), ciclo(ciclo)
    {}

	string getCarrera(){
		return carrera;
	}

	unsigned short getCiclo(){
		return ciclo;
	}

	string toString() {
		return Persona::toString() + carrera + " " + to_string(ciclo) + "\n";
	}

	void inscribirCurso(Curso* c) {
		if (c->getCarrera() != carrera) {
			cout << "No puedes inscribirte en este curso porque no es de tu carrera" << endl;
			return;
		}

		if (c->getCiclo() < ciclo) {
			cout << "No puedes inscribirte en este curso porque ya lo has pasado" << endl;
			return;
		}
		cursos.push_back(c);
		cout << "Te has inscrito en el curso " << c->getNombre() << ".\n";
	}

	void retirarCurso(Curso* c) {
		auto it = find(cursos.begin(), cursos.end(), c);
		if (it == cursos.end()) {
			cout << "No estás inscrito en este curso.\n";
			return;
		}
		cursos.erase(it);
		cout << "Te has retirado del curso " << c->getNombre() << ".\n";
	}

};
#endif // !__ALUMNO_HPP__