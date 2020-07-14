
#ifndef PROJECAO_H
#define PROJECAO_H

#include "matriz.h"
#include "Ponto3D.h"

class Projecao
{
    public:
        //inicializa a matriz com a identidade
        Projecao(){projecao.identidade_ini();}

        void setCavaleira();
        void setOrtogonalParalela();
        void projetaPonto(Ponto3D &ponto);
        void impressao(){projecao.impressao();}

    private:
        Matriz4x4 projecao;

};

#endif