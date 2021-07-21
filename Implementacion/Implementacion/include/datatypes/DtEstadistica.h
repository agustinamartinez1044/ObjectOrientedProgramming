#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class DtEstadistica {
    private:
        string nombre, descripcion;
        float valor;
    public:
        DtEstadistica();
        DtEstadistica(string nombre, string descripcion);
        DtEstadistica(string nombre, string descripcion, float valor); 
        ~DtEstadistica();
        string getNombre() const;
        string getDescripcion() const;
        float getValor() const;

        friend std::ostream &operator<<(std::ostream &os, DtEstadistica const &estadistica);
};
