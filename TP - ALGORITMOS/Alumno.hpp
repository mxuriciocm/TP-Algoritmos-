#ifndef __ALUMNO_HPP__
#define __ALUMNO_HPP__
#include "Persona.hpp"
#include "Curso.hpp"
#include "Vector.hpp"
#include "stack.hpp"
#include <fstream>
#include <string>
using namespace std;

class Alumno : public Persona{
private:
	unsigned short ciclo;
	string carrera;
	//Vector<Curso*> cursos;
	Stack<Curso*> cursosMatriculados;
	Stack<Curso*> cursosDisponibles;
public:
	Alumno(string nombre = "", string codigo = "", string correo = "", unsigned short edad = 25, string carrera = "", unsigned short ciclo = 10)
        : Persona(nombre, "alumno", codigo, correo, edad), carrera(carrera), ciclo(ciclo)
    {
		cargarCursos();
	}

	string getCarrera(){
		return carrera;
	}

	unsigned short getCiclo(){
		return ciclo;
	}

	void cargarCursos() {
		ifstream archivo;
		archivo.open("cursos.txt");
		string idx, nombre, codigo;
		unsigned short ciclo;
		while (archivo >> idx >> nombre >> carrera >> ciclo) {
			cursosDisponibles.push(new Curso(nombre, codigo, carrera, (int)ciclo));
		}
		archivo.close();
		//imprimir cursos disponibles
		//cursosDisponibles.forEach([](Curso* c){
		//	cout << c->toString() << endl;
		//});
	}

	void mostrarCursos(){
		cursosDisponibles.forEach([](Curso* c){
			cout << c->toString();
		});
	}

	void matriculaCurso(){
		//cursosMatriculados.push(cursosDisponibles.forElement(cursosDisponibles.peek()));
	}

};
#endif // !__ALUMNO_HPP__