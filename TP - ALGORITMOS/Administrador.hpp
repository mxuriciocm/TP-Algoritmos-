#ifndef __ADMINISTRADOR_HPP__
#define __ADMINISTRADOR_HPP__
#include "Persona.hpp"

class Administrador : public Persona{
public:
    Administrador(string nombre = "", string rol = "", string codigo = "", string correo = "", unsigned short edad = 25, string cargo = "")
        : Persona(nombre, rol, codigo, correo, edad)
    {}
};

#endif // !__ADMINISTRADOR_HPP__
