#pragma once

#include <iostream>

#include "Participa.h"

class Jugador;
class JugadorVideojuego;

using namespace std;

class Puntua {
    private :
        int puntaje;
        Jugador *puntuador;
    public :
        Puntua();
        Puntua(Jugador * jugador, int puntaje);
        ~Puntua();

        int getPuntaje();
        Jugador * getPuntuador();

        void setPuntuador(Jugador * jugador);
        void setPuntaje(int puntaje);
};
