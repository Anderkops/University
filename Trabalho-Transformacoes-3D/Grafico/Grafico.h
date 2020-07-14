#ifndef GRAFICO_H
#define GRAFICO_H

#include "projecao.h"
#include "transformacao.h"
#include "Ponto3D.h"
#include "UTela.h"


class Grafico
{
    private:

        Projecao projecao;
        Transformacao transformacao;
        TformTela *formTela;

    public:

        Grafico(){}

        void setGrafico(TformTela *formTela){this->formTela = formTela;}

        void limpaTransformacao(){transformacao.setIdentidade(); transformacao.impressao();}
        void translacao(float dx, float dy, float dz){transformacao.translacao(dx,dy,dz);}
        void rotacao(float angulo, float x, float y, float z){transformacao.rotacao(angulo,x,y,z);}
        void escala(float sx, float sy, float sz){transformacao.escala(sx,sy,sz);}
        void shering(float s10,float s20,float s21,float s01,float s02,float s12){transformacao.shering(s10,s20,s21,s01,s02,s12);}

        void reflexaoXY(){transformacao.reflexaoXY();}
        void reflexaoXZ(){transformacao.reflexaoXZ();}
        void reflexaoYZ(){transformacao.reflexaoYZ();}

        void setProjCavaleira(){projecao.setCavaleira();}
        void setProjOrtogonalParalela(){projecao.setOrtogonalParalela();}

        void grpDesenhaLinha(Ponto3D p1, Ponto3D p2);

    //private:

        void transformaPonto3D(Ponto3D &ponto){transformacao.transformaPonto(ponto);}
        void projetaPonto3D(Ponto3D &ponto){projecao.projetaPonto(ponto);}

};

#endif