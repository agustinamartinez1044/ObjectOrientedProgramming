#pragma once

#include <list>
#include <map>

#include "../clases/Partida.h"

#include "../datatypes/DtVideojuego.h"

using namespace std;

class IFinalizarPartida {
    
    public :
        virtual ~IFinalizarPartida() = 0;
        virtual list<DtPartida *> listarPartidasNoFinalizadasDelJugador() = 0;
        virtual void finalizarPartida(int id) = 0;
        virtual map<int,Partida *> getPartidas() = 0;
};
