#pragma once

#include <iostream>

#include "../datatypes/DtSuscripcion.h"
#include "../datatypes/DtFechaHora.h"
#include "../enumerados/TipoPago.h"

using namespace std;

class Suscripcion {
private:
	DtFechaHora *fechaActivacion;
	TipoPago metodoPago;
	float pago;
	bool esActiva;
public:
	Suscripcion();
	Suscripcion(DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool esActiva);
	virtual ~Suscripcion();

	DtFechaHora *getFechaActivacion();
	TipoPago getMetodoPago();
	float getPago();
	bool getEsActiva();
	virtual void setFechaActivacion(DtFechaHora *fechaActivacion);
	virtual void setMetodoPago(TipoPago metodoPago);
	virtual void setPago(float pago);
	virtual void setEsActiva(bool esActiva);
};
