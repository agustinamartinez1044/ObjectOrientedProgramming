#include "../../include/clases/Desarrollador.h"

Desarrollador::Desarrollador() {}

Desarrollador::~Desarrollador() {
    videojuegos.clear();
    estadisticas.clear();
}

Desarrollador::Desarrollador(DtDesarrollador * datos) : Usuario(datos->getEmail() , datos->getContrasena()) {
    this->empresa = datos->getEmpresa(); 
}

char Desarrollador::getTipo(){
    return 'd';
}
string Desarrollador::getEmpresa() {
    return this->empresa;
}

void Desarrollador::setEmpresa(string empresa) {
    this->empresa = empresa;
}

void Desarrollador::setEstadisticas(map<string, Estadistica*> estadisticas) {
    this->estadisticas = estadisticas;
}

map<string, Estadistica*> Desarrollador::getEstadisticas() {
    return this->estadisticas;
}

map<string,Videojuego*> Desarrollador::getVideojuegos() {
    return videojuegos;
}

void Desarrollador::agregarVideojuego(Videojuego * videojuego) {
    string nombreVideojuego = videojuego->getNombre();

    videojuegos.insert(pair<string,Videojuego*>(nombreVideojuego, videojuego));
}

// dss eliminar videojuego
list<DtVideojuego *> Desarrollador::listarVideojuegosSinPartidasActivas(){
    map<string,Videojuego*>::iterator it; 
	list<DtVideojuego *> resVideojuegos;
    Videojuego *vj;
    for (it = videojuegos.begin(); it != videojuegos.end(); it++){
        vj = it->second;
        bool tienePartidas = vj->tienePartidasActivas();
        if(!tienePartidas){
            DtVideojuego *dtVideojuego = new DtVideojuego
                (
                    vj->getNombre(), vj->getDescripcion(),
                    vj->getCostoMensual(), vj->getCostoTrimestral(),
                    vj->getCostoVitalicio(), vj->getCostoAnual()
                );
            resVideojuegos.push_back(dtVideojuego);
        }    
    }
	return resVideojuegos;
}


list<DtVideojuego *> Desarrollador::listarVideojuegosDelDesarrollador() {
    list<DtVideojuego *> lista;
    map<string,Videojuego *>::iterator itr;
    DtVideojuego *dtVideojuego;
    for(itr = videojuegos.begin(); itr != videojuegos.end(); ++itr){
        dtVideojuego = new DtVideojuego
            (
                itr->second->getNombre(), itr->second->getDescripcion(),
                itr->second->getCostoMensual(), itr->second->getCostoTrimestral(),
                itr->second->getCostoAnual(), itr->second->getCostoVitalicio()
            );
        lista.push_back(dtVideojuego);
    }
    return lista;
}

void Desarrollador::eliminarLinkDesarrolladorAVideojuego(string nombre) {
    videojuegos.erase(nombre);
}

void Desarrollador::setVideojuego(Videojuego *videojuego ){
    videojuegos.insert
        (
            pair<string, Videojuego *>(videojuego->getNombre(), videojuego)
        );
}
