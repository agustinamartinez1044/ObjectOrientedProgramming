#pragma once

#include <iostream>
#include <string>
#include "../clases/Usuario.h"

using namespace std;

class IIniciarSesion {
    public:
        virtual ~IIniciarSesion() = 0;
        virtual bool confirmarDatosSesion(string email, string contrasena) = 0;
        virtual Usuario *buscarUsuario(string) = 0;
        virtual void setUsuario(Usuario *) = 0;
};
