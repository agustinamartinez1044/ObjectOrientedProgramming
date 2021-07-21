#pragma once

#include <iostream>
#include <map>
#include <list>

#include "../datatypes/DtEstadistica.h"
#include "../datatypes/DtVideojuego.h"
#include "../datatypes/DtDesarrollador.h"

#include "./Videojuego.h"
#include "./Usuario.h"
#include "./Categoria.h"

class Estadistica;
using namespace std;

class Desarrollador : public Usuario {
    private:
        string empresa;

        map<string,Videojuego*> videojuegos;
        map<string, Estadistica*> estadisticas;
    public:
        Desarrollador();
        Desarrollador(DtDesarrollador*);
        ~Desarrollador();

        char getTipo();
        string getEmpresa();
        void setEmpresa(string empresa);
        map<string, Estadistica*> getEstadisticas();
        void setEstadisticas(map<string, Estadistica*>);
        map<string,Videojuego*> getVideojuegos();
        void agregarVideojuego(Videojuego * videojuego);
        list<DtVideojuego *> listarVideojuegosDelDesarrollador();
        void eliminarLinkDesarrolladorAVideojuego(string nombre);
        bool tienePartidasActivas();
        list<DtVideojuego *> listarVideojuegosSinPartidasActivas();
        void setVideojuego(Videojuego *);
};
