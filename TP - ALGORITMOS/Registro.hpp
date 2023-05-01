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
	string user;
	string pass;

public:
	Registro(string user="", string pass="") : user(user), pass(pass){
		user = user;
		pass = pass;
	}
	~Registro();

	void validarRegistro(string user, string pass){
		//validar de un archivo de texto primera linea user y segunda pass
		ofstream archivo;
		archivo.open("registro.txt", std::ios::app);
		archivo << user << endl;
		archivo << pass << endl;
		archivo.close();
	}
	void setUsuario(string user){
		this->user = user;
	}
	void setPass(string pass){
		this->pass = pass;
	}
	string getUsuario(){
		return user;
	}
	string getPass(){
		return pass;
	}

	//menu
	void menuRegistro(){
		string user, pass;
		cout << "Ingrese su usuario: ";
		cin >> user;
		cout << "Ingrese su contrasena: ";
		cin >> pass;
		setUsuario(user);
		setPass(pass);
		validarRegistro(user, pass);
	}
};

#endif // !__REGISTRO_HPP__