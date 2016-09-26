#include <vector>
#include <map>

class TipoSala
{
    private:
         int id;
         std::vector<int> turmas;
         std::vector<int> salas;
         std::map<int , TipoSala> tiposSala;
         TipoSala(int cap);

    public:
        TipoSala();
        int capacidade;
        TipoSala getTipo(int i);
        std::vector<int> getTurmas(int i);
        void setTurmas(int i,std::vector<int> turmas);
        TipoSala tipoSalaFactory(int cap);
        int getCapacidade(int i);
        int getID(int i);
        int getID();
        void setID(int i,int id) ;
        void setID(int id);
        std::vector<int> getSalas(int i) ;
        void setSalasPorTipo(int i,std::vector<int> aSalasPorTipo);
        std::map<int,TipoSala> getTiposSala();
};
