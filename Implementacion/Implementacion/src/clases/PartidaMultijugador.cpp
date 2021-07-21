#include "../../include/clases/PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador() : Partida() {}

PartidaMultijugador::~PartidaMultijugador() {
	observadores.clear();
	participantes.clear();
}

PartidaMultijugador::PartidaMultijugador(int id, DtFechaHora *comienzo,bool transmitidaenvivo,
	map<string,Participa *> participantes, map<int,Observa*> observadores): Partida(id, comienzo) {
		this->transmitidaenvivo = transmitidaenvivo;
		this->participantes = participantes;
		this->observadores = observadores;
}

PartidaMultijugador::PartidaMultijugador(DtPartidaMultijugador *dtPartidaMultijugador, map<string,Participa *> participantes){
	this->setId(dtPartidaMultijugador->getId());
	this->setComienzo(dtPartidaMultijugador->getComienzo());
	this->transmitidaenvivo = dtPartidaMultijugador->getTransmitidaEnVivo();
	this->setFinal(NULL);
	this->participantes = participantes;
	this->setDuracion(-1);
}

bool PartidaMultijugador::getTransmitidaEnVivo() {
	return this->transmitidaenvivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool transmitidaenvivo) {
  	this->transmitidaenvivo = transmitidaenvivo;
}

map<string,Participa *> PartidaMultijugador::getParticipantes() {
  	return this->participantes;
}

void PartidaMultijugador::setParticipantes(map<string,Participa *> participantes) {
   	this->participantes = participantes;
}

map<int,Observa*> PartidaMultijugador::getObservadores() {
	return this->observadores;
}

void PartidaMultijugador::setObservadores(map<int,Observa*> observadores) {
   	this->observadores = observadores;
}

void PartidaMultijugador::finalizarPartidaMultijugador() {
	DtFechaHora * abandono = this->getFinal();
	map<string,Participa *> participantes = this->participantes;

		for(pair<string,Participa *> participa : participantes){
			if(participa.second->getHoraAbandono()== NULL)
			participa.second->setHoraAbandono(abandono);
		}
}

DtPartida * PartidaMultijugador::getDtPartida() {
	DtPartida *dt = new DtPartida(); 
	return dt;
}
