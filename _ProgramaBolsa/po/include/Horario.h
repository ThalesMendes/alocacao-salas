#include <string>

using namespace std;

enum  Turno{MANHA, TARDE, NOITE, ERRO};
enum  DiaSemana{SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA};

class Horario
{

private:
    int id;
    int inicio;
public:
    int checaDia(int horario);
    int MAXIMO = 80;
    Turno checaTurno(int horario);
    Horario(int inicio, DiaSemana diaDaSemana);
    Horario(int inicio, int diaDaSemana);
    int fim();
    bool colide(Horario horario);
    int getDiaSemana();
    int getInicio();
    int getID();
    Turno getTurno();
    int getTurnoInt();
    string toString();
};

