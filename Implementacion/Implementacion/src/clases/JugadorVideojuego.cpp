#include "../../include/clases/JugadorVideojuego.h"

JugadorVideojuego::JugadorVideojuego(){}

JugadorVideojuego::JugadorVideojuego(Jugador * jugador,Videojuego * videojuego){
    this->jugador = jugador;
    this->videojuego = videojuego;
}

JugadorVideojuego::~JugadorVideojuego(){
    partidas.clear();
    participantes.clear();
    suscripciones.clear();
    delete jugador;
    delete videojuego;
}

map<int,Partida*> JugadorVideojuego::getPartidas(){
    return this->partidas;
}

Jugador * JugadorVideojuego::getJugador(){
    return this->jugador;
}

Videojuego * JugadorVideojuego::getVideojuego(){
    return this->videojuego;
}

list<Suscripcion*> JugadorVideojuego::getSuscripciones(){
    return this->suscripciones;
}
 map<int,Participa*> JugadorVideojuego::getParticipantes(){
    return this->participantes;
}

void JugadorVideojuego::setPartidas(map<int,Partida*> partidas){
    this->partidas = partidas;
}

void JugadorVideojuego::setJugador(Jugador * jugador){
    this->jugador = jugador;
}

void JugadorVideojuego::setVideojuego(Videojuego * videojuego){
    this->videojuego = videojuego;
}

void JugadorVideojuego::setSuscripciones(list<Suscripcion*> suscripciones){
    this->suscripciones = suscripciones;
}

void JugadorVideojuego::setParticipantes(map<int,Participa*> participantes){
    this->participantes = participantes;
}

list<DtPartida *> JugadorVideojuego::getDtPartidasSinFinalizar(){
    map<int,Partida *>::iterator it;
    list<DtPartida *> res;
    Partida *partida;

    for(it = this->partidas.begin(); it != this->partidas.end(); ++it){
        partida = it->second;

        if (partida->noFinalizo()){
            string nombreVideojuego = videojuego->getNombre();
            PartidaIndividual *esPartidaIndividual = dynamic_cast<PartidaIndividual *>(partida);

            if (esPartidaIndividual) {
                PartidaIndividual *parInd = esPartidaIndividual;
                bool esContinuacionAnterior = (esPartidaIndividual->getContinuacionDe() == NULL);

                DtPartidaIndividual *dtPartida = new DtPartidaIndividual
                    (
                        esPartidaIndividual->getId(), esPartidaIndividual->getComienzo(), nombreVideojuego, esContinuacionAnterior
                    );
                res.push_back(dtPartida);
            }
            else{
                PartidaMultijugador * partidaMult = dynamic_cast<PartidaMultijugador *>(partida);
                map<string,Participa *>::iterator itr;
                map<string, Participa *> participante = partidaMult->getParticipantes();
                list<string> lista;
                for(itr = participante.begin(); itr != participante.end();++itr) {
                    lista.push_back(itr->first);
                }
                
                DtPartidaMultijugador *dtPartida = new DtPartidaMultijugador
                    (
                        partidaMult->getId(),partidaMult->getComienzo(),nombreVideojuego, partidaMult->getTransmitidaEnVivo(), lista
                    );
                res.push_back(dtPartida);
            }
        }
    }
    return res;
}

Suscripcion * JugadorVideojuego::getSuscripcionActiva(){
    list<Suscripcion*> suscripciones = this->getSuscripciones();
    list<Suscripcion*>::iterator iter;
    Suscripcion * suscripcionActiva = NULL;

    for(iter = suscripciones.begin(); iter != suscripciones.end(); ++iter){
        if ((*iter)->getEsActiva()) {
            suscripcionActiva = *iter;
        }
    }

    return suscripcionActiva;
}

map<float , DtPartida *> JugadorVideojuego::listarPartidasIndividuales(string nombre){
    map<float , DtPartida *> res;
    map<int,Partida *> partidas = this->partidas;
    map<int,Partida *>::iterator iter;

    for(iter = partidas.begin(); iter != partidas.end(); ++iter){
        Partida * partida = iter->second;
        PartidaIndividual * esPartidaIndividual = dynamic_cast<PartidaIndividual *>(partida);
        if(esPartidaIndividual && (esPartidaIndividual->getDuracion() != -1)){
            float claveFinalizacion = partida->getClaveFinalizacion();
            DtPartida *dtPartida = new DtPartida
            (esPartidaIndividual->getId(),esPartidaIndividual->getComienzo()
            ,esPartidaIndividual->getFinal(), esPartidaIndividual->getDuracion());
            res.insert( std::pair<float , DtPartida *>(claveFinalizacion,dtPartida) );
        }
    }
    return res;
}

string JugadorVideojuego::getNombreJugador(){
    Jugador * jugador = this->getJugador();
    return  jugador->getNickname();

}

bool JugadorVideojuego::hayPartidasActivas() {
    return !(0 != getDtPartidasSinFinalizar().size());
}


void JugadorVideojuego::eliminarJugadorVideojuego(string nombre){
    suscripciones.clear();
    participantes.clear();
    partidas.clear();
    this->jugador->eliminarLinkJugadorAJugadorVideojuego(nombre);
}

void JugadorVideojuego::agregarSuscripcion(Suscripcion * nuevaSuscripcion) {
    suscripciones.push_back(nuevaSuscripcion);
}

void JugadorVideojuego::agregarPartida(DtPartidaIndividual *dtPartida){ 
    Partida * partida = new PartidaIndividual(dtPartida);
    int identificador = partida->getId();
    partidas.insert( std::pair<int , Partida *>(identificador,partida));
}

void JugadorVideojuego::agregarPartidaMultijugador(DtPartidaMultijugador *dtPartida,map<string,Participa *> participantes){
    Partida * partida = new PartidaMultijugador(dtPartida, participantes);
    int identificador = partida->getId();
    partidas.insert( std::pair<int , Partida *>(identificador,partida));
}

void JugadorVideojuego::agregarParticipacion(int id, Participa* participacion){
    participantes.insert(pair<int,Participa*>(id,participacion));

}