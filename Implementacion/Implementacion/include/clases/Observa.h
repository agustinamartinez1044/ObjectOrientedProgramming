#pragma once

#include <iostream>
#include <list>
#include <map>

#include "./Comentario.h"

class Usuario;

using namespace std;

class Observa {
    private:
        map<int, Comentario *> comentarios;
        map<string, Usuario *> observadores;

    public :
        Observa();
        ~Observa();

        list<string> getComentarios();
        list<Usuario *> getUsuario();
};
