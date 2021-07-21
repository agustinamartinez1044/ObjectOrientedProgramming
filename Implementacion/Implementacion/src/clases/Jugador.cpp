#include "../../include/clases/Jugador.h"
#include <string>

Jugador::Jugador(){}

Jugador::Jugador(DtJugador *datos) : Usuario(datos->getEmail(),datos->getContrasena()){
    this->nickname = datos->getNickname();
    this->descripcion = datos->getDescripcion();
}

Jugador::~Jugador() {}

char Jugador::getTipo(){
    return 'j';
}

string Jugador::getNickname() {
    return this->nickname;
}

string Jugador::getDescripcion() {
    return this->descripcion;
}

void Jugador::setNickname(string nickname) {
    this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Jugador::eliminarLinkJugadorAJugadorVideojuego(string nombre) {
    jugadorVideojuegos.erase(nombre);
}

JugadorVideojuego * Jugador::buscarParVideojuego(string nombre) {
    map<string,JugadorVideojuego*>::iterator it = jugadorVideojuegos.find(nombre);

    if(it != jugadorVideojuegos.end()) {
        return it->second;
    } else {
        return NULL;
    }
}

StatusSuscripcion Jugador::getStatusSuscripcionVideojuego(string nombre) {
    JugadorVideojuego * jugadorVideojuego = this->buscarParVideojuego(nombre);
    StatusSuscripcion statusSuscripcion = Ninguna;

    if (jugadorVideojuego != NULL) {
        Suscripcion * suscripcion = jugadorVideojuego->getSuscripcionActiva();

        if (suscripcion != NULL) {
            SuscripcionVitalicia *vitalicia = dynamic_cast<SuscripcionVitalicia*>(suscripcion);

            if (vitalicia != NULL) {
                statusSuscripcion = Vitalicia;
            } else {
                statusSuscripcion = Temporal;
            }
        }
    }

    return statusSuscripcion;
}

void Jugador::cancelarSuscripcion(string nombreVideojuego) {
    JugadorVideojuego * jugadorVideojuego = this->buscarParVideojuego(nombreVideojuego);

    if (jugadorVideojuego != NULL) {
        Suscripcion * suscripcion = jugadorVideojuego->getSuscripcionActiva();

        suscripcion->setEsActiva(false);
    }
}

void Jugador::confirmarSuscripcion(Videojuego * videojuego, DtSuscripcion * dtSuscripcion) {
    Suscripcion * nuevaSuscripcion;
    JugadorVideojuego * parJugadorVideojuego = this->buscarParVideojuego(videojuego->getNombre());

    DtSuscripcionVitalicia * vitalicia = dynamic_cast<DtSuscripcionVitalicia*>(dtSuscripcion);

    if (vitalicia != NULL) {
        nuevaSuscripcion = new SuscripcionVitalicia(vitalicia);
    } else {
        DtSuscripcionTemporal * temporal = dynamic_cast<DtSuscripcionTemporal*>(dtSuscripcion);

        nuevaSuscripcion = new SuscripcionTemporal(temporal);
    }

    if (parJugadorVideojuego == NULL) {
        JugadorVideojuego * nuevoParJugadorVideojuego = new JugadorVideojuego(this, videojuego);

        jugadorVideojuegos.insert(
            pair<string,JugadorVideojuego*>(
                videojuego->getNombre(),
                nuevoParJugadorVideojuego
            )
        );
         videojuego->setParJV( this->getNickname(), nuevoParJugadorVideojuego);

        
        nuevoParJugadorVideojuego->agregarSuscripcion(nuevaSuscripcion);
    } else {
        parJugadorVideojuego->agregarSuscripcion(nuevaSuscripcion);
    }
}

list<DtPartida *> Jugador::listarPartidasNoFinalizadasDelJugador() {
    map<string,JugadorVideojuego*>::iterator it;
    list<DtPartida *> res;
    list<DtPartida *> aux;
    for(it = this->jugadorVideojuegos.begin(); it != this->jugadorVideojuegos.end(); ++it){
        aux = it->second->getDtPartidasSinFinalizar();
        res.merge(aux);
    }
    return res;
}

list<DtVideojuego *> Jugador::listarVideojuegosConSuscripcionActivas(){
    list<DtVideojuego *> lista;
	map<string,JugadorVideojuego*> jugadorVideojuegos = this->jugadorVideojuegos;
    map<string,JugadorVideojuego*>::iterator iter;

	for( iter = jugadorVideojuegos.begin(); iter != jugadorVideojuegos.end(); iter++) {
        JugadorVideojuego * jv = iter->second;
        Suscripcion * suscripcionActiva = jv->getSuscripcionActiva();
        if (suscripcionActiva != NULL){
            Videojuego *vj = jv->getVideojuego();
            DtVideojuego *dt = new DtVideojuego
                (
                    vj->getNombre(), vj->getDescripcion(),
                    vj->getCostoMensual(), vj->getCostoTrimestral(),
                    vj->getCostoVitalicio(), vj->getCostoAnual()
                );
            lista.push_back(dt);
        }
	}
    return lista;
}

map<float , DtPartida *> Jugador::listarPartidasIndividuales(string nombre){
    map<string,JugadorVideojuego*> jugadorVideojuegos = this->jugadorVideojuegos;
    map<string,JugadorVideojuego*>::iterator it = jugadorVideojuegos.find(nombre);
    return it->second->listarPartidasIndividuales(nombre);
}

void Jugador::confirmarInicioPartidaIndividual(DtPartidaIndividual *dtPartida, string nombre) {
    map<string,JugadorVideojuego*> jugadorVideojuegos = this->jugadorVideojuegos;
    map<string,JugadorVideojuego*>::iterator it = jugadorVideojuegos.find(nombre);
    it->second->agregarPartida(dtPartida);
}

void Jugador::confirmarInicioPartidaMultijugador(DtPartidaMultijugador *dtPartida, string nombre, map<string,Participa *> participantes){
    map<string,JugadorVideojuego*> jugadorVideojuegos = this->jugadorVideojuegos;
    map<string,JugadorVideojuego*>::iterator it = jugadorVideojuegos.find(nombre);

    it->second->agregarPartidaMultijugador(dtPartida, participantes);
}
//esto es una lista de identificadores que participa :)
list<int> Jugador::listarPartidasNoFinalizadasMultijugador() {
   list<int> lista;
   map<string,JugadorVideojuego*> jv = this->jugadorVideojuegos;
   map<string,JugadorVideojuego*>::iterator iter;
   for( iter = jv.begin(); iter != jv.end(); iter++) {
      map<int,Participa *> participaciones = iter->second->getParticipantes();
      map<int,Participa *>::iterator it;
      for( it = participaciones.begin(); it != participaciones.end(); it++) {
          if(it->second->getHoraAbandono() == NULL)
          lista.push_back(it->first);
      }
   }
   return lista;
}

map<string,JugadorVideojuego*>  Jugador::getJugadorVideojuegos(){
    return this->jugadorVideojuegos;
}
