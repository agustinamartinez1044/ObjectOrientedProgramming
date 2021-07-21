#pragma once

#include "../interfaces/IAltaUsuario.h"
#include "../interfaces/IAsignarPuntajeVideojuego.h"
#include "../interfaces/IConsultarEstadisticas.h"
#include "../interfaces/IIniciarSesion.h"
#include "../interfaces/ISeleccionarEstadisticas.h"
#include "../interfaces/ISuscripcionVideojuegos.h"
#include "../interfaces/IModificarFecha.h"

#include "./ControladorVideojuego.h"

class ControladorUsuario : public IIniciarSesion, public IAltaUsuario,
    public IAsignarPuntajeVideojuego, public IConsultarEstadisticas,
    public ISeleccionarEstadisticas, public ISuscripcionVideojuegos,
    public IModificarFecha {

    private :
        ControladorUsuario();
        static ControladorUsuario *instancia;

        DtFechaHora *fechaSistema;
        Desarrollador * desarrolladorActivo;
        Jugador * jugadorActivo;
        map<string,Usuario *> usuarios;
        map<string,Jugador *> jugadores;

    public :
        ~ControladorUsuario();
        static ControladorUsuario* getInstancia();
        void setUsuario(Usuario *);
        Desarrollador * getDesarrolladorActivo();
        Jugador * getJugadorActivo();
        void modificarFechaSistema(DtFechaHora * fecha);
        DtFechaHora *getFechaSistema();
        void cerrarSecion();
        bool confirmarDatosSesion(string email, string contrasena);
        Usuario *buscarUsuario( string email);
        bool nicknameValido(string nickname);
        bool emailValido(string);
        void crearUsuario(DtUsuario *datos);
        void asignarPuntaje(string nombreVideojuego, int puntaje);
        map<string,DtVideojuego*> listarVideojuegosSistema();
        list<DtVideojuego *> listarVideojuegosDelDesarrollador();
        bool existeVideojuego(string);
        list<DtEstadistica *> consultarEstadisticas(string);
        list <DtVideojuego *> listarVideojuegosConSuscripcionActiva();
        list <DtVideojuego *> listarVideojuegosNoSuscriptos();
        StatusSuscripcion getStatusSuscripcionVideojuego(string nombre);
        map<string,float> getCostosVideojuego(string nombreVideojuego);
        void cancelarSuscripcion(string nombreVideojuego);
        void confirmarSuscripcion(string nombreVideojuego, DtSuscripcion * suscripcion);
        list<DtEstadistica *> listarEstadisticas();
        bool existeEstadistica(string);
        void seleccionarEstadisticas(list<string>);
        list<DtPartida *> listarPartidasNoFinalizadasDelJugador(Jugador *jugador);
        Jugador * getJugador(string nickname);
};
