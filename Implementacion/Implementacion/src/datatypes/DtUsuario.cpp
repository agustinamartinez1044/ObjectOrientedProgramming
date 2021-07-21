#include "../../include/datatypes/DtUsuario.h"

DtUsuario::DtUsuario(string email, string contrasena) {
    this->email = email;
    this->contrasena = contrasena;
}

DtUsuario::DtUsuario() {}

DtUsuario::~DtUsuario() {}

string DtUsuario::getEmail() const {
    return this->email;
}

string DtUsuario::getContrasena() const {
    return this->contrasena;
}
