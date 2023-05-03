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

	void matriculaCurso(string codigo){
		//Elegir curso
		ifstream archivo;
		archivo.open("Cursos.txt");
		string idx, nombre, codigoCurso;
		unsigned short ciclo;
		while (archivo >> idx >> nombre >> codigoCurso >> ciclo) {
			if (codigoCurso == codigo) {
				cursosMatriculados.push(new Curso(nombre, codigoCurso, carrera, ciclo));
				cout << "Curso matriculado" << endl;
				break;
			}
		}
	}
	void verCursosMatriculados() {
		cursosMatriculados.forEach(
			[](Curso* c) {
				cout << c->toString() << endl;
			}
		);
	}

	void verNotas() {
		if (cursosMatriculados.isEmpty()) {
			cout << "No hay cursos matriculados" << endl;
			return;
		}
		else {
			cursosMatriculados.forEach([](Curso* c) {
				cout << "Nombre del curso: " << c->getNombre() << c->getNotaFinal() << endl;
				}
			);
		}
	}

	void retirarseDelCurso() {
		if (cursosMatriculados.isEmpty())
		{
			cout << "No hay cursos matriculados" << endl;
		}else{
			cursosMatriculados.popElementIf([](Curso* c) {
					return c->getNota() < 13;
				}
			);
			cout << "Se completo con el retiro del curso o cursos con calificaión menor a 13" << endl;
		}
	}

};
#endif // !__ALUMNO_HPP__