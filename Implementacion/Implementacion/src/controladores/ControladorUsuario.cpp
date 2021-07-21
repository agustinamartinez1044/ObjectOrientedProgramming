#include "../../include/controladores/ControladorUsuario.h"

IConsultarEstadisticas::~IConsultarEstadisticas() {}

IAltaUsuario::~IAltaUsuario() {}

IAsignarPuntajeVideojuego::~IAsignarPuntajeVideojuego() {}

ISeleccionarEstadisticas::~ISeleccionarEstadisticas() {}

IIniciarSesion::~IIniciarSesion() {}

ISuscripcionVideojuegos::~ISuscripcionVideojuegos() {}

IModificarFecha::~IModificarFecha() {}

ControladorUsuario *ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario::~ControladorUsuario() {
    delete fechaSistema;
    delete desarrolladorActivo;
    delete jugadorActivo;
    usuarios.clear();
    jugadores.clear();
}

ControladorUsuario *ControladorUsuario::getInstancia() {
    if(instancia == nullptr)
        instancia = new ControladorUsuario();
    return instancia;
}

void ControladorUsuario::modificarFechaSistema(DtFechaHora *fecha){
    fechaSistema = fecha;
}

DtFechaHora *ControladorUsuario::getFechaSistema(){
    return fechaSistema;
}

bool ControladorUsuario::nicknameValido(string nickname) {
    return jugadores.find(nickname) == jugadores.end();
}

bool ControladorUsuario::emailValido(string email) {
    return usuarios.find(email) == usuarios.end();
}

Usuario * ControladorUsuario::buscarUsuario(string email) {
    if (emailValido(email))
        return NULL;
    return usuarios.find(email)->second;
}


void ControladorUsuario::crearUsuario(DtUsuario *datosUsuario) {
    DtJugador *esDtJugador = dynamic_cast<DtJugador *>(datosUsuario);

    if (esDtJugador) {
        Jugador *nuevoUsuario = new Jugador(esDtJugador);
        jugadores.insert(pair<string,Jugador*>(nuevoUsuario->getNickname(), nuevoUsuario));
        usuarios.insert(pair<string,Usuario*>(nuevoUsuario->getEmail(), nuevoUsuario));
    }
    else {
        DtDesarrollador *esDesarrollador = dynamic_cast<DtDesarrollador *>(datosUsuario);
        Desarrollador *nuevoUsuario = new Desarrollador(esDesarrollador);
        usuarios.insert(pair<string,Usuario*>(nuevoUsuario->getEmail(), nuevoUsuario));
    }
}

bool ControladorUsuario::confirmarDatosSesion(string email, string contrasena) {
    map<string,Usuario *>::iterator iteradorUsuario = usuarios.find(email);

    if (iteradorUsuario == usuarios.end()) {
        return false;
    } else {
        Usuario * usuario = iteradorUsuario->second;

        if (usuario->getContrasena() == contrasena) return true;
    }
    return false;
}


map<string,DtVideojuego*> ControladorUsuario::listarVideojuegosSistema() {
    ControladorVideojuego * controladorVideojuego = ControladorVideojuego::getInstancia();

    return controladorVideojuego->listarVideojuegosSistema();
}

void ControladorUsuario::asignarPuntaje(string nombreVideojuego, int puntaje) {
    ControladorVideojuego * controladorVideojuego = ControladorVideojuego::getInstancia();
    Videojuego * videojuego = controladorVideojuego->buscarVideojuego(nombreVideojuego);
    Puntua * puntua = new Puntua(jugadorActivo, puntaje);

    videojuego->agregarPuntua(puntua);
}

list<DtVideojuego *> ControladorUsuario::listarVideojuegosDelDesarrollador() {
    return desarrolladorActivo->listarVideojuegosDelDesarrollador();
}

bool ControladorUsuario::existeVideojuego(string nombreVideojuego) {
    ControladorVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();
    return controladorVideojuego->existeVideojuego(nombreVideojuego);
}

list<DtEstadistica *> ControladorUsuario::consultarEstadisticas(string nombreVideojuego){
    ControladorVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();

    Desarrollador *desarrollador = this->getDesarrolladorActivo();
    map<string, Estadistica*> estadisticasSeleccionadas = desarrollador->getEstadisticas();

    list<DtEstadistica*> estadisticas = controladorVideojuego->calcularEstadisticas(nombreVideojuego, estadisticasSeleccionadas);
    return estadisticas;
}

list <DtVideojuego *> ControladorUsuario::listarVideojuegosConSuscripcionActiva(){
    return jugadorActivo->listarVideojuegosConSuscripcionActivas();
}

list <DtVideojuego *> ControladorUsuario::listarVideojuegosNoSuscriptos() {
    list<DtVideojuego *> listaActivas = listarVideojuegosConSuscripcionActiva();
    list<DtVideojuego *> res;
    ControladorVideojuego *cv = ControladorVideojuego::getInstancia();
    map<string, Videojuego *> videojuegos(cv->getVideojuegos());
    list<DtVideojuego *>::iterator itr;

    for(itr = listaActivas.begin(); itr != listaActivas.end(); ++itr ) {
        if((*itr)->getNombre() == videojuegos.find((*itr)->getNombre())->first) {
            videojuegos.erase((*itr)->getNombre());
        }
    }
    map<string, Videojuego *>::iterator iter;

    for(iter = videojuegos.begin(); iter != videojuegos.end(); ++iter) {
        DtVideojuego *dt = new DtVideojuego
            (
                iter->first,iter->second->getDescripcion(),
                iter->second->getCostoMensual(),
                iter->second->getCostoTrimestral(),
                iter->second->getCostoAnual(),
                iter->second->getCostoVitalicio()
            );
        res.push_back(dt);
    }

    videojuegos.clear();
    return res;
}

StatusSuscripcion ControladorUsuario::getStatusSuscripcionVideojuego(string nombre) {
    Jugador * jugador = this->getJugadorActivo();

    return jugador->getStatusSuscripcionVideojuego(nombre);
}

void ControladorUsuario::cancelarSuscripcion(string nombreVideojuego) {
    Jugador * jugador = this->getJugadorActivo();

    jugador->cancelarSuscripcion(nombreVideojuego);
}

void ControladorUsuario::confirmarSuscripcion(string nombreVideojuego, DtSuscripcion * suscripcion) {
    ControladorVideojuego * controladorVideojuego = ControladorVideojuego::getInstancia();
    Videojuego * videojuego = controladorVideojuego->buscarVideojuego(nombreVideojuego);

    jugadorActivo->confirmarSuscripcion(videojuego, suscripcion);
}

list<DtEstadistica *> ControladorUsuario::listarEstadisticas() {
    list<DtEstadistica*> listaEstadisticas;

    ControladorVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();
    map<string, Estadistica*> estadisticas = controladorVideojuego->getEstadisticas();

    for (pair<string, Estadistica*> par : estadisticas) {
        Estadistica *estadistica = par.second;
        DtEstadistica *dtestadistica = new DtEstadistica(estadistica->getNombre(), estadistica->getDescripcion());
        listaEstadisticas.push_back(dtestadistica);
    }
    return listaEstadisticas;
}

bool ControladorUsuario::existeEstadistica(string nombreEstadistica) {
    ControladorVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();
    map<string, Estadistica*> estadisticas = controladorVideojuego->getEstadisticas();

    return estadisticas.find(nombreEstadistica) != estadisticas.end();
}

void ControladorUsuario::seleccionarEstadisticas(list<string> nombresEstadisticas) {
    ControladorVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();
    map<string, Estadistica*> listaEstadisticas = controladorVideojuego->getEstadisticas();

    Desarrollador *desarrollador = getDesarrolladorActivo();

    map<string, Estadistica*> estadisticasSeleccionadas;
    for (string nombreEstadistica : nombresEstadisticas) {
        Estadistica *estadistica = listaEstadisticas.find(nombreEstadistica)->second;
        estadisticasSeleccionadas.insert(pair<string, Estadistica*>(nombreEstadistica, estadistica));
    }

    desarrollador->setEstadisticas(estadisticasSeleccionadas);
}

Desarrollador * ControladorUsuario::getDesarrolladorActivo(){
    return this->desarrolladorActivo;
}

Jugador *ControladorUsuario::getJugadorActivo(){
    return this->jugadorActivo;
}

void ControladorUsuario::setUsuario(Usuario *usuario){

    Jugador *jugador = dynamic_cast<Jugador *>(usuario);

    if (jugador) {
        this->jugadorActivo = jugador;
    }
    else {
        Desarrollador *desarrollador = dynamic_cast<Desarrollador *>(usuario);
        this->desarrolladorActivo = desarrollador;
    }
}

map<string,float> ControladorUsuario::getCostosVideojuego(string nombreVideojuego){
    ControladorVideojuego * controladorVideojuego = ControladorVideojuego::getInstancia();

    return controladorVideojuego->costosVideojuego(nombreVideojuego);
}

Jugador * ControladorUsuario::getJugador(string nickname){
    map<string,Jugador *> jugadores =  this->jugadores;
    map<string,Jugador *>::iterator iter = jugadores.find(nickname);
    return iter->second;
}

void ControladorUsuario::cerrarSecion(){
    desarrolladorActivo = NULL;
    jugadorActivo =NULL;
}
