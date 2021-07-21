#include "../../include/clases/Comentario.h"

Comentario::Comentario(int id, DtFechaHora *fecha, string comentario){
    this->id = id;
    this->fechaEnvio = fecha;
    this->comentario = comentario;
}

Comentario::~Comentario(){
    delete fechaEnvio;
}

int Comentario::getId() { 
    return this->id;
}

string Comentario::getComentario() {
    return this->comentario;
}

void Comentario::setComentario(string comentario) {
    this->comentario = comentario;
}

void Comentario::setId( int id) {
    this->id = id;
}
