#pragma once

#include <iostream>

using namespace std;

class DtUsuario {
    private:
        string email, contrasena;
    public:
        DtUsuario(string email, string contrasena);
        DtUsuario();
        virtual ~DtUsuario();

        virtual string getEmail() const;
        virtual string getContrasena() const;
};
