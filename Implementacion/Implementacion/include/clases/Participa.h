#pragma once

#include <iostream>

#include "../datatypes/DtFechaHora.h"

class PartidaMultijugador;

class Participa {
    private :
        DtFechaHora *horaAbandono;

    public :
        Participa();
        Participa(DtFechaHora *horaAbandono);
        ~Participa();

        DtFechaHora *getHoraAbandono();
        void setHoraAbandono(DtFechaHora *horaAbandono);
};
