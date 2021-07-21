#pragma once

#include "../interfaces/IAgregarCategoria.h"
#include "../interfaces/IPublicarVideojuego.h"
#include "../interfaces/IEliminarVideojuego.h"
#include "../interfaces/IInformacionVideojuego.h"

#include "./ControladorUsuario.h"
#include "../clases/EstadisticaHorasJugadas.h"
#include "../clases/EstadisticaCantidadSuscripciones.h"

class ControladorVideojuego : public IPublicarVideojuego, public IInformacionVideojuego,
    public IEliminarVideojuego , public IAgregarCategoria {

    private :
        static ControladorVideojuego *instancia;
        ControladorVideojuego();

        map<string, Videojuego *> videojuegos;
        map<string, Categoria *> categorias;
        map<string, Estadistica*> estadisticas;

    public :
        ~ControladorVideojuego();
        static ControladorVideojuego *getInstancia();
        map<string, Estadistica*> getEstadisticas();
        list<DtCategoria *> listarCategorias();
        bool existeVideojuego(string nombreVideojuego);
        bool esGenero(string nombreGenero);
        bool esPlataforma(string nombrePlataforma);
        bool esOtroTipoCategoria(string nombreCategoria);
        bool existeCategoria(string);
        void crearCategoria(DtCategoria *dtCategoria);
        map<string, Videojuego *> getVideojuegos();
        list<DtVideojuego *> listarVideojuegosSinPartidasActivas();
        void eliminarVideojuego(string nombre);
        DtVideojuego *obtenerDatosVideojuego(string nombre);
        void crearVideojuego(DtVideojuego *dtVideojuego, list<string> categorias);
        map<string,DtVideojuego*> listarVideojuegosSistema();
        Videojuego * buscarVideojuego(string nombreVideojuego);
        map<string,float> costosVideojuego(string nombreVideojuego);
        list<DtEstadistica*> calcularEstadisticas(string, map<string, Estadistica*>);
        bool tienePartidasActivas(string nombreVideojuego);
        Videojuego * getVideojuego(string nombre);
};
