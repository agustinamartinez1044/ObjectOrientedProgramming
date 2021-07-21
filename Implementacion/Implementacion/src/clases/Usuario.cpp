#include "../../include/clases/Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string email, string contrasena){
  this->email = email;
  this->contrasena = contrasena;
}

Usuario::~Usuario(){}

string Usuario::getEmail() {
  return this->email;
}

string Usuario::getContrasena() {
  return this->contrasena;
}

void Usuario::setEmail(string email) {
  this->email = email;
}

void Usuario::setContrasena(string contrasena) {
  this->contrasena = contrasena;
}
