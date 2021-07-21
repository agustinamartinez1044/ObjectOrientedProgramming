#pragma once

#include "DtPartida.h"

class DtPartidaIndividual: public DtPartida{
    private:
        bool continuaPartidaAnterior;
        int idPartidaAnterior;
    public:
        DtPartidaIndividual(int id, DtFechaHora *comienzo, string videojuego, bool continuaPartidaAnterior);
        DtPartidaIndividual(int id, DtFechaHora *comienzo,string videojuego, bool continuaPartidaAnterior, int inContinuaPartidaAnterior);
        DtPartidaIndividual();
        ~DtPartidaIndividual();
        int getPartidaQueContinua();

        void print(ostream &os) const;
};
