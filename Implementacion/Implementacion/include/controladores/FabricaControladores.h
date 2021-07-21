#pragma once
// #include <stdio.h>
// #include <string.h>
// #include <iostream>
// #include <map>
// #include <set>

#include "../interfaces/IAgregarCategoria.h"
#include "../interfaces/IAbandonarPartidaMultijugador.h"
#include "../interfaces/IFinalizarPartida.h"
#include "../interfaces/IAltaUsuario.h"
#include "../interfaces/IAsignarPuntajeVideojuego.h"
#include "../interfaces/IPublicarVideojuego.h"
#include "../interfaces/ISuscripcionVideojuegos.h"
#include "../interfaces/IConsultarEstadisticas.h"
#include "../interfaces/IInformacionVideojuego.h"
#include "../interfaces/IIniciarPartida.h"
#include "../interfaces/IIniciarSesion.h"
#include "../interfaces/ISeleccionarEstadisticas.h"
#include "../interfaces/IEliminarVideojuego.h"

#include "./ControladorPartida.h"
#include "./ControladorUsuario.h"
#include "./ControladorVideojuego.h"

class FabricaControladores {

private:
    static FabricaControladores * instancia;
    FabricaControladores();
    
public:
    ~FabricaControladores();
    static FabricaControladores * getInstancia();
    
    static IAgregarCategoria *getIAgregarCategoria();
    static IAbandonarPartidaMultijugador *getIAbandonarPartidaMultijugador();
    static IFinalizarPartida *getIFinalizarPartida();
    static IAltaUsuario *getIAltaUsuario();
    static IAsignarPuntajeVideojuego *getIAsignarPuntajeVideojuego();
    static IPublicarVideojuego *getIPublicarVideojuego();
    static ISuscripcionVideojuegos *getISuscripcionVideojuegos();
    static IConsultarEstadisticas *getIConsultarEstadisticas();
    static IInformacionVideojuego *getIInformacionVideojuego();
    static IIniciarPartida *getIIniciarPartida();
    static IIniciarSesion *getIIniciarSesion();
    static ISeleccionarEstadisticas *getISeleccionarEstadisticas();
    static IEliminarVideojuego *getIEliminarVideojuego();
    static IModificarFecha *getIModificarFecha();
};
