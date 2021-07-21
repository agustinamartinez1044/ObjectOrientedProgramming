#include "../../include/clases/Videojuego.h"

Videojuego::Videojuego() {}

Videojuego::~Videojuego() {
	categorias.clear();
	jugadoresvideojuego.clear();
	puntuaciones.clear();
}

Videojuego::Videojuego(string nombre, string descripcion, float costoMensual,
	float costoTrimestral,
	float costoVitalicio,
	float costoAnual,
    Desarrollador * creador,
    map<string,Categoria *> categorias) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->costoMensual = costoMensual;
	this->costoTrimestral = costoTrimestral;
	this->costoVitalicio = costoVitalicio;
	this->costoAnual = costoAnual;
	this->creador = creador;
	this->categorias = categorias;
}

Videojuego::Videojuego
	(
		DtVideojuego *dtvideojuego, Desarrollador * creador,
		map<string,Categoria *> categorias
	){

	this->nombre = dtvideojuego->getNombre();
	this->descripcion = dtvideojuego->getDescripcion();
	this->costoMensual = dtvideojuego->getCostoMensual();
	this->costoTrimestral = dtvideojuego->getCostoTrimestral();
	this->costoVitalicio = dtvideojuego->getCostoVitalicio();
	this->costoAnual = dtvideojuego->getCostoAnual();
	this->creador = creador;
	this->categorias = categorias;
}


string Videojuego::getNombre() {
  	return this->nombre;
}

string Videojuego::getDescripcion() {
  	return this->descripcion;
}

float Videojuego::getCostoTrimestral() {
  	return this->costoTrimestral;
}

float Videojuego::getCostoMensual() {
  	return this->costoMensual;
}

float Videojuego::getCostoAnual() {
  	return this->costoAnual;
}

float Videojuego::getCostoVitalicio() {
  	return this->costoVitalicio;
}

float Videojuego::getPuntajePromedio() {
		list<Puntua*>::iterator it;
		int totalPuntuaciones = puntuaciones.size();
		float totalPuntaje = 0.0;

		for(it = puntuaciones.begin(); it != puntuaciones.end(); it++) {
			totalPuntaje += (*it)->getPuntaje();
		}

		if (totalPuntuaciones == 0)
			return 0.0;

		return (totalPuntaje / totalPuntuaciones);
}

Desarrollador * Videojuego::getCreador() {
  	return this->creador;
}

map<string,Categoria*> Videojuego::getCategorias() {
  	return this->categorias;
}

//dss Iniciar Partida
list<string> Videojuego::getNicknameJugadoresSuscriptos(){
	list<string> lista;
	map<string,JugadorVideojuego*> jugadoresVideojuego = this->jugadoresvideojuego;
	map<string,JugadorVideojuego*>::iterator iter;
	for(iter = jugadoresVideojuego.begin(); iter != jugadoresVideojuego.end(); ++iter){
		JugadorVideojuego * jv = iter->second;

  	Suscripcion * suscripcionActiva = jv->getSuscripcionActiva();

    if (suscripcionActiva != NULL) {
			string nickname = jv->getNombreJugador();
			lista.push_back(nickname);
		}
	}
	return lista;
}


bool Videojuego::tienePartidasActivas() {
	map<string,JugadorVideojuego *>::iterator it;
	bool tieneActivas = true;
	bool res = false;

	for (it = this->jugadoresvideojuego.begin(); it != this->jugadoresvideojuego.end(); ++it) {
		tieneActivas = it->second->hayPartidasActivas();
		if(tieneActivas == true) {
			res = true;
		}
	}
	return res;
}

void Videojuego::eliminarVideojuego(string nombre) {

	map<string,JugadorVideojuego *>::iterator itr;
	for(itr = jugadoresvideojuego.begin(); itr != jugadoresvideojuego.end(); ++itr){
		itr->second->eliminarJugadorVideojuego(nombre);
	}

	jugadoresvideojuego.clear();
	puntuaciones.clear();

	map<string,Categoria *>::iterator iter;
	for(iter = categorias.begin(); iter != categorias.end(); ++iter){
		iter->second->eliminarLinkCategoriaAVideojuego(nombre);

	}

	creador->eliminarLinkDesarrolladorAVideojuego(nombre);
	categorias.clear();
}

void Videojuego::setJugadoresVideojuego(map<string,JugadorVideojuego *> jugadoresvideojuego){
	this->jugadoresvideojuego = jugadoresvideojuego;
}

void Videojuego::setNombre(string nombre){
	this->nombre = nombre;
}

void Videojuego::setDescripcion(string descripcion){
	this->descripcion = descripcion;
}

void Videojuego::setCostoMensual(float costoMensual){
	this->costoMensual = costoMensual;
}

void Videojuego::setCostoTrimestral(float costoTrimestral){
	this->costoTrimestral = costoTrimestral;
}

void Videojuego::setCostoVitalicio(float costoVitalicio){
	this->costoVitalicio = costoVitalicio;
}

void Videojuego::setCostoAnual(float costoAnual){
	this->costoAnual = costoAnual;
}

void Videojuego::setCreador(Desarrollador * creador){
	this->creador = creador;
}

void Videojuego::setCategorias(map<string,Categoria *> categorias){
	this->categorias = categorias;
}

void Videojuego::setPuntuaciones(list<Puntua *> puntuaciones){
	this->puntuaciones = puntuaciones;
}

void Videojuego::agregarPuntua(Puntua * puntua) {
	puntuaciones.push_back(puntua);
}

map<string,JugadorVideojuego *> Videojuego::getJugadoresVideojuego(){
	return jugadoresvideojuego;
}
void Videojuego::setParJV(string nickname,  JugadorVideojuego * jv){
	jugadoresvideojuego.insert(
            pair<string,JugadorVideojuego*>(
                nickname,
                jv
            ));
}