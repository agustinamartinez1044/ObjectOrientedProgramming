#include "../../include/datatypes/DtVideojuego.h"

DtVideojuego::DtVideojuego(){}

DtVideojuego::DtVideojuego(string nombre, string descripcion, float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicio, float puntajePromedio){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costoMensual = costoMensual;
    this->costoTrimestral = costoTrimestral;
    this->costoAnual = costoAnual;
    this->costoVitalicio = costoVitalicio;
    this->puntajePromedio = puntajePromedio;
}

DtVideojuego::~DtVideojuego(){}

string DtVideojuego::getNombre() const{
    return this->nombre;
}

string DtVideojuego::getDescripcion() const{
    return this->descripcion;
}

float DtVideojuego::getCostoMensual() const{
    return this->costoMensual;
}

float  DtVideojuego::getCostoVitalicio() const{
    return this->costoVitalicio;
}

float  DtVideojuego::getCostoTrimestral() const{
    return this->costoTrimestral;
}

float  DtVideojuego::getCostoAnual() const{
    return this->costoAnual;
}

float DtVideojuego::getPuntajePromedio() const {
    return this->puntajePromedio;
}

ostream &operator<<(ostream &os, const DtVideojuego &videojuego) {
    os << "Nombre: " << videojuego.getNombre() << "\n"
    "Descripcion: " << videojuego.getDescripcion() << "\n"
    "Costo mensual: $" << fixed << setprecision(2) << videojuego.getCostoMensual() << "\n"
    "Costo trimestral: $" << fixed << setprecision(2) << videojuego.getCostoTrimestral() << "\n"
    "Costo anual: $" << fixed << setprecision(2) << videojuego.getCostoAnual() << "\n"
    "Costo vitalicio: $" << fixed << setprecision(2) << videojuego.getCostoVitalicio() << "\n"
    "Puntaje promedio: " << fixed << setprecision(1) << videojuego.getPuntajePromedio() << "\n";
    return os;
}
