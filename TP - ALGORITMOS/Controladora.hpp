#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
		cout << "el rol es: " << rol << endl;
		this->usuario = login->getUsuario();
		cout << "el usuario es: " << usuario << endl;
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

			Alumno* alumno = new Alumno(nombre, this->usuario, this->correo);
			cout << "Bienvenido " << alumno->getCodigo() << endl;
			cout << "correo: " << alumno->getCorreo() << endl;
			cout << "nombre: " << alumno->getNombre() << endl;
			//opciones 
			cout << "1. Ver cursos" << endl;
			cout << "2. Ver notas" << endl;
			cout << "3. Matricularse" << endl;
			cout << "4. Salir de curso" << endl;
			cout << "5. Cerrar sessión" << endl;

		}else if(rol == "profesor"){
			cout << "menu profesor";

		}
	}


};

#endif 