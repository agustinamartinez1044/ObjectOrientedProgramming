#pragma once

#include <iomanip>

#include "./DtFechaHora.h"

class Partida;

using namespace std;

class DtPartida {
    private:
        int id;
        DtFechaHora *comienzo;
        DtFechaHora *final; 
        float duracion;
        string videojuego;

    public:
        DtPartida();
        DtPartida(int id, DtFechaHora *comienzo, string videojuego);
        DtPartida(int id, DtFechaHora *comienzo, DtFechaHora *final, float duracion);
        ~DtPartida();

        int getId() const;
        DtFechaHora *getComienzo() const;
        DtFechaHora *getFinal() const;
        virtual float getDuracion() const;
        string getVideojuego() const;

        virtual void print(ostream& os) const;
        friend ostream &operator<<(ostream &os, DtPartida const * partida);
};
