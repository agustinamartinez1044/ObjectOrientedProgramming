#pragma once 

#include <list>
#include "../datatypes/DtEstadistica.h"

class Estadistica;

using namespace std;

class ISeleccionarEstadisticas {
    public :
        virtual ~ISeleccionarEstadisticas() = 0;
        virtual list<DtEstadistica *> listarEstadisticas() = 0;
        virtual bool existeEstadistica(string) = 0;
        virtual void seleccionarEstadisticas(list<string> estadisticasSeleccionadas) = 0;
};
