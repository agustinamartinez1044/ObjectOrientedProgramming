#include "./Estadistica.h"

class EstadisticaCantidadSuscripciones : public Estadistica {
public:
	EstadisticaCantidadSuscripciones();
	~EstadisticaCantidadSuscripciones();
	float calcular(Videojuego *videojuego);
};
