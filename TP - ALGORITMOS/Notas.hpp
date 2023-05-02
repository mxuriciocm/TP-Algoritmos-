#ifndef __NOTAS_HPP__
#define __NOTAS_HPP__

#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;

class Notas
{
private:
    float nota;
    string nombreCurso;
    string codigoAlumno;
public:
    Notas() {}
    ~Notas() {}

    void setNota(float nota) {this->nota = nota;}
    void setNombreCurso(string nombreCurso) {this->nombreCurso = nombreCurso;}
    void setCodigoAlumno(string codigoAlumno) {this->codigoAlumno = codigoAlumno;}

    float getNota() {return nota;}
    string getNombreCurso() {return nombreCurso;}
    string getCodigoAlumno() {return codigoAlumno;}

    string toString() {
        return "Nombre del curso: " + nombreCurso + "\nCodigo del alumno: " + codigoAlumno + "\nNota: " + std::to_string(nota) + "\n";
    }
};




#endif // !__NOTAS_HPP__
