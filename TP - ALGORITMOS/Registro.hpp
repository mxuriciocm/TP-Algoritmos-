#ifndef __REGISTRO_HPP__
#define __REGISTRO_HPP__
#include "Alumno.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
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

		while (getline(archivo1, linea, ' ')) {
			if (linea == usuario) {
				cout << "El usuario ya existe" << endl;	
				usuarioEncontrado = true;
				break;
			}
		}
		if (!usuarioEncontrado)
		{
			this->usuario = usuario;
			//Pedir datos al usuario
			cout << "Ingrese su nombre: ";	
			cin >> nombre;
			cout << "Ingrese su edad: ";
			cin >> edad;
			cout << "Ingrese su carrera: ";
			cin >> carrera;
			cout << "Ingrese su ciclo: ";
			cin >> ciclo;
			system("cls");
			//guardar en el archivo
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
				this->rol = rol;
				archivo << rol << " ";
				archivo << nombre << " ";
				archivo << edad << " ";
				archivo << carrera << " ";
				archivo << ciclo << endl;
				archivo.close();
				cout << "Registro exitoso!" << endl;
			}
			else {
				cout << "Error al abrir el archivo" << endl;
			}
		}
	}
	
	void validarRegistro(string usuarioIntroducido, string contrasenaIntroducida) {
		ifstream archivo("registro.txt");
		bool usuarioEncontrado = false;
		bool contrasenaEncontrada = false;
		if (archivo.is_open()) {
			string linea;

			while (getline(archivo, linea)) {
				istringstream ss(linea);
				string usuarioActual, contrasenaActual, rolActrual;
				ss >> usuarioActual >> contrasenaActual >> rolActrual;

				if (usuarioActual == usuarioIntroducido && contrasenaActual == contrasenaIntroducida) {
					archivo.close();
					usuarioEncontrado = true;
					contrasenaEncontrada = true;
					this->usuario = usuarioActual;
				}
				if (rolActrual == "alumno") {
					this->rol = "alumno";
				}
				else if(rolActrual == "profesor")
				{
					this->rol = "profesor";
				}
				else if(rolActrual == "administrador")
				{
					this->rol = "administrador";
				}
				else
				{
					this->rol = "desconocido";
				}

			}
			archivo.close();
			

			if (usuarioEncontrado && contrasenaEncontrada) {
				cout << "Iniciaste sesion" << usuario << endl;
			}
			else {
				cout << "Usuario o contrasena incorrectos" << endl;
			}
		}
		else {
			std::cout << "No se pudo abrir el archivo para verificar las credenciales." << std::endl;
		}
	}

	void menuRegistro() {
		string usuarioIngresada, contrasenaIngresada;
		int opc;
		cout << "Aplicacion Gestion Educativa" << endl;
		cout << "1. Registrarse" << endl;
		cout << "2. Iniciar sesion" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opc;
		switch (opc) {
			case 1: {
			cout << "Ingrese su usuario: ";
			cin >> usuarioIngresada;
			cout << "Ingrese su contrasena: ";
			cin >> contrasenaIngresada;
			if (usuarioIngresada != "" && contrasenaIngresada != "") {
				guardarRegistro(usuarioIngresada, contrasenaIngresada);
			}
			else {
				cout << "Usuario o contrasena invalidos" << endl;
			}
				break;
			}
		
		case 2: {
			cout << "Ingrese su usuario: ";
			cin >> usuarioIngresada;
			cout << "Ingrese su contrasena: ";
			cin >> contrasenaIngresada;
			if (usuarioIngresada != "" && contrasenaIngresada != "") {
				validarRegistro(usuarioIngresada, contrasenaIngresada);
				system("cls");
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