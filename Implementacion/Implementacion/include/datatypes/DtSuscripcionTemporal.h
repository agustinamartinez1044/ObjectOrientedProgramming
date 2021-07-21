#pragma once

#include "./DtSuscripcion.h"

class DtSuscripcionTemporal: public DtSuscripcion {
    private:
        int mesesValida;
        bool cancelada;
    public:
        DtSuscripcionTemporal(
            DtFechaHora *fechaActivacion,
            TipoPago metodoPago,
            float pago,
            bool activa,
            int mesesValida,
            bool cancelada
        );
        DtSuscripcionTemporal();
        ~DtSuscripcionTemporal();

        bool getCancelada() const;
        int getMesesValida() const;
};
