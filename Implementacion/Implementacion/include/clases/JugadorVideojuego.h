#pragma once

#include <iostream>
#include <map>
#include <list>

#include "../datatypes/DtPartida.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartidaMultijugador.h"
#include "../datatypes/DtVideojuego.h"

#include "./Videojuego.h"
#include "./Partida.h"
#include "./Suscripcion.h"
#include "./PartidaIndividual.h"
#include "./PartidaMultijugador.h"
#include "./Participa.h"
#include "./Jugador.h"

class Videojuego;

using namespace std;

class JugadorVideojuego {
    private :

    map<int,Partida *> partidas;
    Jugador * jugador;
    Videojuego * videojuego;
    list<Suscripcion *> suscripciones;
    map<int,Participa *> participantes;

    public :
    
    JugadorVideojuego(Jugador * jugador,Videojuego * videojuego);
    JugadorVideojuego();
    ~JugadorVideojuego();

    map<int,Partida*> getPartidas();
    Jugador * getJugador();
    Videojuego * getVideojuego();
    list<Suscripcion*> getSuscripciones();
    map<int,Participa *> getParticipantes();
    void setPartidas(map<int,Partida*> partidas);
    void setJugador(Jugador * jugador);
    void setVideojuego(Videojuego * videojuego);
    void setSuscripciones(list<Suscripcion *> suscripciones);
    void setParticipantes(map<int,Participa *> participantes);
    void agregarSuscripcion(Suscripcion * nuevaSuscripcion);
    bool hayPartidasActivas();
    list<DtPartida *> getDtPartidasSinFinalizar();
    Suscripcion * getSuscripcionActiva();
    map<float , DtPartida *> listarPartidasIndividuales(string nombre);
    string getNombreJugador();
    void eliminarJugadorVideojuego(string nombre);
    void agregarPartida(DtPartidaIndividual *dtPartida);
    void agregarPartidaMultijugador(DtPartidaMultijugador *dtPartida, map<string,Participa *> participantes);
    void agregarParticipacion(int id, Participa* participacion);

};
