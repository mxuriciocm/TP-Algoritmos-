#ifndef __REGISTRO_HPP__
#define __REGISTRO_HPP__
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
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
	string rol;
public:
	Registro(string usuario="", string contrasena="") : usuario(usuario), contrasena(contrasena){}
	

	string getRol() {
		return rol;
	}
	string getUsuario(){
		return usuario; 
	}

	void guardarRegistro(string usuario, string contrasena){
		//Datos para el usuario
		unsigned short edad, ciclo;
		string nombre, carrera;

		//para los datos
		ofstream archivo;
		ifstream archivo1;
		archivo1.open("registro.txt");
		string linea;
		bool usuarioEncontrado = false;

		while (getline(archivo1, linea)) {
			if (linea == usuario) {
				cout << "El usuario ya existe" << endl;	
				usuarioEncontrado = true;
				break;
			}
		}
		if (!usuarioEncontrado)
		{
			//Pedir datosw al usuario
			cout << "Ingrese su nombre:";	
			cin >> nombre;
			cout << "Ingrese su edad:";
			cin >> edad;
			cout << "Ingrese su carrera:";
			cin >> carrera;
			cout << "Ingrese su ciclo:";
			cin >> ciclo;

			archivo.open("registro.txt", std::ios::app);
			
			if (archivo.is_open()) {
				archivo << usuario << " ";
				archivo << contrasena << " ";
				switch (tolower(usuario[0])) {
				case 'u':
					rol = "alumno";
					break;
				case 'p':
					rol = "profesor";
					break;
				case 'a':
					rol = "administrador";
					break;
				default:
					rol = "desconocido";
					break;
				}
				archivo << rol << " ";
				archivo << nombre << " ";
				archivo << edad << " ";
				archivo << carrera << " ";
				archivo << ciclo << endl;
				archivo.close();
				cout << "Registro exitoso" << endl;
			}
			else {
				cout << "Error al abrir el archivo" << endl;
			}
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
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch (opc) {
			case 1: {
			cout << "\nIngrese su usuario: ";
			cin >> usuario;
			cout << "Ingrese su contrasena: ";
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