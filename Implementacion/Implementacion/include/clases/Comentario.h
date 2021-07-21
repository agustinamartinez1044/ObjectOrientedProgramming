#pragma once

#include <iostream>

#include "../datatypes/DtFechaHora.h"

using namespace std;

class Comentario {
    private :
        int id;
        DtFechaHora *fechaEnvio;
        string comentario;
    public :
        Comentario(int, DtFechaHora *, string);
        ~Comentario();
        
        void setComentario(string);
        void setId(int);

        int getId();
        string getComentario(); 
};
