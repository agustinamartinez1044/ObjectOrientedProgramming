#include "../../include/clases/Observa.h"

Observa::Observa(){}

Observa::~Observa(){
     comentarios.clear();
     observadores.clear();
}

list<string> Observa::getComentarios() {
     list<string> lista;
     map<int, Comentario *>::iterator itr;

     for (itr = this->comentarios.begin(); itr != this->comentarios.end(); ++itr) {
          lista.insert(lista.begin(),itr->second->getComentario());
     }
     return lista;
}

list<Usuario *>  Observa::getUsuario() {
     list<Usuario *> lista;
     map<string, Usuario *>::iterator itr;
     for (itr = this->observadores.begin(); itr != this->observadores.end(); ++itr) {
          lista.insert(lista.begin(),itr->second);
     }
     return lista;
}
