#pragma once 

#include <list>

#include "../datatypes/DtVideojuego.h"

class IEliminarVideojuego {

    public:
        virtual ~IEliminarVideojuego() = 0;
        virtual list<DtVideojuego *> listarVideojuegosSinPartidasActivas() = 0;
        virtual bool tienePartidasActivas(string nombreVideojuego) = 0;
        virtual void eliminarVideojuego(string nombre) = 0; 
};
