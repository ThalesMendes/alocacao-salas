#include "TipoSala.h"

TipoSala::TipoSala(int cap) {
    capacidade = cap;
    /*turmas = new int[0];
    salas = new int[0];*/
}

 TipoSala TipoSala::getTipo(int i){
    return tiposSala.at(i);
}

std::vector<int> TipoSala::getTurmas(int i) {
    return getTipo(i).turmas;
}

void TipoSala::setTurmas(int i,std::vector<int> turmas) {
   getTipo(i).turmas = turmas;
}


TipoSala TipoSala::tipoSalaFactory(int cap){
    TipoSala *ts = new TipoSala(cap);
    //COMO INSERIR
    //tiposSala.insert(cap, *ts);
    return *ts;
}

int TipoSala::getCapacidade(int i) {
    return getTipo(i).capacidade;
}

int TipoSala::getID(int i) {
    return getTipo(i).id;
}

int TipoSala::getID() {
    return id;
}

void TipoSala::setID(int i,int id) {
    TipoSala g = getTipo(i);
    g.id = id;
}

void TipoSala::setID(int i) {
    id = i;
}

std::vector<int>  TipoSala::getSalas(int i) {
    return getTipo(i).salas;
}

void TipoSala::setSalasPorTipo(int i,std::vector<int>  aSalasPorTipo) {
    getTipo(i).salas = aSalasPorTipo;
}

std::map<int,TipoSala>  TipoSala::getTiposSala(){
    return tiposSala;
}


