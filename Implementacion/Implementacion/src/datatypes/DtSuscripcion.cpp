#include "../../include/datatypes/DtSuscripcion.h"

DtSuscripcion::DtSuscripcion(){}

DtSuscripcion::DtSuscripcion(DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool activa){
    this->fechaActivacion = fechaActivacion;
    this->metodoPago = metodoPago;
    this->pago = pago;
    this->activa = activa;
}

DtSuscripcion::~DtSuscripcion(){}

DtFechaHora *DtSuscripcion::getFechaActivacion() const{
    return this->fechaActivacion;
}

TipoPago DtSuscripcion::getMetodoPago() const{
    return this->metodoPago;
}

float DtSuscripcion::getPago() const{
    return this->pago;
}

bool DtSuscripcion::getActiva() const{
    return this->activa;
}
