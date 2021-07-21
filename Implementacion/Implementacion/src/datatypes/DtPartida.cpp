#include "../../include/datatypes/DtPartida.h"

DtPartida::DtPartida(){}

DtPartida::DtPartida(int id, DtFechaHora *comienzo, string videojuego) {
  this->id = id;
  this->comienzo = comienzo;
  this->videojuego = videojuego;
}

DtPartida::DtPartida(int id, DtFechaHora *comienzo, DtFechaHora *final, float duracion) {
  this->id = id;
  this->comienzo = comienzo;
  this->final = final;
  this->duracion = duracion;

}

DtPartida::~DtPartida() {}

int DtPartida::getId() const {
  return this->id;
}
DtFechaHora *DtPartida::getComienzo() const {
  return this->comienzo;
}
DtFechaHora *DtPartida::getFinal() const {
  return this->final;
}

float DtPartida::getDuracion() const {
  return this->duracion;
}

string DtPartida::getVideojuego() const {
  return this->videojuego;
}

ostream &operator<<(ostream &os, const DtPartida * partida){
    partida->print(os);
    return os;
}


void DtPartida::print(ostream &os) const {

}
