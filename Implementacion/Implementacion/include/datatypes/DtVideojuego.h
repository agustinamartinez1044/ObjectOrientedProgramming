#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class DtVideojuego {
    private:
        string nombre;
        string descripcion;

        float costoMensual;
        float costoTrimestral;
        float costoAnual;
        float costoVitalicio;
        float puntajePromedio;

    public:
        DtVideojuego();
        DtVideojuego(
                    string nombre,
                    string descripcion,
                    float costoMensual,
                    float costoTrimestral,
                    float costoAnual,
                    float costoVitalicio,
                    float puntajePromedio = 0.0
                    );
        ~DtVideojuego();

        string getNombre() const;
        string getDescripcion() const;
        float getCostoMensual() const;
        float getCostoTrimestral() const;
        float getCostoAnual() const;
        float getCostoVitalicio() const;
        float getPuntajePromedio() const;

        friend std::ostream &operator<<(std::ostream &os, DtVideojuego const &videojuego);
};
