#include "../../include/datatypes/DtJugador.h"

DtJugador::DtJugador(
    string email, string contrasena, string nickname, string descripcion
    ) : DtUsuario(email, contrasena) {
    this->nickname = nickname;
    this->descripcion = descripcion;
}

DtJugador::DtJugador() : DtUsuario() {}

DtJugador::~DtJugador() {}

string DtJugador::getNickname() const {
    return this->nickname;
}

string DtJugador::getDescripcion() const {
    return this->descripcion;
}
