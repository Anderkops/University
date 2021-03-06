#ifndef GRAFICO_H
#define GRAFICO_H

#include<iostream>
#include <math.h>

#include "Janela3d.h"


#define MAX_TAM_X  447
#define MAX_TAM_Y  463


#define PI 3.14159265f

#define _2PI 6.2831853f

#define RadToDeg 57.29577951f

#define DegToRad 0.017453293f

#define DegreesToRads( degrees ) ((degrees) * DegToRad)

#define ORD 4


using namespace std;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class _3D_Point
{
       public:
        float vetor[4];

       public:

        _3D_Point(float x=0.0, float y=0.0, float z = 0.0);
        void set_3D_Point(float x, float y, float z);
        void set_3D_Point(int index, float value){vetor[index]=value;}
        float getX(){return vetor[0];}
        float getY(){return vetor[1];}
        float getZ(){return vetor[2];}
        float getPonto(int index){return vetor[index];}
        void impressao();
};

//------------------------------------------------------------------------------

class Matrix_Ordem_4
{
       protected:
        float  matriz[ORD][ORD];
        float  Matrix_Ordem_4::determinante3x3(int NaoContaLinha, int NaoContaColuna)const;
       public:
              Matrix_Ordem_4();
              Matrix_Ordem_4 Matrix_Ordem_4::operator * (const float constante)const;
              Matrix_Ordem_4 Matrix_Ordem_4::operator * (const Matrix_Ordem_4 &B)const;
        bool  Matrix_Ordem_4::operator ==(const  Matrix_Ordem_4 &B) const ;
        float determinante4x4()const;
        void  identidade_ini();
        float get_Matrix(int i, int j) const;
        void  set_Matrix(int i, int j,float valor);
        Matrix_Ordem_4 &get_Matrix();
};

//------------------------------------------------------------------------------

class Transformacao3D
{
    public:
        void Transformacao(){transformacao.identidade_ini();}
        void translacao(float dx, float dy, float dz);
        void rotacao(float angulo, float eixoX, float eixoY, float eixoZ);
        void escala(float sx, float sy, float sz);
        void reflexaoXY();
        void reflexaoXZ();
        void reflexaoYZ();
        void setIdentidade(){transformacao.identidade_ini();}
        void transformaPonto(_3D_Point &ponto);
    private:
        Matrix_Ordem_4 transformacao;
};

//------------------------------------------------------------------------------

class Projecao3D
{
    private:
        Matrix_Ordem_4 projecao;
    public:
        void Projecao(){projecao.identidade_ini();}
        void setOrtogonalParalela();
        void projetaPonto(_3D_Point &ponto);
};

//------------------------------------------------------------------------------

class Z_Buffer
{
    private:
        float buff[MAX_TAM_Y][MAX_TAM_X];
    public:
        void zera();
        bool check_depth(float Z, int x, int y);
};

//------------------------------------------------------------------------------

class Grafico3D
{
    private:
        Projecao3D projecao;
        Transformacao3D transformacao;
        Z_Buffer z_buffer;
        TColor cor;
        TPrincipal *Principal;
    public:

        void Grafico(){}
        void setGrafico(TPrincipal *Principal){this->Principal = Principal;}
        void setCor(TColor cor){this->cor = cor;}

        void zera_Transformacao(){transformacao.setIdentidade();}
        void translacao(float dx, float dy, float dz){transformacao.translacao(dx,dy,dz);}
        void rotacao(float angulo, float x, float y, float z){transformacao.rotacao(angulo,x,y,z);}
        void escala(float sx, float sy, float sz){transformacao.escala(sx,sy,sz);}

        void reflexaoXY(){transformacao.reflexaoXY();}
        void reflexaoXZ(){transformacao.reflexaoXZ();}
        void reflexaoYZ(){transformacao.reflexaoYZ();}

        void setProjOrtogonalParalela(){projecao.setOrtogonalParalela();}

        void figura_DesenhaPonto(_3D_Point p);
        void figura_DesenhaLinha(_3D_Point p1, _3D_Point p2);
        void figura_Cubo(int fator=20.0);
        void figura_Esfera(float raio=30.0);
        void figura_Cilindro(float altura=20.0, float raio=50.0);
        void figura_Cone(float altura=50.0);
        void figura_Superficie(float xmin=-10, float xmax=10, float ymin=-10, float ymax=10);
        void figura_Plano(float xmin=-25, float xmax=25, float ymin=-25, float ymax=25);

        void zera_Z_Buffer(){z_buffer.zera();}
        void transforma_3D_Point(_3D_Point &ponto){transformacao.transformaPonto(ponto);}
        void projeta_3D_Point(_3D_Point &ponto){projecao.projetaPonto(ponto);}
};

#endif
