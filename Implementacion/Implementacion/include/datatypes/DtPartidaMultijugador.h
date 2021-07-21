#pragma once

#include "DtPartida.h"

#include <list>


class DtPartidaMultijugador: public DtPartida {
    private:

        bool transmitidaEnVivo;
        list<string> nicknames;

    public:
        DtPartidaMultijugador(int id, DtFechaHora *comienzo, string videojuego, bool transmitidaEnVivo, list<string> nicknames);
        DtPartidaMultijugador();
        ~DtPartidaMultijugador();
        bool getTransmitidaEnVivo() const;
        list<string> getNicknames() ;

        void print(ostream &os) const;
};
