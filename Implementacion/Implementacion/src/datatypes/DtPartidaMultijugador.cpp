#include "../../include/datatypes/DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador() : DtPartida() { }

DtPartidaMultijugador::~DtPartidaMultijugador() {}

DtPartidaMultijugador::DtPartidaMultijugador
  	(
		int id, DtFechaHora *comienzo, string videojuego, bool transmitidaEnVivo, list<string> nicknames
  	): DtPartida(id, comienzo,videojuego) {

    this->transmitidaEnVivo = transmitidaEnVivo;
    this->nicknames = nicknames;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo() const {
    return this->transmitidaEnVivo;
}

list<string> DtPartidaMultijugador::getNicknames() {
	return this->nicknames;
}

void DtPartidaMultijugador::print(ostream &os) const {
    string enVivo = "no";
    if (this->getTransmitidaEnVivo()) {
      enVivo = "si";
    }

    os << "Tipo de partida: multijugador\n";
    os << "ID de la partida: " << this->getId() << "\n";
    os << "Inicio: " << (*this->getComienzo()) << "\n";
    if (this->getFinal() != NULL) {
      os << "Final: " << (*this->getFinal());
      os << "Duración: " << fixed << setprecision(2) << this->getDuracion() << " horas\n"; // formatearlo, es un float
    } else {
      os << "Final: -\n";
      os << "Duración: -\n";
    }
    os << "Transmitida en vivo: " << enVivo;

}
