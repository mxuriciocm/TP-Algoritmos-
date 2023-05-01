#pragma once
#include <iostream>
#include <functional>
using namespace std;

template <class Generico>
class Nodo {
public:
	Generico dato;
	Nodo<Generico>* siguiente;
	Nodo<Generico>* anterior;
	Nodo(Generico d){
		dato=d;
		siguiente=nullptr;
		anterior=nullptr;
	}
	~Nodo(){}
};

template <class Generico>
class Lista {
	Nodo<Generico>* inicio;
	Nodo<Generico>* fin;
	int cantidad;
public:
	Lista(){
		inicio=nullptr;
		fin=nullptr;
		cantidad=0;
	}
	~Lista(){}
	void pushback(Generico d) {
		Nodo<Generico>* temp = new Nodo<Generico>(d);
		if (Vacio()) {
			inicio= temp;
			fin=temp;
		}
		else {
			fin->siguiente = temp;
			temp->anterior = inicio;
			fin	= temp;
		}
		cantidad++;
	}
	/*void pushfront(Generico d) {
		Nodo<Generico>* temp = new Nodo<Generico>(d);
		if (inicio==nullptr) {
			inicio = temp;
			fin = temp;
		}
		else {
			Nodo<Generico>*temp2=inicio;
			inicio = temp;
			temp->anterior = nullptr;
			temp->siguiente=temp2;
		}
		cantidad++;
	}*/
	void MOSTRAR(function<void (Generico)>mostrar) {
		Nodo<Generico>* temp = inicio;
		while (temp!=nullptr){
			mostrar(temp->dato);
			temp = temp->siguiente;
		}
	}
	bool Vacio() {
		return inicio==nullptr;
	}
	
};