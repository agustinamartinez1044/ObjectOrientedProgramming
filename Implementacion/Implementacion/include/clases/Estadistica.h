#pragma once

#include "Categoria.h"
#include <iostream>

#include "../datatypes/DtEstadistica.h"
#include "../datatypes/DtVideojuego.h"

//#include "Videojuego.h"
#include "./JugadorVideojuego.h"

using namespace std;

class Videojuego;

class Estadistica {
  private:
    string nombre;
    string descripcion;
  public:
    Estadistica();
    virtual ~Estadistica();

    string getNombre();
    string getDescripcion();
    void setNombre(string nombre);
    void setDescripcion(string descripcion);

    DtEstadistica getDtEstadistica();
    virtual float calcular(Videojuego *videojuego);
};
