#include "Sala.h"

Sala::Sala(string codigo, TipoSala tipoSala, std::vector<Horario> ind) {
    codigo = codigo;
 //   tipoSala = tipoSala.getID();
    indisponibilidade = ind;

   /* NÃO EXISTE ESSE TIPO DE INCIALIZAÇÃO EM C++
   if (indisponibilidade.empty()) {
        indisponibilidade = new Horario[1] ;
    }*/
}

int Sala::getCapacidade() {
    return tipoSala;
}

string Sala::getCodigo() {
    return codigo;
}

std::vector<Horario> Sala::getIndisponibilidade() {
    return indisponibilidade;
}

int Sala::getID() {
    return id;
}

void Sala::setID(int id) {
    id=id;
}

int Sala::getTipoSala(){
    return tipoSala;
}

int Sala::getGrupoSala() {
    return grupoSala;
}

void Sala::setGrupoSala(int gs) {
    grupoSala = gs;
}
