#include "../../include/clases/Partida.h"

Partida::Partida() {}

Partida::Partida(int id, DtFechaHora *comienzo){
    this->id = id;
    this->comienzo = comienzo;
    this->duracion = -1;
}

Partida::~Partida() {
    delete comienzo;
    delete final;
}

int Partida::getId() {
    return this->id;
}

DtFechaHora *Partida::getComienzo() {
    return this->comienzo;
}

DtFechaHora *Partida::getFinal() {
    return this->final;
}

float Partida::getDuracion() {
    return this->duracion;
}

void Partida::setId(int id) {
    this->id = id;
}

void Partida::setComienzo(DtFechaHora *comienzo) {
    this->comienzo = comienzo;
}

void Partida::setFinal(DtFechaHora *final) {
    this->final = final;
}

void Partida::setDuracion(float duracion) {
    this->duracion = duracion;
}

bool Partida::noFinalizo(){
    return this->getDuracion() == -1;
}

float Partida::calcularDuracion(DtFechaHora * comienzo, DtFechaHora * final){
    float anio = final->getAnio() - comienzo->getAnio();
    float mes = final->getMes() - comienzo->getMes();
    float dia = final->getDia()- comienzo->getDia();
    float hora =  final->getHora() - comienzo->getHora();
    float minutos = final->getMinutos() - comienzo->getMinutos();
    float duracion = anio*365*24 + mes*30*24 + dia*24 + hora + (minutos/60);
    return duracion;
}

void Partida::finalizarPartida(DtFechaHora * fecha) {
    this->final = fecha;
    DtFechaHora * comienzo = this->getComienzo();
    DtFechaHora * final = this->getFinal();
    this->duracion = calcularDuracion(comienzo, final);
}

float Partida::getClaveFinalizacion(){
    float anio =  final->getAnio(); 
    float mes = final->getAnio();
    float dia = final->getDia();
    float hora =  final->getHora(); 
    float minutos = final->getMinutos(); 
    float ClaveFinalizacion = (anio*365*24*60*60 + mes*30*24*60*60 + dia*24*60*60 + hora*60*60 + minutos*60);
    return ClaveFinalizacion;
}	
