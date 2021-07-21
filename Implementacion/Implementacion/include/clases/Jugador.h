#pragma once

#include <iostream>
#include <map>
#include <list>

#include "../datatypes/DtPartida.h"
#include "../datatypes/DtJugador.h"
#include "../enumerados/StatusSuscripcion.h"
#include "../datatypes/DtVideojuego.h"
#include "../datatypes/DtSuscripcionVitalicia.h"
#include "../datatypes/DtSuscripcionTemporal.h"

#include "Categoria.h"
#include "Usuario.h"
#include "Puntua.h"
#include "JugadorVideojuego.h"
#include "SuscripcionVitalicia.h"
#include "SuscripcionTemporal.h"

class Videojuego;

using namespace std;

class Jugador : public Usuario {
	private:
		string nickname;
		string descripcion;

		map<string,JugadorVideojuego*> jugadorVideojuegos;
	public:
		Jugador();
		Jugador(DtJugador *);
		~Jugador();

		char getTipo();
		string getNickname();
		string getDescripcion();
		void setNickname(string nickname);
		void setDescripcion(string descripcion);
		map<string,JugadorVideojuego*> getJugadorVideojuegos();
		list<DtVideojuego *> listarVideojuegos();
		void eliminarLinkJugadorAJugadorVideojuego(string nombre);
		void confirmarInicioPartidaIndividual(DtPartidaIndividual *dtPartida, string nombre);
		JugadorVideojuego * buscarParVideojuego(string nombre);
		StatusSuscripcion getStatusSuscripcionVideojuego(string nombre);
		void cancelarSuscripcion(string nombreVideojuego);
		void confirmarSuscripcion(Videojuego *videojuego, DtSuscripcion *dtSuscripcion);
		list<DtPartida *> listarPartidasNoFinalizadasDelJugador();
		list<DtVideojuego *> listarVideojuegosConSuscripcionActivas();
		map<float , DtPartida *> listarPartidasIndividuales(string nombre);
		list<int> listarPartidasNoFinalizadasMultijugador();
		void confirmarInicioPartidaMultijugador(DtPartidaMultijugador *dtPartida, string nombre, map<string,Participa *> participantes);
};
