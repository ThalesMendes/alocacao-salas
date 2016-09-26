#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Horario.h"
#include "TipoSala.h"
#include "GrupoTurma.h"

using namespace std;

class Turma
{

private:
    int id;
    string nome;
    string codigo;
    string professor;
    string departamento;
    std::vector<int> grupoTurma;//indices dos grupoTurma que a turma pertence
    std::vector<Horario> horarios;
    int tamanhoTurma;
    vector<vector<bool> > colisaoTurmas;
    int tipoSala = -1;
public:
    Turma(string nome, string codigo, std::vector<Horario> horarios, int tamanho, string professor, string departamento);
    std::vector<int> getGrupoTurma();
    void addGrupoTurma(int grupo);
    int getID();
    void setID(int id);
    vector<vector<bool> >  getColisaoTurmas();
    void setColisaoTurmas(vector<vector<bool> > colisaoTurmas);
    bool colide(Turma turma);
    int duracaoTotal();
    int dias();
    std::vector<Horario> getHorarios();
    string getCodigo();
    int getTamanho();
    int primeiroDia();
    string getNome();
    string getProfessor();
    string getDepartamento();
    int setTipoSala(std::vector<TipoSala> tiposSala);
    int getTipoSala();
    std::vector<GrupoTurma> getListaGrupos();
    bool colide(Horario horario);
};

