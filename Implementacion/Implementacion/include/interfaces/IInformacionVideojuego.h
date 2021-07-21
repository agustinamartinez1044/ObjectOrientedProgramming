#pragma once

#include <list>
#include <map>

#include "../datatypes/DtVideojuego.h"

using namespace std;

class IInformacionVideojuego {

    public:
        virtual ~IInformacionVideojuego() = 0;
        virtual map<string,DtVideojuego*> listarVideojuegosSistema() = 0;
};
