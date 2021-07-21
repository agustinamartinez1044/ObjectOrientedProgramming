#pragma once

#include <iostream>

#include "../enumerados/TipoCategoria.h"

using namespace std;

class DtCategoria {
    private:
        string nombre;
        string descripcion;
        TipoCategoria tipo;
	public:
		DtCategoria();
		DtCategoria(string nombre, string descripcion, TipoCategoria tipo);
		~DtCategoria();
		string getNombre() const;
		string getDescripcion() const;
		TipoCategoria getTipoCategoria() const;

		friend std::ostream &operator<<(std::ostream &os, DtCategoria const &cateogoria);
};
