#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__
#include <functional>

template <typename X>
class Vector {
private:
    X* vec;
    int idx;
    int capacity;

public:
    Vector(int cap = 10, int idx = -1) : capacity(cap), idx(idx) {
        vec = new X[cap];
    }

    Vector(X* v, int size) : vec(v), idx(size - 1), capacity(size) {}

    ~Vector() {
        delete[] vec;
    }

    void push_back(X x) {
        if (idx == capacity - 1) { // 2
            capacity *= 2; // 2
            X* aux = new X[capacity]; // 2
            for (int i = 0; i <= idx; i++) { //1 + n(2 + INTERNO +  2)
                aux[i] = vec[i]; // 3
            }
            delete[] vec; // 1
            vec = aux; // 1
        }
        vec[++idx] = x; // 2
    }
    // 7 + N(7) + 4 


    void at() {
        if (idx != -1) {
			return vec[idx];
		}
    }

    void pop_back() {
        if (idx != -1) {
            idx--;
        }
    }

    void imp(std::function<void(X)> f) {
        for (int i = 0; i <= idx; i++) {
            f(vec[i]);
        }
    }

    int size() {
        return idx + 1;
    }

    //contar los elementos con recursividad
    int size_rec(int i = 0) {
        if (i > idx) {
			return 0;
		}
		return 1 + size_rec(i + 1);
	}

    void for_each(std::function<void(X&)> f) {
        for (int i = 0; i <= idx; i++) {
            f(vec[i]);
        }
    }


};


#endif