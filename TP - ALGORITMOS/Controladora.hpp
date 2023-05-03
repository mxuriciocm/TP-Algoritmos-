#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>

using std::endl;
using std::string;
using std::cout;

class Controladora {
private:
	Registro* login;
	string usuario;
	string contrasena;
	string rol;
	string nombre;
	unsigned short edad;
	string carrera;
	unsigned short ciclo;
	string correo;

public:
	Controladora(string rol = ""): rol(rol) {
		login = new Registro();
	}
	~Controladora() {}

	void inicioPrograma() {
		login->menuRegistro();
		this->rol = login->getRol();
		cout << "Su rol es: " << rol << endl;
		this->usuario = login->getUsuario();
		cout << "Su usuario es: " << usuario << endl;
		this->correo = login->getUsuario()+"@estudia.com";
		Controladora::inicio();
	}


	void inicio() {
		if (rol == "alumno") {
			ifstream archivo;
			string linea;
			string usuarioActual, contrasenaActual, rolActual, nombreActual, carreraActual;
			unsigned short edad, ciclo;

			archivo.open("registro.txt");

			if (archivo.fail())
			{
				cout << "No se pudo abrir el archivo" << endl;
			}	
			else
			{
				while (getline(archivo, linea))
				{
					istringstream ss(linea);
					ss >> usuarioActual >> contrasenaActual >> rolActual >> nombreActual >> edad >> carreraActual >> ciclo;
					if (usuarioActual == this->usuario) {
						//guardar en las clase todos los datos
						this->rol = rolActual;
						this->nombre = nombreActual;
						this->edad = edad;
						this->carrera = carreraActual;
						this->ciclo = ciclo;
						break;
					}
				}
			}
			archivo.close();

			int opcion = 0;
			Alumno* alumno = new Alumno(nombre, this->usuario, this->correo);
			while (opcion != 5 ) {
				system("cls");
				cout << "Bienvenido " << alumno->getCodigo() << ", que deseas realizar?" << endl;
				//cout << "correo: " << alumno->getCorreo() << endl;
				//cout << "nombre: " << alumno->getNombre() << endl;
				//opciones 
				cout << "1. Ver cursos" << endl;
				cout << "2. Ver notas" << endl;
				cout << "3. Matricularse" << endl;
				cout << "4. Retirarse de un curso" << endl;
				cout << "5. Cerrar sesion" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcion;
				switch (opcion)
				{
				case 1:
				{
					alumno->mostrarCursos();
					system("pause");
				}
					break;
				case 2:
					alumno->verNotas();
					system("pause");
					break;
				case 3:
				{	cout << "Cursos disponibles:" << endl;
					alumno->mostrarCursos();
					cout << "Ingrese el codigo del curso: ";
					string codigo;
					cin >> codigo;
					alumno->matriculaCurso(codigo);
					//cursos matriculados
					cout << "Cursos matriculados:" << endl;
					alumno->verCursosMatriculados();
					system("pause");
				}
					break;
				case 4:
					alumno->retirarseDelCurso();
					system("pause");
					break;
				case 5:
					system("cls");
					break;
				}
			}
		
			
		}else if(rol == "profesor"){
			cout << "menu profesor";

		}
	}


};

#endif 