#include "../../include/clases/EstadisticaCantidadSuscripciones.h"

EstadisticaCantidadSuscripciones::EstadisticaCantidadSuscripciones() : Estadistica() {
	this->setNombre("cantidad de suscripciones");
	this->setDescripcion("");
}

EstadisticaCantidadSuscripciones::~EstadisticaCantidadSuscripciones(){}

float EstadisticaCantidadSuscripciones::calcular(Videojuego *videojuego){ 
		return videojuego->getJugadoresVideojuego().size();
}
