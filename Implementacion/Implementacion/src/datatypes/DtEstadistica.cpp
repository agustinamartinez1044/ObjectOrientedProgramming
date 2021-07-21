#include "../../include/datatypes/DtEstadistica.h"

DtEstadistica::DtEstadistica(){}

DtEstadistica::DtEstadistica(string nombre, string descripcion, float valor){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->valor = valor;
}

DtEstadistica::DtEstadistica(string nombre, string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}


DtEstadistica::~DtEstadistica(){}

string DtEstadistica::getNombre() const{
    return this->nombre;
}
string DtEstadistica::getDescripcion() const{
    return this->descripcion;
}
float DtEstadistica::getValor() const{
    return this->valor;
}

ostream &operator<<(ostream &os, const DtEstadistica &estadistica) {
    os << estadistica.getNombre() << ": " << fixed << setprecision(2) << estadistica.getValor();
    return os;
}
