#pragma once

#include "../datatypes/DtSuscripcionVitalicia.h"
#include "./Suscripcion.h"

class SuscripcionVitalicia : public Suscripcion {
public:
    SuscripcionVitalicia();
    SuscripcionVitalicia(DtSuscripcionVitalicia * dtSuscripcion);
    SuscripcionVitalicia(DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool esActiva);
    ~SuscripcionVitalicia();
};
