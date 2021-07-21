#include "../../include/controladores/FabricaControladores.h"

FabricaControladores* FabricaControladores::instancia = NULL;

FabricaControladores::FabricaControladores(){}

FabricaControladores::~FabricaControladores(){}

FabricaControladores* FabricaControladores::getInstancia(){
    if(instancia == NULL)
        instancia = new FabricaControladores();
    return instancia;
}

IFinalizarPartida *FabricaControladores::getIFinalizarPartida(){
    return ControladorPartida::getInstancia();
}

IAgregarCategoria *FabricaControladores::getIAgregarCategoria(){
    return ControladorVideojuego::getInstancia();
}

IAbandonarPartidaMultijugador *FabricaControladores::getIAbandonarPartidaMultijugador(){
    return ControladorPartida::getInstancia();
}


IAltaUsuario *FabricaControladores::getIAltaUsuario(){
    return ControladorUsuario::getInstancia();
}

IAsignarPuntajeVideojuego *FabricaControladores::getIAsignarPuntajeVideojuego(){
    return ControladorUsuario::getInstancia();
}

IPublicarVideojuego *FabricaControladores::getIPublicarVideojuego(){
    return ControladorVideojuego::getInstancia();
}

ISuscripcionVideojuegos *FabricaControladores::getISuscripcionVideojuegos(){
    return ControladorUsuario::getInstancia();
}

IConsultarEstadisticas *FabricaControladores::getIConsultarEstadisticas(){
    return ControladorUsuario::getInstancia();
}

IInformacionVideojuego *FabricaControladores::getIInformacionVideojuego(){
    return ControladorVideojuego::getInstancia();
}

IIniciarPartida *FabricaControladores::getIIniciarPartida(){
    return ControladorPartida::getInstancia();
}

IIniciarSesion *FabricaControladores::getIIniciarSesion(){
    return ControladorUsuario::getInstancia();
}

ISeleccionarEstadisticas *FabricaControladores::getISeleccionarEstadisticas(){
    return ControladorUsuario::getInstancia();
}

IEliminarVideojuego *FabricaControladores::getIEliminarVideojuego(){
    return ControladorVideojuego::getInstancia();
}

IModificarFecha *FabricaControladores::getIModificarFecha(){
    return ControladorUsuario::getInstancia();
}
