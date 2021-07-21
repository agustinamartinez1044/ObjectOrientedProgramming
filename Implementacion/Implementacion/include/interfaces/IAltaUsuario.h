#pragma once

#include <iostream>

#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtDesarrollador.h"
#include "../datatypes/DtJugador.h"
#include "../clases/Jugador.h"
#include "../clases/Desarrollador.h"

using namespace std;

class IAltaUsuario {

    public:
        virtual ~IAltaUsuario() = 0;
        virtual bool nicknameValido(string) = 0;
        virtual bool emailValido(string) = 0;
        virtual void crearUsuario(DtUsuario *datos) = 0;
};
