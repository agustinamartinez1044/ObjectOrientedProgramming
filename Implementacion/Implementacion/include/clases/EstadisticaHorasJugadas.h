#include "./Estadistica.h"

class EstadisticaHorasJugadas : public Estadistica {

public:
	EstadisticaHorasJugadas();
	EstadisticaHorasJugadas(string nombre, string descripcion);
	~EstadisticaHorasJugadas();
	float calcular(Videojuego *videojuego);
};
