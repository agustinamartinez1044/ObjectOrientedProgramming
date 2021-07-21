#include "../../include/controladores/ControladorVideojuego.h"

IAgregarCategoria::~IAgregarCategoria() {}

IPublicarVideojuego::~IPublicarVideojuego() {}

IInformacionVideojuego::~IInformacionVideojuego() {}

IEliminarVideojuego::~IEliminarVideojuego() {}

ControladorVideojuego *ControladorVideojuego::instancia = NULL;

ControladorVideojuego::ControladorVideojuego() {
    EstadisticaHorasJugadas *horasJugadas = new EstadisticaHorasJugadas();
    EstadisticaCantidadSuscripciones *cantidadSuscripciones = new EstadisticaCantidadSuscripciones();
    
    this->estadisticas.insert(pair<string, Estadistica*>(horasJugadas->getNombre(), horasJugadas));
    this->estadisticas.insert(pair<string, Estadistica*>(cantidadSuscripciones->getNombre(), cantidadSuscripciones));
}

ControladorVideojuego::~ControladorVideojuego() {
    videojuegos.clear();
    categorias.clear();
    estadisticas.clear();
}

ControladorVideojuego *ControladorVideojuego::getInstancia() {
    if (instancia == nullptr)
        instancia = new ControladorVideojuego();
    return instancia;
}

map<string, Estadistica *> ControladorVideojuego::getEstadisticas() {
    return this->estadisticas;
}

list<DtCategoria *> ControladorVideojuego::listarCategorias(){
    list<DtCategoria *> listaCategorias;

    for (pair<string, Categoria*> par : this->categorias) {
        Categoria *categoria = par.second;
        DtCategoria *dtcategoria = new DtCategoria(categoria->getNombre(),categoria->getDescripcion() , categoria->getTipoCategoria());
        listaCategorias.push_back(dtcategoria);
    }
    return listaCategorias;
}

bool ControladorVideojuego::existeCategoria(string nombreCategoria) {
    return this->categorias.find(nombreCategoria) != this->categorias.end();
}

void ControladorVideojuego::crearCategoria(DtCategoria *datosCategoria){
    Categoria * nuevaCategoria = new Categoria(datosCategoria);
    categorias.insert(pair<string, Categoria *>(nuevaCategoria->getNombre(), nuevaCategoria));
}


list<DtVideojuego *> ControladorVideojuego::listarVideojuegosSinPartidasActivas() {
    list<DtVideojuego *> lista;
    ControladorUsuario *controladorUsuario = ControladorUsuario::getInstancia();
    lista = controladorUsuario->getDesarrolladorActivo()->listarVideojuegosSinPartidasActivas();
    return lista;
}

void ControladorVideojuego::eliminarVideojuego(string nombre) {
    Videojuego *videojuego = this->videojuegos.find(nombre)->second;
    videojuego->eliminarVideojuego(nombre);
    videojuegos.erase(nombre);
}

void ControladorVideojuego::crearVideojuego(DtVideojuego *dtVideojuego, list<string> categorias) {
    map<string,Categoria *> categoriasVideojuego;
	map<string,JugadorVideojuego *> jugadoresvideojuego;
	list<Puntua *> puntuaciones;

    ControladorUsuario *controladorUsuario = ControladorUsuario::getInstancia();
    list<string>::iterator itr;
    Categoria *itCategoria;

    for (itr = categorias.begin(); itr != categorias.end(); ++itr) {
        itCategoria =  this->categorias.find(itr->data())->second;
        categoriasVideojuego.insert(pair<string, Categoria *>(itr->data(), itCategoria));
    }

    Videojuego *nuevoVideojuego = new Videojuego
        (
            dtVideojuego->getNombre(),dtVideojuego->getDescripcion(),
            dtVideojuego->getCostoMensual(), dtVideojuego->getCostoTrimestral(),
            dtVideojuego->getCostoVitalicio(), dtVideojuego->getCostoVitalicio(),
            controladorUsuario->getDesarrolladorActivo(), categoriasVideojuego
        );

    nuevoVideojuego->setCreador(controladorUsuario->getDesarrolladorActivo());
    nuevoVideojuego->setCategorias(categoriasVideojuego);
    nuevoVideojuego->setPuntuaciones(puntuaciones);
    nuevoVideojuego->setJugadoresVideojuego(jugadoresvideojuego);

    controladorUsuario->getDesarrolladorActivo()->setVideojuego(nuevoVideojuego);
    this->videojuegos.insert(pair<string, Videojuego *>(nuevoVideojuego->getNombre(), nuevoVideojuego));
}

map<string,DtVideojuego*> ControladorVideojuego::listarVideojuegosSistema() {
    map<string,Videojuego*>::iterator iteradorVideojuego;
    map<string,DtVideojuego*> lista;

    for (iteradorVideojuego = videojuegos.begin(); iteradorVideojuego != videojuegos.end(); iteradorVideojuego++) {
        Videojuego * videojuego = iteradorVideojuego->second;

        DtVideojuego * dtVideojuego = new DtVideojuego(
            videojuego->getNombre(), videojuego->getDescripcion(),
            videojuego->getCostoMensual(), videojuego->getCostoTrimestral(),
            videojuego->getCostoVitalicio(), videojuego->getCostoAnual(),
            videojuego->getPuntajePromedio()
        );

        lista.insert(pair<string,DtVideojuego*>(videojuego->getNombre(), dtVideojuego));
    }

    return lista;
}

bool ControladorVideojuego::existeVideojuego(string nombreVideojuego){
    return buscarVideojuego(nombreVideojuego) != NULL;
}

string enumString(TipoCategoria tipo){
    switch (tipo) {
        case Genero: return "Genero";
        case Plataforma: return "Plataforma";
        case Otro: return "Otro";
    }
    return "";
}

bool ControladorVideojuego::esGenero(string nombreGenero) {
    map<string, Categoria *>::iterator categoria = categorias.find(nombreGenero);

    if(categoria != categorias.end()){
        return enumString(categoria->second->getTipoCategoria()) == "Genero";
    }
    else {
        return false;
    }
}

bool ControladorVideojuego::esPlataforma(string nombrePlataforma) {
    map<string, Categoria *>::iterator categoria = categorias.find(nombrePlataforma);

    if(categoria != categorias.end()){
        return enumString(categoria->second->getTipoCategoria()) == "Plataforma";
    }
    else {
        return false;
    }
}

bool ControladorVideojuego::esOtroTipoCategoria(string nombreCategoria) {
    map<string, Categoria *>::iterator categoria = categorias.find(nombreCategoria);

    if(categoria != categorias.end()) {
        return enumString(categoria->second->getTipoCategoria()) == "Otro";
    }
    else {
        return false;
    }
}

Videojuego * ControladorVideojuego::buscarVideojuego(string nombreVideojuego) {
    map<string,Videojuego*>::iterator iteratorVideojuego = videojuegos.find(nombreVideojuego);

    if (iteratorVideojuego != videojuegos.end()) {
        return iteratorVideojuego->second;
    } else {
        return NULL;
    }
}

map<string,float> ControladorVideojuego::costosVideojuego(string nombreVideojuego) {
    map<string,float> costos;

    Videojuego * videojuego = this->buscarVideojuego(nombreVideojuego);

    if (videojuego != NULL) {
        costos.insert(pair<string,float>("mensual", videojuego->getCostoMensual()));
        costos.insert(pair<string,float>("trimestral", videojuego->getCostoTrimestral()));
        costos.insert(pair<string,float>("anual", videojuego->getCostoAnual()));
        costos.insert(pair<string,float>("vitalicia", videojuego->getCostoVitalicio()));
    }

    return costos;
}

list<DtEstadistica *> ControladorVideojuego::calcularEstadisticas(string nombreVideojuego, map<string, Estadistica*> listaEstadisticas) {
    Videojuego *videojuego = this->videojuegos.find(nombreVideojuego)->second;

    list<DtEstadistica*> estadisticasCalculadas;
    for (pair<string, Estadistica*> par : listaEstadisticas) {
        Estadistica *estadistica = par.second;
        float valor = estadistica->calcular(videojuego);
        DtEstadistica *dtestadistica = new DtEstadistica(estadistica->getNombre(), estadistica->getDescripcion(), valor);
        estadisticasCalculadas.push_back(dtestadistica);
    }

    return estadisticasCalculadas;
}

Videojuego * ControladorVideojuego::getVideojuego(string nombre){
     map<string,Videojuego *>::iterator it;
      it = videojuegos.find(nombre);
      return it->second;

}

map<string, Videojuego *> ControladorVideojuego::getVideojuegos() {
    return videojuegos;
}

bool ControladorVideojuego::tienePartidasActivas(string nombreVideojuego) {
    Videojuego *vj = videojuegos.find(nombreVideojuego)->second;
    return vj->tienePartidasActivas();
}
