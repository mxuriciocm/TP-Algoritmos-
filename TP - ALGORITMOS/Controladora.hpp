#pragma once
#include <iostream>
#include <functional>
#include "Alumno.hpp"
#include "Lista.hpp"
#include "Curso.hpp"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class CONTROLADORA {
public:
	Alumno* alumno;
	Lista<Curso*>lista_cursos;
	ifstream archivo;
	string data;
	vector<string>_cursos;
	CONTROLADORA() {}
	void ejecutar() {
		string name;
		int edad;
		string codigo_A;
		string correo;
		string curso;
		string seccion;
		string codigo;


		cout << "Nombre del alumno:"; cin >> name;
		cout << "Edad del alumno:"; cin >> edad;
		cout << "Codigo del alumno:"; cin >> codigo_A;
		cout << "Correo del alumno:"; cin >> correo;
		alumno = new Alumno(name, edad, codigo, correo);
		alumno->Datos_Alumno();
		int opcion_menu;
		while (true) {
			if (opcion_menu == 3) {
				break;
			}
			do {
				cout << "MENU BLACKBOARD" << endl;
				cout << "1. Matricularse" << endl;
				cout << "2. Ver mis cursos" << endl;
				cout << "3. SALIR" << endl;
				cout << "OPCION: "; cin >> opcion_menu;
			} while (opcion_menu < 1 || opcion_menu>3);
			switch (opcion_menu) {
			case 1:
				//MOSTRAR OPCIONES DE CURSOS
				archivo.open("Cursos.txt", ios::in);

				if (archivo.is_open()) {
					while (getline(archivo, data)) {
						_cursos.push_back(data);
					}
				}
				for (int i = 0; i < _cursos.size(); i++) {
					cout << _cursos.at(i) << endl;
				}
				//----------------------------------------------
				int opcion;
				cout << "A qué curso te vas a matricular:"; cin >> opcion;
				switch (opcion) {
				case 1:
					curso = "ALGORITMOS";
					codigo = "SX21";
					break;
				case 2:
					curso = "CALCULO";
					codigo = "MA4062";
					break;
				case 3:
					curso = "REDES Y COMUNICACIONES DE DATOS";
					codigo = "SRD50";
					break;
				}

				cout << "Seccion del curso:"; cin >> seccion;
				lista_cursos.pushback(new Curso(curso, seccion, codigo));
				break;
			case 2:
				lista_cursos.MOSTRAR([](Curso* c) {c->Datos_Curso(); });
				break;

			}
		}


	}


};