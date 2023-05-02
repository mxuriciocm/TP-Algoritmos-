#ifndef __REGISTRO_HPP__
#define __REGISTRO_HPP__
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

class Registro
{
private:
	string usuario;
	string contrasena;

public:
	Registro(string usuario="", string contrasena="") : usuario(usuario), contrasena(contrasena){}
	
	void guardarRegistro(string usuario, string contrasena){

		ofstream archivo;
		archivo.open("registro.txt", std::ios::app);
		if (archivo.is_open()) {
			archivo << usuario << endl;
			archivo << contrasena << endl;
			archivo.close();
			cout << "Registro exitoso" << endl;
		}
		else {
			cout << "Error al abrir el archivo" << endl;
		}
	}
	
	void validarRegistro(string usuario, string contrasena) {
		
		ifstream archivo("registro.txt");
		bool usuarioEncontrado = false;
		bool contrasenaEncontrada = false;
		string linea;


		while (getline(archivo, linea)) {
			if (linea == usuario) {
				usuarioEncontrado = true;
				if (getline(archivo, linea)) {
					if (linea == contrasena) {
						contrasenaEncontrada = true;
					}
				}

			}
		}

		archivo.close();
		if (usuarioEncontrado && contrasenaEncontrada == true) {
			cout << "Se inicio sesion" << endl;
		} else{
			cout << "Usuario y/o contrasena incorrectos" << endl;
		}
	}

	void menuRegistro() {
		string usuario, contrasena;
		int opc;
		cout << "Bienvenido a la aplicacion" << endl;
		cout << "1. Registrarse" << endl;
		cout << "2. Iniciar sesion" << endl;
		cout << "Ingrese una opcion: " << endl;
		cin >> opc;
		switch (opc) {
		case 1: {
			cout << "Ingrese su usuario: " << endl;
			cin >> usuario;
			cout << "Ingrese su contrasena: " << endl;
			cin >> contrasena;
			if (usuario != "" && contrasena != "") {
				guardarRegistro(usuario, contrasena);
			}
			else {
				cout << "Usuario o contrasena invalidos" << endl;
			}
			break;
		}
		
		case 2: {
			//opcion 2
			cout << "Ingrese su usuario: " << endl;
			cin >> usuario;
			cout << "Ingrese su contrasena: " << endl;
			cin >> contrasena;
			if (usuario != "" && contrasena != "") {
				validarRegistro(usuario, contrasena);
			}
			else {
				cout << "Usuario o contrasena invalidos" << endl;
			}
			break;
		}
			  
			 
		}
	}
};

#endif // !__REGISTRO_HPP__