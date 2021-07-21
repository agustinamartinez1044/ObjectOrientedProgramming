#include "../../include/clases/SuscripcionTemporal.h"

SuscripcionTemporal::SuscripcionTemporal() { }

SuscripcionTemporal::SuscripcionTemporal
	(
		int mesesValida,
        bool cancelada,
		DtFechaHora *fechaActivacion,
        TipoPago metodoPago,
		float pago,
        bool esActiva
	) : Suscripcion(fechaActivacion, metodoPago, pago, esActiva) {
	this->mesesValida = mesesValida;
	this->cancelada = cancelada;
}

SuscripcionTemporal::SuscripcionTemporal(DtSuscripcionTemporal * dtSuscripcion) :
	Suscripcion(
		dtSuscripcion->getFechaActivacion(),
		dtSuscripcion->getMetodoPago(),
		dtSuscripcion->getPago(),
		dtSuscripcion->getActiva()
	) {
	this->mesesValida = dtSuscripcion->getMesesValida();
	this->cancelada = dtSuscripcion->getCancelada();
}

SuscripcionTemporal::~SuscripcionTemporal() {}

int SuscripcionTemporal::getMesesValida() {
	return this->mesesValida;
}

void SuscripcionTemporal::setMesesValida(int mesesValida) {
	this->mesesValida = mesesValida;
}

bool SuscripcionTemporal::getCancelada() {
	return this->cancelada;
}

void SuscripcionTemporal::setCancelada(bool cancelada) {
	this->cancelada = cancelada;
}
