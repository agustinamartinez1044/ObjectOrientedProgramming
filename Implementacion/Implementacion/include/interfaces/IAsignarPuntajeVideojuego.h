#pragma once

#include <list>

#include "../clases/Videojuego.h"
#include "../datatypes/DtVideojuego.h"

using namespace std;

class IAsignarPuntajeVideojuego {

    public:
        virtual ~IAsignarPuntajeVideojuego() = 0;
        virtual map<string,DtVideojuego*> listarVideojuegosSistema() = 0;
        virtual void asignarPuntaje(string nombreVideojuego, int puntaje) = 0;
};
