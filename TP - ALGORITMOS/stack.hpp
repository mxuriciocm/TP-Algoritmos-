#ifndef __STACK_HPP__
#define __STACK_HPP__
#include <functional>
template <class T>
struct Nodo
{
	T element;
	Nodo<T> *sig;
	Nodo<T> *ant;
	Nodo(T e) : element(e) { sig = ant = nullptr; }
};

template <class T>
class Stack
{
private:
	Nodo<T>* inicio;
	size_t size;

public:
	Stack()
	{
		this->inicio = nullptr;
		this->size = 0;
	}
	~Stack() {
		desapilarTodo();
	}

	void desapilarTodo() {}


	T peek() { return inicio->elemento; }

	T forElement (T e) {
		Nodo<T>* aux = inicio;
		do {
			if (aux->element == e) return aux->element;
		} while (aux != inicio);
		return nullptr;
	}

	void push(T e) {
		Nodo<T>* nuevo = new Nodo<T>(e);

		if (inicio == nullptr) {
			nuevo->sig = nuevo;
			nuevo->ant = nuevo;
		}
		else {
			nuevo->sig = inicio;
			nuevo->ant = inicio->ant;
			inicio->ant = nuevo;
			nuevo->ant->sig = nuevo;
		}
		inicio = nuevo;
		++size;
	}

    void forEach(std::function<void(T)> f) {
		Nodo<T>* aux = inicio;
		do {
			f(aux->element);
			aux = aux->sig;
		} while (aux != inicio);
	}

	void pop() {
		if (inicio == nullptr) return;

		else if (size == 1) {
			delete inicio;
			inicio = nullptr;
			size = 0;
		}

		else
		{
			inicio->ant->sig = inicio->sig;
			inicio->sig->ant = inicio->ant;
			Nodo<T>* aux = inicio;
			inicio = inicio->sig;
			delete aux;
		}
	}

	void pop_back() {
		if (inicio == nullptr) return;

		else if (size == 1) {
			delete inicio;
			inicio = nullptr;
			size = 0;
		}

		else {
			Nodo<T>* aux = inicio->ant;
			inicio->ant = aux->ant;
			aux->ant->sig = inicio;
			size--;
			delete aux;
		}
	}

	bool isEmpty() {
		return inicio == nullptr;
	}
};

#endif // !__STACK_HPP__