#include "../../include/datatypes/DtSuscripcionVitalicia.h"

DtSuscripcionVitalicia::DtSuscripcionVitalicia() : DtSuscripcion() { }

DtSuscripcionVitalicia::~DtSuscripcionVitalicia() {}

DtSuscripcionVitalicia::DtSuscripcionVitalicia 
	(
		DtFechaHora *fechaActivacion, TipoPago metodoPago, float pago, bool activa
	) : DtSuscripcion(fechaActivacion, metodoPago, pago, activa) {}
