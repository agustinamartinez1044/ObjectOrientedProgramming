#pragma once

#include <map>
#include <list>
#include <iterator>
#include <iostream>

#include "../datatypes/DtCategoria.h"
#include "../enumerados/TipoCategoria.h"

class Videojuego;

using namespace std;

class Categoria {
    private :
        string nombre;
        string descripcion;
        TipoCategoria tipo;
        map<string,Videojuego *> videojuegos; 
    public :
    Categoria();
    Categoria(string, string, TipoCategoria, Videojuego *);
    Categoria(DtCategoria*);
    ~Categoria();

    //operaciones DSS
    void eliminarLinkCategoriaAVideojuego(string nombre);
    list<Videojuego *> getVideojuegos();
    string getNombre();
    string getDescripcion();
    TipoCategoria getTipoCategoria();
    void agregarVideoJuego(string nombre, Videojuego *videojuego);
 
};
