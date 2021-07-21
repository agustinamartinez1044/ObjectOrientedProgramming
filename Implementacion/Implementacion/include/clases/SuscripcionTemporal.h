#pragma once

#include <iostream>

using namespace std;

#include "../datatypes/DtSuscripcionTemporal.h"
#include "Suscripcion.h"

class SuscripcionTemporal : public Suscripcion {
private:
    int mesesValida;
    bool cancelada;
public:
    SuscripcionTemporal();
    SuscripcionTemporal(DtSuscripcionTemporal * dtSuscripcion);
    SuscripcionTemporal(int mesesValida, bool cancelada, DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool esActiva);
    ~SuscripcionTemporal();

    int getMesesValida();
    bool getCancelada();
    void setMesesValida(int mesesValida);
    void setCancelada(bool cancelada);
};
