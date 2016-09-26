#include "GrupoTurma.h"

GrupoTurma::GrupoTurma(Tipo tp, string agp) {
    bool create = true;

    for(std::vector<GrupoTurma>::iterator gT = grupoTurma.begin(); gT != grupoTurma.end(); ++gT){

        Tipo tipo = gT->getTipo();
        string agrupamento = gT->getAgrupamento();

        if (tipo == tp && agrupamento==agp) {
            create = false;
        }
    }

    if (create) {
        tipo = tp;
        agrupamento = agp;
        /*VERIFICAR SE ISSO É NECESSÁRIO
        turmas = new int[0];*/
        id = 0;
    } else {
        id = -1;
        tipo = ERROR;
        agrupamento = "";
    }
}

 GrupoTurma GrupoTurma::criar(Tipo tipo, string agrupamento){

    GrupoTurma *gt = new GrupoTurma(tipo, agrupamento);

    if (gt->getTipo() == ERROR) {
        for(std::vector<GrupoTurma>::iterator gtAux = grupoTurma.begin(); gtAux != grupoTurma.end(); ++gtAux){

            if ((gtAux->getTipo() == tipo) && (gtAux->getAgrupamento() == agrupamento)) {
                return *gtAux;
            }
        }
    }


    if (gt->id == 0) {
        grupoTurma.push_back(*gt);
        gt->id = grupoTurma.size()-1;
        /* VERIFICAR SE ESTÁ CERTO
        gt->id = grupoTurma.find(gt);*/
    }

    return *gt;
}

/*void GrupoTurma::addTurma(Turma turma) {

    for(std::vector<int>::iterator t = turmas.begin(); t != turmas.end(); ++t){
        if (*t == turma.getID()) {
            return;
        }
    }

    std::vector<int> auxTurmas; //= new int[turmas.length + 1];
    auxTurmas=turmas;
    auxTurmas[turmas.size()] = turma.getID();
    turmas = auxTurmas;
    turma.addGrupoTurma(id);
}*/



int GrupoTurma::getId() {
    return id;
}

std::vector<int> GrupoTurma::getTurmas() {
    return turmas;
}

Tipo GrupoTurma::getTipo() {
    return tipo;
}


string GrupoTurma::getAgrupamento() {
    return agrupamento;
}

int GrupoTurma::getNumeroTurmas() {
    return turmas.size();
}

GrupoTurma GrupoTurma::getGrupo(int id) {

    GrupoTurma  *g = NULL;

    if (id >= 0 || grupoTurma.size() > id) {
           for(std::vector<GrupoTurma>::iterator gT = grupoTurma.begin(); gT != grupoTurma.end(); ++gT){

            if(gT->getId() == id){
                *g = *gT;
            }
        }
    }

    return *g;
}
