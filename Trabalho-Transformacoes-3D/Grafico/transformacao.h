#ifndef TRANSFORMACAO_H
#define TRANSFORMACAO_H

#include "matriz.h"
#include "Ponto3D.h"

#include<iostream>

#define PI 3.14159265f

#define RadToDeg 57.29577951f

#define DegToRad 0.017453293f

#define DegreesToRads( degrees ) ((degrees) * DegToRad)


using namespace std;

class Transformacao
{
    public:
        //inicializa com a matriz identidade
        Transformacao(){transformacao.identidade_ini();}

        void translacao(float dx, float dy, float dz);
        void rotacao(float angulo, float eixoX, float eixoY, float eixoZ);
        void escala(float sx, float sy, float sz);
        void reflexaoXY();
        void reflexaoXZ();
        void reflexaoYZ();

        void shering(float s10,float s20,float s21,float s01,float s02,float s12);
        void setIdentidade(){transformacao.identidade_ini();}
        //void transforma verice()
        void impressao(){transformacao.impressao();}

        void transformaPonto(Ponto3D &ponto);

    private:
    
        Matriz4x4 transformacao;
};

#endif