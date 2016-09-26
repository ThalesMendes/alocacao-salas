#include <string>

using namespace std;

class Parametros
{
    private:
        double custoNaoAtendimento;
        double custoAtendSalaMaior;
        double custoConflitoAlocacao;//maior custo (maior dobro de nao alocacao)
        double custoGrupoSalaGrupoTurma;//maior custo (maior dobro de nao alocacao)
        double bonusSalaVaziaDia;//Se a sala estiver vazia o dia todo 4x
        double bonusSalaVaziaTurno;
        double bonusGrupoTurma;
        double custoPorGrupoSalaEmGrupoTurma;//muito menor que custo de nao atendimento
        int tempoMaximoProcessamento;
        string diretorio;
        string arquivoEntrada;
        string arquivoSolucao;
    public:
        double getCustoNaoAtendimento();
        double getCustoAtendSalaMaior();
        double getBonusSalaVaziaDia();
        double getBonusSalaVaziaTurno();
        double getCustoConflito();
        double getBonusGrupoTurma();
        double getCustoGrupoSalaGrupoTurma();
};
