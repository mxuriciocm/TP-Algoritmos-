#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::endl;
using std::string;
using std::cout;

class Controladora {
private:
	Registro* login;
	string rol;
	string usuario;
	string correo;
public:
	Controladora(string rol = ""): rol(rol) {
		login = new Registro();
	}
	~Controladora() {}

	void inicioPrograma() {
		login->menuRegistro();
		this->rol = login->getRol();
		this->usuario = login->getUsuario();
		this->correo = login->getUsuario()+"@estudia.com";
		Controladora::inicio();
	}


	void inicio() {
		if (rol == "alumno") {
			ifstream archivo;
			string linea;
			string contrasena, tipo, nombre, carrera;
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
					string UserEncontrar;
					archivo >> UserEncontrar;
					if (UserEncontrar == this->usuario)
					{
						cout << "usuario encontrado" << endl;
						archivo >> contrasena;
						archivo >> tipo;
						archivo >> nombre;
						archivo >> edad;
						archivo >> carrera;
						archivo >> ciclo;
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