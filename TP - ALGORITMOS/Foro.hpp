#ifndef __FORO_HPP__
#define __FORO_HPP__
#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;

class Foro
{
private:
    //declarar variables
    ifstream openFile;
    ofstream writeFile;
    string nombreArchivo;

public:
    Foro(string nombreArchivo="foro_curso_1"){
        this->nombreArchivo = nombreArchivo;
    }
    ~Foro();

    void crearForo(){
        writeFile.open(nombreArchivo+".txt", std::ios::app);
        writeFile.close();
    }
    void escribirForo(string mensaje, string nombreArchivo, string nombreUsuario){
        writeFile.open(nombreArchivo+".txt", std::ios::app);
        writeFile << nombreUsuario << ": " << mensaje << "\n";
        writeFile.close();
    }
    void leerForo(string nombreArchivo){
        openFile.open(nombreArchivo+".txt");
        string linea;
        while (getline(openFile, linea)){
            cout << linea << "\n";
        }
        openFile.close();
    }
};

#endif // !__FORO_HPP__