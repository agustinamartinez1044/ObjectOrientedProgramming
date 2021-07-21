#pragma once

#include <iostream>
#include <list>
#include <string>

#include "../datatypes/DtCategoria.h"
#include "../enumerados/TipoCategoria.h"

using namespace std;

class IAgregarCategoria {

    public:
        virtual ~IAgregarCategoria() = 0;
        virtual list<DtCategoria *> listarCategorias() = 0;
        virtual bool existeCategoria(string) = 0;
        virtual void crearCategoria(DtCategoria *dtCategoria) = 0;
};
