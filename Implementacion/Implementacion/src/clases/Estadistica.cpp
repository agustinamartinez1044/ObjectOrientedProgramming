#include "../../include/clases/Estadistica.h"

Estadistica::Estadistica() {}

Estadistica::~Estadistica(){}

string Estadistica::getNombre() {
  return this->nombre;
}

void Estadistica::setNombre(string nombre) {
  this->nombre = nombre;
}

string Estadistica::getDescripcion() {
  return this->descripcion;
}

void Estadistica::setDescripcion(string descripcion) {
  this->descripcion = descripcion;
}

float Estadistica::calcular(Videojuego *videojuego){
  return 0;
}


// DtEstadistica Estadistica::getDtEstadistica() {
//   return DtEstadistica(this->nombre, this->descripcion, this->calcular());
// }
