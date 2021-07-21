#include "../../include/datatypes/DtSuscripcionTemporal.h"

DtSuscripcionTemporal::DtSuscripcionTemporal() : DtSuscripcion() {}

DtSuscripcionTemporal::~DtSuscripcionTemporal() {}

DtSuscripcionTemporal::DtSuscripcionTemporal(
    DtFechaHora *fechaActivacion,
    TipoPago metodoPago,
    float pago,
    bool activa,
    int mesesValida,
    bool cancelada
  ) : DtSuscripcion(fechaActivacion, metodoPago, pago, activa) {
    this->mesesValida = mesesValida;
    this->cancelada = cancelada;
}

bool DtSuscripcionTemporal::getCancelada() const{
    return this->cancelada;
}

int DtSuscripcionTemporal::getMesesValida() const{
    return this->mesesValida;
}
