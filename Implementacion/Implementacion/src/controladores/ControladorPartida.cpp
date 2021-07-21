#include "../../include/controladores/ControladorPartida.h"

IIniciarPartida::~IIniciarPartida() {}

IFinalizarPartida::~IFinalizarPartida() {}

IAbandonarPartidaMultijugador::~IAbandonarPartidaMultijugador() {}

ControladorPartida *ControladorPartida::instancia = NULL;

ControladorPartida::ControladorPartida() {}

ControladorPartida::~ControladorPartida() {
    partidas.clear();
}

ControladorPartida *ControladorPartida::getInstancia() {
    if( instancia == nullptr)
        instancia = new ControladorPartida();
    return instancia;
}

list<DtPartidaMultijugador*> ControladorPartida::listarPartidasNoFinalizadasMultijugador() {
    list<DtPartidaMultijugador*> listas;
    ControladorUsuario * cu = ControladorUsuario::getInstancia();
    Jugador * jugador = cu->getJugadorActivo();
    list<int> lista = jugador->listarPartidasNoFinalizadasMultijugador();
    list<int>::iterator it;
    for(it = lista.begin(); it != lista.end(); ++it){
        int id = *it;
        DtPartida * dtPartida = partidas.find(id)->second->getDtPartida();
        DtPartidaMultijugador *esDtPartidaMultijugador = dynamic_cast<DtPartidaMultijugador *>(dtPartida);
        if (esDtPartidaMultijugador) listas.push_back(esDtPartidaMultijugador);
    }

    return listas;
}

void ControladorPartida::elegirPartidaIndividual(int id) {}

list<DtPartida *> ControladorPartida::listarPartidasNoFinalizadasDelJugador(){
    ControladorUsuario * cu;
	cu = ControladorUsuario::getInstancia();
    Jugador * jugador = cu->getJugadorActivo();

    list<DtPartida*> partidas = jugador->listarPartidasNoFinalizadasDelJugador();

    return partidas;
}

void ControladorPartida::finalizarPartida(int id) {
    ControladorUsuario *cu = ControladorUsuario::getInstancia();
    map<int,Partida*>  partidas = this->partidas;
    std::map<int,Partida*>::iterator it;
    it = partidas.find(id);
    Partida * partida = it->second;
    partida->finalizarPartida(cu->getFechaSistema());

    PartidaMultijugador *esPartidaMultijugador = dynamic_cast<PartidaMultijugador *>(partida);

    if (esPartidaMultijugador) esPartidaMultijugador->finalizarPartidaMultijugador();
}

list<DtVideojuego *> ControladorPartida::listarVideojuegosConSuscripcionActiva(){
    ControladorUsuario * cu;
	cu = ControladorUsuario::getInstancia();
    Jugador *jugador = cu->getJugadorActivo();
    list<DtVideojuego *> lista = jugador->listarVideojuegosConSuscripcionActivas();
    return lista;
}

map<float , DtPartida *> ControladorPartida::listarPartidasIndividuales(string nombre){
    ControladorUsuario * cu;
	cu = ControladorUsuario::getInstancia();
    Jugador *jugador = cu->getJugadorActivo();
    map<float, DtPartida *> partidas = jugador->listarPartidasIndividuales(nombre);
    return partidas;
}

list<string> ControladorPartida::listarNicknames(string nombre){
    ControladorVideojuego * cu;
	cu = ControladorVideojuego::getInstancia();
    Videojuego * videojuego = cu->getVideojuego(nombre);
    cout << videojuego; 
    list<string> lista = videojuego->getNicknameJugadoresSuscriptos();
    ControladorUsuario * cu2;
    cu2 = ControladorUsuario::getInstancia();
    string jugador = cu2->getJugadorActivo()->getNickname();
    lista.remove(jugador);

    return lista;
}

void ControladorPartida::confirmarPartida(DtPartida * dtPartida, string nombreVideojuego){
    ControladorUsuario * cu;
    cu = ControladorUsuario::getInstancia();
    Jugador * jugador = cu->getJugadorActivo();
    DtPartidaIndividual *esPartidaIndividual = dynamic_cast<DtPartidaIndividual * >(dtPartida);
    if(esPartidaIndividual){
        jugador->confirmarInicioPartidaIndividual(esPartidaIndividual,nombreVideojuego);   
    }
    else{
        DtPartidaMultijugador *esPartidaMultijugador = dynamic_cast<DtPartidaMultijugador * >(dtPartida);
        list<string> nicknames = esPartidaMultijugador->getNicknames();
        list<string>::iterator iter;
        map<string,Participa *> participantes;

        for(iter = nicknames.begin(); iter != nicknames.end(); ++iter) {
            Jugador * participante = cu->getJugador(*iter);
            JugadorVideojuego* jv = participante->buscarParVideojuego(nombreVideojuego);
            Participa* parti = new Participa();
            participantes.insert(std::pair<string,Participa *>(participante->getNickname(),parti));
            int id =dtPartida->getId();
            jv->agregarParticipacion(id, parti);
        
        }

        jugador->confirmarInicioPartidaMultijugador(esPartidaMultijugador,nombreVideojuego, participantes);

    }
    int id = dtPartida->getId();
    Partida * PartidaNueva = jugador->getJugadorVideojuegos().find(nombreVideojuego)->second->getPartidas().find(id)->second; 
    this->partidas.insert(std::pair<int , Partida *>(id,PartidaNueva)); 

}

void ControladorPartida::abandonarPartidaMultijugador(int identificador) {
    ControladorUsuario * cu = ControladorUsuario::getInstancia();
    Jugador * jugador = cu->getJugadorActivo();

    map<int,Partida *>::iterator itPartida = partidas.find(identificador);

    if (itPartida != partidas.end()) {
        PartidaMultijugador * partida = dynamic_cast<PartidaMultijugador*>(itPartida->second);

        map<string,Participa *> participantes = partida->getParticipantes();
        map<string,Participa *>::iterator itParticipacion = participantes.find(jugador->getNickname());

        if (itParticipacion != participantes.end()) {
            itParticipacion->second->setHoraAbandono(cu->getFechaSistema());
        }
    }
}

void ControladorPartida::setIdentificador(int id) {
    this->identificador = id;
}

int ControladorPartida::getIdentificador() {
    return this->identificador;
}

map<int,Partida *> ControladorPartida::getPartidas(){
    return partidas;
}
