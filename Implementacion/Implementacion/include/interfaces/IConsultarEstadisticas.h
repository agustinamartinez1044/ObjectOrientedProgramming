#pragma once

#include <cstdarg>
#include <list>

#include "../clases/Estadistica.h"

#include "../datatypes/DtVideojuego.h"

using namespace std;

class IConsultarEstadisticas {

    public: 
        virtual ~IConsultarEstadisticas() = 0;
        virtual list<DtVideojuego *> listarVideojuegosDelDesarrollador() = 0;
        virtual bool existeVideojuego(string) = 0;
        virtual list<DtEstadistica *> consultarEstadisticas(string) = 0; 
};
