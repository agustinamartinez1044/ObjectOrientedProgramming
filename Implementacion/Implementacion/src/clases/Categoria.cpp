#include "../../include/clases/Categoria.h"
#include <string>

Categoria::Categoria() {}

Categoria::~Categoria() {
    videojuegos.clear();
}

Categoria::Categoria(string nombre, string descripcion, TipoCategoria tipoCategoria, Videojuego *videojuego) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipoCategoria;
    this->videojuegos.insert(pair<string,Videojuego*>(nombre,videojuego));
}

Categoria::Categoria(DtCategoria * dtcategoria) {
    this->nombre = dtcategoria->getNombre();
    this->descripcion = dtcategoria->getDescripcion();
    this->tipo = dtcategoria->getTipoCategoria();
}

void Categoria::eliminarLinkCategoriaAVideojuego(string nombre){
    videojuegos.erase(nombre);
}

list<Videojuego *> Categoria::getVideojuegos(){
    list<Videojuego *> videojuegos;
    map<string,Videojuego *>::iterator itr;

    for (itr = this->videojuegos.begin(); itr != this->videojuegos.end(); ++itr) {
        videojuegos.insert(videojuegos.begin() , itr->second);
    }
    return videojuegos;
}
string Categoria::getNombre(){
    return this->nombre;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}

TipoCategoria Categoria::getTipoCategoria() {
    return this->tipo;
}

void Categoria::agregarVideoJuego(string nombre, Videojuego *videojuego){
    this->videojuegos.insert(pair<string,Videojuego*>(nombre,videojuego));
}
