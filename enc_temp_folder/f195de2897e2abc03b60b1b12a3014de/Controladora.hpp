#ifndef __CONROLADORA_HPP__
#define __CONTROLADORA_HPP__
#include "Registro.hpp"
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::endl;
using std::string;

class Controladora {
private:
	Registro* login;
	string rol;
	string usuario;
	unsigned short ciclo;
	string carrera;
	string nombre;
	string codigo;
public:
	Controladora(string rol = ""): rol(rol) {
		login = new Registro();
	}
	~Controladora() {}

	void inicioPrograma() {
		login->menuRegistro();
		rol = login->getRol();
		usuario = login->getUsuario();
		Controladora::inicio();
	}

	void inicio(){
		if(rol == "alumno"){
			ifstream archivo;
			string linea;	
			archivo.open("registro.txt");

			if(archivo.fail()){
				cout << "No se pudo abrir el archivo";
			}
			
			while(!archivo.eof()){
				//buscar hasta encontrar un espacio
				nombre = linea.substr(0, linea.find(" "));
				carrera = linea.substr(linea.find(" ") + 1, linea.find(" "));
				ciclo = stoi(linea.substr(linea.find(" ") + 1, linea.find(" ")));	
			}
			archivo.close();
			Alumno* alumno = new Alumno(nombre, codigo, carrera, ciclo);
			cout << "Bienvenido " << alumno->getNombre() << endl;
			cout << "Carrera: " << alumno->getCarrera() << endl;
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