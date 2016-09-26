#include <vector>
#include <string>
//#include "Turma.h"

using namespace std;

enum  Tipo {
    DISCIPLINA_HORARIO, //turmas que são da mesma disciplina e horario (ex: algoritmos, 14h)
    DISCIPLINA, //mesma disciplina
    PROFESSOR_HORARIO_CONSECUTIVO,
    DEPARTAMENTO,
    ERROR
};

class GrupoTurma
{
    private:
        int id;
        std::vector<int> turmas;
        Tipo tipo;
        string agrupamento;//razao do agrupamento e.g. Nome do Professor, Departamento, etc
        std::vector<GrupoTurma> grupoTurma;//array com todos os grupos
        GrupoTurma(Tipo tipo, string agrupamento);

    public:
        GrupoTurma criar(Tipo tipo, string agrupamento);
        //void addTurma(Turma turma);
        int getId();
        std::vector<int> getTurmas();
        Tipo getTipo();
        string getAgrupamento();
        int getNumeroTurmas();
        GrupoTurma getGrupo(int id);
        //bool verificaPertinencia(Turma turma);
};
