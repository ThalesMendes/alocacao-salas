 #include "Turma.h"

 Turma::Turma(string n, string c, std::vector<Horario> hs, int t, string p, string d) {
    nome = n;
    codigo = c;
    horarios = hs;
    tamanhoTurma = t;
    professor = p;
    departamento = d;
}


std::vector<int> Turma::getGrupoTurma() {
    return grupoTurma;
}

void Turma::addGrupoTurma(int grupo) {
   for(std::vector<int>::iterator g = grupoTurma.begin(); g != grupoTurma.end(); ++g){
        if (*g == grupo) {
            return;
        }
    }

    std::vector<int> aux;
    for(std::vector<int>::iterator g = grupoTurma.begin(); g != grupoTurma.end(); ++g){
        aux[*g] = grupoTurma[*g];
    }

    aux.push_back(grupo);
    grupoTurma = aux;
}

int Turma::getID() {
    return id;
}

void Turma::setID(int i) {
    id = i;
}

vector<vector<bool> > Turma::getColisaoTurmas() {
    return colisaoTurmas;
}

void Turma::setColisaoTurmas(vector<vector<bool> > c) {
    colisaoTurmas = c;
}


bool Turma::colide(Turma turma) {

    for(std::vector<Horario>::iterator h1 = horarios.begin(); h1 != horarios.end(); ++h1){
        for(std::vector<Horario>::iterator h2 = turma.horarios.begin(); h2 != turma.horarios.end(); ++h2){

           Horario h = *h1;

           if (h.colide(*h2)) {
                return true;
            }
        }
    }
    return false;
}

int Turma::duracaoTotal() {
    return horarios.size();
}

int Turma::dias() {
    std::vector<int> dias;
    int somaDias = 0;
    for (int i = 0; i < 6; i++) {
        dias[i] = 0;
    }

   for(std::vector<Horario>::iterator h = horarios.begin(); h != horarios.end(); ++h){
        Horario h1 = *h;
        dias[h1.getDiaSemana()] += 1;
    }

    for(std::vector<int>::iterator i = dias.begin(); i != dias.end(); ++i){
        if (*i != 0) {
            somaDias++;
        }
    }
    return somaDias;
}


vector<Horario> Turma::getHorarios() {
    return horarios;
}

string Turma::getCodigo() {
    return codigo;
}

int Turma::getTamanho() {
    return tamanhoTurma;
}

int Turma::primeiroDia() {
    for(std::vector<Horario>::iterator h = horarios.begin(); h != horarios.end(); ++h){
        Horario h1 = *h;
        return h1.getDiaSemana();
    }
    return -1;
}


string Turma::getNome() {
    return nome;
}

string Turma::getProfessor() {
    return professor;
}

string Turma::getDepartamento() {
    return departamento;
}

/*int Turma::setTipoSala(std::vector<TipoSala> tiposSala) {
    for(std::vector<TipoSala>::iterator t = tiposSala.begin(); t != tiposSala.end(); ++t){
        TipoSala ts = *t;
        if (ts.capacidade - tamanhoTurma >= 0) {
            tipoSala = ts.getID();
            break;
        }
    }
    return getTipoSala();
}*/

int Turma::getTipoSala() {
    return tipoSala;
}

std::vector<GrupoTurma> Turma::getListaGrupos() {
    std::vector<GrupoTurma> lista;


    /*
    DANDO ERRO NA HORA DE CHAMAR O GET, PRECISA DE INSTANCIAR UM OBJETO?
    for(std::vector<int>::iterator g = grupoTurma.begin(); g!= grupoTurma.end(); ++g){
        lista.push_back(GrupoTurma.getGrupo(*g));
    }*/
    return lista;
}

bool Turma::colide(Horario horario) {
    for(std::vector<Horario>::iterator h = getHorarios().begin(); h!= getHorarios().end(); ++h){
        Horario horarioaux = *h;
        if (horarioaux.colide(horario)) {
            return true;
        }
    }
    return false;
}
