#include "../../include/clases/EstadisticaHorasJugadas.h"

EstadisticaHorasJugadas::EstadisticaHorasJugadas() : Estadistica() {
	this->setNombre("horas jugadas");
	this->setDescripcion("");
}

EstadisticaHorasJugadas::~EstadisticaHorasJugadas(){}

float EstadisticaHorasJugadas::calcular(Videojuego *videojuego){
	float horasJugadas = 0;

	map<string, JugadorVideojuego*> jugadoresVideojuego = videojuego->getJugadoresVideojuego();
	for (pair<string, JugadorVideojuego*> par : jugadoresVideojuego) {

		map<int, Partida*> partidas = par.second->getPartidas();
		for (pair<int, Partida*> partida : partidas) {
			if (partida.second->getDuracion() != -1) {
				horasJugadas += partida.second->getDuracion();
			}
		}
	}
	return horasJugadas;
}
