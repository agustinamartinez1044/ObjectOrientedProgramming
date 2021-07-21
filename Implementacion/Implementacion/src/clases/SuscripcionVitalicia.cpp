#include "../../include/clases/SuscripcionVitalicia.h"

SuscripcionVitalicia::SuscripcionVitalicia() : Suscripcion() {}

SuscripcionVitalicia::SuscripcionVitalicia
	(
		DtFechaHora *fechaActivacion,
		TipoPago metodoPago,
		float pago,
		bool esActiva
	) : Suscripcion(fechaActivacion, metodoPago, pago, esActiva) {}

SuscripcionVitalicia::SuscripcionVitalicia(DtSuscripcionVitalicia * dtSuscripcion) :
	Suscripcion(
		dtSuscripcion->getFechaActivacion(),
		dtSuscripcion->getMetodoPago(),
		dtSuscripcion->getPago(),
		dtSuscripcion->getActiva()
	) {};

SuscripcionVitalicia::~SuscripcionVitalicia(){}
