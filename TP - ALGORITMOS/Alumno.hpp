#pragma once
#include <iostream>

using namespace std;

class Alumno{
public:
	Alumno(string n,int e,string cod,string corr){
		this->nombre=n;
		this->edad=e;
		this->codigo=cod;
		this->correo=corr;
		
	}
	~Alumno(){}
	string getNombre(){
		return this->nombre;
	}
	void setNombre(string n){
		this->nombre=n;
	}
	int getEdad(){
		return this->edad;
	}
	void setEdad(int e) {
		this->edad = e;
	}
	string getCodigo(){
		return this->codigo;
	}
	void setCodigo(string cod) {
		this->codigo = cod;
	}
	string getCorreo() {
		return this->correo;
	}
	void getCorreo(string corr) {
		this->correo = corr;
	}
	void Datos_Alumno(){
		cout<<"Datos"<<endl;
		cout<<getNombre()<<endl;
		cout<<getEdad()<<endl;
		cout<<getCodigo()<<endl;
		cout<<getCorreo()<<endl;
	}



private:
	string nombre;
	int edad;
	string codigo;
	string correo;
};


