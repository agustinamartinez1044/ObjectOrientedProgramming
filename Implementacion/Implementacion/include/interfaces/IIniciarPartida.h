#pragma once

#include <list>
#include <map>

#include "../clases/Partida.h"

#include "../datatypes/DtVideojuego.h"
#include "../datatypes/DtPartidaIndividual.h"

using namespace std;

class IIniciarPartida {
    public :
        virtual ~IIniciarPartida() = 0;
        virtual list<DtVideojuego *> listarVideojuegosConSuscripcionActiva() = 0;   //listo
        virtual map<float, DtPartida *> listarPartidasIndividuales(string nombre) = 0; //listo
        virtual void elegirPartidaIndividual(int id) = 0; //Menu
        virtual list<string> listarNicknames(string nombre) = 0; //listo
        virtual void confirmarPartida(DtPartida *,string nombreVideojuego) = 0;
        virtual int getIdentificador() = 0;
        virtual void setIdentificador(int id) = 0;
};
