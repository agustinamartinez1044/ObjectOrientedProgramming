#include "../../include/clases/Puntua.h"

Puntua::Puntua() {}

Puntua::Puntua(Jugador * jugador, int puntaje) {
    this->puntuador = jugador;
    this->puntaje = puntaje;
}

Puntua::~Puntua() {}

int Puntua::getPuntaje() {
    return this->puntaje;
}

Jugador * Puntua::getPuntuador() {
    return this->puntuador;
}

void Puntua::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

void Puntua::setPuntuador(Jugador * jugador) {
    this->puntuador = jugador;
}
