#pragma once
#include <iostream>

using namespace std;

class Curso{
public:
	Curso(string n,string sec,string cod){
		this->nombre=n;
		this->seccion=sec;
		this->codigo=cod;
	}
	~Curso(){}
	string getNombre(){
		return this->nombre;
	}
	void setNombre(string n){
		this->nombre=n;
	}

	string getSeccion() {
		return this->seccion;
	}
	void setSeccion(string n) {
		this->seccion = n;
	}

	string getCodigo() {
		return this->codigo;
	}
	void setCodigo(string n) {
		this->codigo = n;
	}
	void Datos_Curso(){
		cout<<"Datos del curso"<<endl;
		cout<<getNombre()<<endl;
		cout<<getCodigo()<<endl;
		cout<<getSeccion()<<endl;
	}
private:
	string nombre;
	string seccion;
	string codigo;
};



