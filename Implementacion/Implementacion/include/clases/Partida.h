#pragma once

#include <iostream>

using namespace std;

#include "../datatypes/DtFechaHora.h"
#include "../datatypes/DtPartida.h"

class Partida{
	private:
		int id;
    	DtFechaHora *comienzo;
		DtFechaHora *final;
		float duracion;

  	public:
    	Partida();
    	Partida(int id, DtFechaHora *comienzo);
    	virtual ~Partida();

	    int getId();
        DtFechaHora *getComienzo();
		DtFechaHora *getFinal();
		float getDuracion();

		void setId(int id);
    	void setComienzo(DtFechaHora *comienzo);
		void setFinal(DtFechaHora *final);
		void setDuracion(float duracion);
		bool esPartidaIndividual();
		virtual DtPartida *getDtPartida() = 0;
		void eliminarTipoPartida();
		bool noFinalizo();
	    void finalizarPartida(DtFechaHora *);
		virtual float calcularDuracion(DtFechaHora * comienzo, DtFechaHora * final);
		float getClaveFinalizacion();
};
