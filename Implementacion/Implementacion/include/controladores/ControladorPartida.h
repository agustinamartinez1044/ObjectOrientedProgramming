#pragma once

#include <iostream>
#include <map>
#include <set>

#include "../interfaces/IFinalizarPartida.h"
#include "../interfaces/IIniciarPartida.h"
#include "../interfaces/IAbandonarPartidaMultijugador.h"
#include "../clases/Partida.h"

#include "./ControladorUsuario.h"
#include "./ControladorVideojuego.h"

using namespace std;

class ControladorPartida : public IIniciarPartida, public IFinalizarPartida,
    public IAbandonarPartidaMultijugador {
    private :
        ControladorPartida();
        static ControladorPartida *instancia;
        map<int,Partida *> partidas;
        int identificador;
    public :
        ~ControladorPartida();
        static ControladorPartida *getInstancia();
        int getIdentificador();
        void setIdentificador(int id);

        list<DtPartida *> listarPartidasNoFinalizadasDelJugador(string jugador);

		list<DtPartidaMultijugador*> listarPartidasNoFinalizadasMultijugador();
        list<DtPartida *> listarPartidasNoFinalizadasDelJugador();
        void finalizarPartida(int id);
        void elegirPartidaIndividual(int id);
        list<string> listarNicknames(string nombre);
        list<DtVideojuego *> listarVideojuegosConSuscripcionActiva();

        map<float, DtPartida *> listarPartidasIndividuales(string nombre);
        void confirmarPartida(DtPartida * dtPartida, string nombreVideojuego);
        void abandonarPartidaMultijugador(int identificador);
        map<int,Partida *> getPartidas();
};
