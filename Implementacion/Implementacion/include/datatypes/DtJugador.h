#pragma once

#include <iostream>

#include "DtUsuario.h"

using namespace std;

class DtJugador : public DtUsuario {
    private:
        string nickname, descripcion;
    public:
        DtJugador(string email, string contrasena, string nickname, string descripcion);
        DtJugador();
        ~DtJugador();

        string getNickname() const;
        string getDescripcion() const;
};
