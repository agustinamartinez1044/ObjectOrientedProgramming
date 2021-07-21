#include "../../include/datatypes/DtFechaHora.h"

DtFechaHora::DtFechaHora(){}

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int minutos) {
  bool diaInvalido = dia < 1 || dia > 31;
  bool mesInvalido = mes < 1 || mes > 12;
  bool anioInvalido = anio < 1900;
  bool horaInvalida = hora < 0 || hora > 23;
  bool minutosInvalidos = minutos < 0 || minutos > 59;

  if (diaInvalido || mesInvalido || anioInvalido || horaInvalida || minutosInvalidos) {
    throw std::invalid_argument("¡Fecha invalida!");
  }

  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
  this->hora = hora;
  this->minutos = minutos;
}

DtFechaHora::~DtFechaHora() {};

int DtFechaHora::getDia() const {
  return this->dia;
}

int DtFechaHora::getMes() const {
  return this->mes;
}

int DtFechaHora::getAnio() const {
  return this->anio;
}

int DtFechaHora::getHora() const {
  return this->hora;
}

int DtFechaHora::getMinutos() const {
  return this->minutos;
}

std::ostream &operator<<(std::ostream &os, const DtFechaHora &fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio()
       << " " << fecha.getHora() << ":" << fecha.getMinutos();

    return os;
}
