#pragma once

#include <iostream>

#include "../datatypes/DtFechaHora.h"
#include "../datatypes/DtPartida.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "./Partida.h"


class PartidaIndividual: public Partida {
    private:
    PartidaIndividual * continuacionde;
    public:
        PartidaIndividual();
        PartidaIndividual(int id, DtFechaHora *comienzo, PartidaIndividual * continuacionde);
        PartidaIndividual(DtPartidaIndividual *dtPartida);
        ~PartidaIndividual();
        
        PartidaIndividual * getContinuacionDe();
        DtPartida * getDtPartida();
        bool ContinuaPartidaAnterior();
};
