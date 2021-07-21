#include "../../include/clases/Participa.h"

Participa::Participa() {}

Participa::Participa(DtFechaHora *horaAbandono){
    this->horaAbandono = horaAbandono;
}
Participa::~Participa() {
    delete horaAbandono;
}

DtFechaHora *Participa::getHoraAbandono() {
    return this->horaAbandono;
}

void Participa::setHoraAbandono(DtFechaHora *horaAbandono) {
    this->horaAbandono = horaAbandono;
}
