#include "../../include/datatypes/DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual() : DtPartida() { }

DtPartidaIndividual::~DtPartidaIndividual() {}

DtPartidaIndividual::DtPartidaIndividual
  (int id, DtFechaHora *comienzo, string videojuego, bool continuaPartidaAnterior
  ): DtPartida(id, comienzo, videojuego) {
         this->continuaPartidaAnterior = continuaPartidaAnterior;
  }
    
DtPartidaIndividual::DtPartidaIndividual
  (int id, DtFechaHora *comienzo, string videojuego, bool continuaPartidaAnterior, int idPartidaAnterior
  ): DtPartida(id, comienzo, videojuego) {
         this->continuaPartidaAnterior = continuaPartidaAnterior;
         this->idPartidaAnterior = idPartidaAnterior;
}

int  DtPartidaIndividual::getPartidaQueContinua(){
  return this->getPartidaQueContinua();
  
}

void DtPartidaIndividual::print(ostream &os) const {
    os << "Tipo de partida: individual\n";
    os << "ID de la partida: " << this->getId() << "\n";
    os << "Inicio: " << (*this->getComienzo()) << "\n";
    if (this->getFinal() != NULL) {
      os << "Final: " << (*this->getFinal());
      os << "Duración: " << fixed << setprecision(2) << this->getDuracion() << " horas"; 
    } else {
      os << "Final: -\n";
      os << "Duración: -";
    }
}
