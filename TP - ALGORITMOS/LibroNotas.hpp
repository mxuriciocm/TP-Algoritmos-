#ifndef __LIBRO_NOTAS_HPP__
#define __LIBRO_NOTAS_HPP__
#include "Vector.hpp"
#include "Notas.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

class LibroNotas
{
private:
    Vector<Notas> libroNotas;
    string codigoAlumno;
    string nombreDeCurso;
public:
    LibroNotas(string codigoAlumno = "", string nombreDeCurso = ""){
        this->codigoAlumno = codigoAlumno;
        this->nombreDeCurso = nombreDeCurso;
    }

    void mostrarNotas(){
        cout << "Codigo del alumno: " << codigoAlumno << "\nNombre del curso: " << nombreDeCurso << "\n";
        //clico para imprimir todas las notas
        libroNotas.imp([](Notas n){
            cout << n.toString() << endl;
        });
    }
};

#endif