#pragma once

#include <iostream>

#include "./DtFechaHora.h"
#include "../enumerados/TipoPago.h"

class DtSuscripcion {
    private:
        DtFechaHora *fechaActivacion;
        TipoPago metodoPago;
        float pago;
        bool activa;
    public:
		DtSuscripcion();
		DtSuscripcion(
            DtFechaHora *fechaActivacion,
            TipoPago metodoPago,
            float pago,
            bool activa
        );
		virtual ~DtSuscripcion();

        DtFechaHora *getFechaActivacion() const;
        virtual TipoPago getMetodoPago() const;
        virtual float getPago() const;
        virtual bool getActiva() const;
};
