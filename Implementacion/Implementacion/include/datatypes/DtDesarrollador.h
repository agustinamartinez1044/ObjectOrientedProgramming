#pragma once

#include <iostream>

#include "DtUsuario.h"

using namespace std;

class DtDesarrollador : public DtUsuario {
    private:
        string empresa;
    public:
        DtDesarrollador(string email, string contrasena, string empresa);
        DtDesarrollador();
        ~DtDesarrollador();

        string getEmpresa() const;
};
