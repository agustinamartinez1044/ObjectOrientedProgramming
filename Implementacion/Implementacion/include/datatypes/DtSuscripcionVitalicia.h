#pragma once

#include "./DtSuscripcion.h"

class DtSuscripcionVitalicia: public DtSuscripcion {
    public:
        DtSuscripcionVitalicia(
            DtFechaHora *fechaActivacion,
            TipoPago metodoPago,
            float pago,
            bool activa
        );
        DtSuscripcionVitalicia();
        ~DtSuscripcionVitalicia();
};
