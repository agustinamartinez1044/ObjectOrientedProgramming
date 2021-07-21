#pragma once 

#include <list>

#include "../clases/Videojuego.h"
#include "../datatypes/DtVideojuego.h"
#include "../datatypes/DtCategoria.h"

class DtCategoria;

using namespace std;

class IPublicarVideojuego {

    public:
        virtual ~IPublicarVideojuego() = 0;
        virtual list<DtCategoria *> listarCategorias() = 0;
        virtual bool existeVideojuego(string nombreVideojuego) = 0;
        virtual bool esGenero(string nombreGenero) = 0;
        virtual bool esPlataforma(string nombrePlataforma) = 0;
        virtual bool esOtroTipoCategoria(string nombreCategoria) = 0;
        virtual void crearVideojuego(DtVideojuego *dtVideojuego, list<string> categorias) = 0;
};
