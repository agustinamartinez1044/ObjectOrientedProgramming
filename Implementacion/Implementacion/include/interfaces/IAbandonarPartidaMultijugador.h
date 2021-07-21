#pragma once

#include <list>
#include <map>

#include "../datatypes/DtPartidaMultijugador.h"

class IAbandonarPartidaMultijugador {

    public:
        virtual ~IAbandonarPartidaMultijugador() = 0;
        virtual list<DtPartidaMultijugador*> listarPartidasNoFinalizadasMultijugador() = 0;
        virtual void finalizarPartida(int id) = 0;
        virtual void abandonarPartidaMultijugador(int identificador) = 0;
};
