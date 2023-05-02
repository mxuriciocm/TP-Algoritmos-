#pragma once
#include <iostream>
#include <functional>
using namespace std;

template <class X>
class Nodo {
public:
	X dato;
	Nodo<X>* siguiente;
	Nodo<X>* anterior;
	Nodo(X d){
		dato=d;
		siguiente=nullptr;
		anterior=nullptr;
	}
	~Nodo(){}
};

template <class X>
class Lista {
	Nodo<X>* inicio;
	Nodo<X>* fin;
	size_t cantidad;
public:
	Lista(){
		inicio=nullptr;
		fin=nullptr;
		cantidad=0;
	}
	~Lista(){}
	void pushback(X d) {
		Nodo<X>* temp = new Nodo<X>(d);
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
	void mostrar(function<void (X)>mostrar) {
		Nodo<X>* temp = inicio;
		while (temp!=nullptr){
			mostrar(temp->dato);
			temp = temp->siguiente;
		}
	}
	bool Vacio() {
		return inicio==nullptr;
	}
	
};