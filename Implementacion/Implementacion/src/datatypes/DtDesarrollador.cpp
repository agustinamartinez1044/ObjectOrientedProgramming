#include "../../include/datatypes/DtDesarrollador.h"

DtDesarrollador::DtDesarrollador(string email, string contrasena, string empresa) : DtUsuario(email, contrasena) {
  this->empresa = empresa;
}

DtDesarrollador::DtDesarrollador() : DtUsuario() {}

DtDesarrollador::~DtDesarrollador() {}

string DtDesarrollador::getEmpresa() const {
  return this->empresa;
}
