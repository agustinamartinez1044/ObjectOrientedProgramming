#pragma once

#include <list>
#include <map>

#include "../datatypes/DtVideojuego.h"
#include "../enumerados/StatusSuscripcion.h"
#include "../datatypes/DtSuscripcion.h"

using namespace std;

class ISuscripcionVideojuegos {
    public:
        virtual ~ISuscripcionVideojuegos() = 0;
        virtual DtFechaHora * getFechaSistema() = 0;
        virtual list<DtVideojuego*> listarVideojuegosConSuscripcionActiva() = 0;
        virtual list<DtVideojuego*> listarVideojuegosNoSuscriptos() = 0;
        virtual StatusSuscripcion getStatusSuscripcionVideojuego(string nombre) = 0;
        virtual map<string,float> getCostosVideojuego(string nombreVideojuego) = 0;
        virtual void cancelarSuscripcion(string nombreVideojuego) = 0;
        virtual void confirmarSuscripcion(string nombreVideojuego, DtSuscripcion *suscripcion) = 0;
};
