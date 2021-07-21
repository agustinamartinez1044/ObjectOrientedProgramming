#include "../../include/clases/PartidaIndividual.h"

PartidaIndividual::PartidaIndividual() : Partida() {}

PartidaIndividual::~PartidaIndividual() {
	delete continuacionde;
}

PartidaIndividual::PartidaIndividual
	(int id, DtFechaHora *comienzo, PartidaIndividual * continuacionde): Partida(id, comienzo) {
		this->continuacionde = continuacionde;
}

PartidaIndividual::PartidaIndividual(DtPartidaIndividual * dtPartida) {
		this->setId(dtPartida->getId());
		this->setComienzo(dtPartida->getComienzo());
		this->setFinal(NULL);
		this->setDuracion(-1);
}

PartidaIndividual * PartidaIndividual::getContinuacionDe() {
    return this->continuacionde;
}

bool PartidaIndividual::ContinuaPartidaAnterior() {
	return this->continuacionde != NULL;
}

DtPartida * PartidaIndividual::getDtPartida() {
	return new DtPartida();
}
