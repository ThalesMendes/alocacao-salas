#include "Horario.h"
#include "TipoSala.h"
#include <vector>
#include <string>

using namespace std;

class Sala
{
    private:
        int id;
        int tipoSala = -1;
        string codigo;
        std::vector<Horario> indisponibilidade;
        int grupoSala;
    public:
        Sala(string codigo, TipoSala tipoSala, std::vector<Horario> indisponibilidade);
        int getCapacidade();
        string getCodigo();
        std::vector<Horario> getIndisponibilidade();
        int getID();
        void setID(int id);
        int getTipoSala();
        int getGrupoSala();
        void setGrupoSala(int grupoSala);
};

