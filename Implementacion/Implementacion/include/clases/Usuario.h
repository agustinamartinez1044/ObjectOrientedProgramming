#pragma once

#include <iostream>

using namespace std;

class Usuario {
    private:
        string email;
        string contrasena;
    public:
        Usuario();
        Usuario(string email, string contrasena);
        virtual ~Usuario();

        string getEmail();
        string getContrasena();
        virtual void setEmail(string email);
        virtual void setContrasena(string contrasena);
        virtual char getTipo() = 0;
};
