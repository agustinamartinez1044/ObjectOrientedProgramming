#include <iostream>
using namespace std;
#include "../../include/datatypes/DtCategoria.h"

DtCategoria::DtCategoria(){}
DtCategoria::DtCategoria(string nombre, string descripcion, TipoCategoria tipo){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}
DtCategoria::~DtCategoria(){}

string DtCategoria::getNombre() const{
    return this->nombre;
}

string DtCategoria::getDescripcion() const{
    return this->descripcion;
}

TipoCategoria DtCategoria::getTipoCategoria() const{
    return this->tipo;
}

ostream &operator<<(ostream &os, const DtCategoria &categoria) {
    string nombreTipoCategoria;
    TipoCategoria tipoCategoria = categoria.getTipoCategoria();

    if (tipoCategoria == Genero) {
        nombreTipoCategoria = "Género";
    } else if (tipoCategoria == Plataforma) {
        nombreTipoCategoria = "Plataforma";
    } else {
        nombreTipoCategoria = "Otro tipo";
    }

    os << categoria.getNombre() << " (Tipo: " << nombreTipoCategoria << ")";
    return os;
}
