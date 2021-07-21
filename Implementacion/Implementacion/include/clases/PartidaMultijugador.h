#pragma once

#include <iostream>
#include <list>
#include <map>

#include "../datatypes/DtFechaHora.h"
#include "../datatypes/DtPartida.h"
#include "../datatypes/DtPartidaMultijugador.h"

#include "./Partida.h"
#include "./Participa.h"
#include "./Observa.h"

using namespace std;

class PartidaMultijugador : public Partida{
private:
    bool transmitidaenvivo;
    map<string,Participa *> participantes;
    map<int,Observa *> observadores;

public:
    PartidaMultijugador();
    PartidaMultijugador(
        int id, DtFechaHora *comienzo, bool trasmitidaenvivo,
        map<string,Participa *> participantes, map<int,Observa *> observadores);
    PartidaMultijugador(DtPartidaMultijugador *PartidaMultijugador, map<string,Participa *> participantes);
    ~PartidaMultijugador();

    bool getTransmitidaEnVivo();
    void setTransmitidaEnVivo(bool trasmitidaenvivo);
    map<string,Participa *> getParticipantes();
    void setParticipantes(map<string,Participa *> participantes);
    map<int,Observa *> getObservadores();
    void setObservadores(map<int,Observa *> observadores);
    void finalizarPartidaMultijugador();
    DtPartida * getDtPartida();
};
