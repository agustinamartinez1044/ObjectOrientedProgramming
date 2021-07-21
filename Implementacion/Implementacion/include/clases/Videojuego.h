#pragma once

#include <iostream>
#include <map>
#include <list>

#include "./Suscripcion.h"
#include "./Desarrollador.h"
#include "./JugadorVideojuego.h"
#include "./Puntua.h"

#include "../datatypes/DtVideojuego.h"

class Desarrollador;
class Categoria;


using namespace std;

class Videojuego {
	private:

		string nombre;
		string descripcion;

		float costoMensual;
		float costoTrimestral;
		float costoVitalicio;
		float costoAnual;

		Desarrollador * creador;
		map<string,Categoria *> categorias;
		map<string,JugadorVideojuego *> jugadoresvideojuego;
		list<Puntua *> puntuaciones;

	public:
		Videojuego();
		Videojuego(string nombre, string descripcion,
		float costoMensual,
		float costoTrimestral,
		float costoVitalicio,
		float costoAnual,
		Desarrollador * creador,
		map<string,Categoria *> categorias);
		Videojuego(DtVideojuego *videojuego, Desarrollador * creador, map<string,Categoria *> categorias);
		~Videojuego();

		string getNombre();
		string getDescripcion();
		float getCostoMensual();
		float getCostoTrimestral();
		float getCostoVitalicio();
		float getCostoAnual();
		float getPuntajePromedio();
		Desarrollador * getCreador();
		map<string,Categoria *> getCategorias();
		map<string,JugadorVideojuego *>  getJugadoresVideojuego();
		list<Puntua *> getPuntuaciones();

		void setNombre(string nombre);
		void setDescripcion(string descripcion);
		void setCostoMensual(float costoMensual);
		void setCostoTrimestral(float costoTrimestral);
		void setCostoVitalicio(float costoVitalicio);
		void setCostoAnual(float costoAnual);
		void setCreador(Desarrollador * creador);
		void setCategorias(map<string,Categoria *> categorias);
		void setJugadoresVideojuego(map<string,JugadorVideojuego *> jugadoresvideojuego);
		void setPuntuaciones(list<Puntua *> puntuaciones);
		void agregarPuntua(Puntua * puntua);
		bool tienePartidasActivas();
		void agregarCategoria(Categoria *categoria);
		void consultarEstadisticas(Videojuego *videojuego);
		void eliminarVideojuego(string nombre);
		list<string> getNicknameJugadoresSuscriptos();
		void setParJV(string nickname,  JugadorVideojuego * jv);
};
