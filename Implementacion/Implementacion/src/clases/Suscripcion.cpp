#include "../../include/clases/Suscripcion.h"

Suscripcion::Suscripcion() {}

Suscripcion::Suscripcion(DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool esActiva) {
    this->fechaActivacion = fechaActivacion;
    this->metodoPago = metodoPago;
    this->pago = pago;
    this->esActiva = esActiva;
}

Suscripcion::~Suscripcion(){
    delete fechaActivacion;
}

DtFechaHora *Suscripcion::getFechaActivacion() {
    return this->fechaActivacion;
}

void Suscripcion::setFechaActivacion(DtFechaHora *fechaActivacion) {
    this->fechaActivacion = fechaActivacion;
}

TipoPago Suscripcion::getMetodoPago() {
    return this->metodoPago;
}

void Suscripcion::setMetodoPago(TipoPago metodoPago) {
    this->metodoPago = metodoPago;
}

float Suscripcion::getPago() {
    return this->pago;
}

void Suscripcion::setPago(float pago) {
    this->pago = pago;
}

bool Suscripcion::getEsActiva() {
    return this->esActiva;
}

void Suscripcion::setEsActiva(bool activa) {
    this->esActiva = activa;
}
