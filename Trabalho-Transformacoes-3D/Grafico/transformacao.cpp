
#include "transformacao.h"
#include<cmath>


//multiplica a matriz de transforma��o corrente pela
//matriz de transla��o
void Transformacao::translacao(float dx, float dy, float dz)
{
    Matriz4x4 translacao;

    //inicializa com a identidade
    translacao.identidade_ini();

    //coloca o tanto que ira transladar
    translacao.setMatriz(0,3,dx);
    translacao.setMatriz(1,3,dy);
    translacao.setMatriz(2,3,dz);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de rota��o
    transformacao = transformacao * translacao;
}

//multiplica a matriz de transforma��o corrente pela
//matriz de Rota��o
void Transformacao::rotacao(float angulo, float eixoX, float eixoY, float eixoZ)
{
    Matriz4x4 rotacao;
    float c, s, ang;

    ang = DegreesToRads(angulo);
    //ang = ang*DegToRad;
    c = cos(ang);
    s = sin(ang);

    cout<<"\nValor do Coseno: "<<c<<endl;
    cout<<"\nPosicao [0][0] da matriz: "<<(c+(1-c)*pow(eixoX,2))<<endl<<endl;

    rotacao.identidade_ini();

    //primeira coluna
    rotacao.setMatriz(0,0,(c+(1-c)*pow(eixoX,2)));
    rotacao.setMatriz(1,0,((1-c)*(eixoX*eixoY)+(s*eixoZ)));
    rotacao.setMatriz(2,0,((1-c)*(eixoX*eixoZ)-(s*eixoY)));


    //segunda coluna
    rotacao.setMatriz(0,1,((1-c)*(eixoX*eixoY)-(s*eixoZ)));
    rotacao.setMatriz(1,1,(c+(1-c)*pow(eixoY,2)));
    rotacao.setMatriz(2,1,((1-c)*(eixoY*eixoZ)+(s*eixoX)));



    //terceira coluna
    rotacao.setMatriz(0,2,((1-c)*(eixoX*eixoZ)+(s*eixoY)));
    rotacao.setMatriz(1,2,((1-c)*(eixoY*eixoZ)-(s*eixoX)));
    rotacao.setMatriz(2,2,(c+(1-c)*pow(eixoZ,2)));


    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de rota��o
    transformacao = transformacao * rotacao;

    transformacao.impressao();

}

//multiplica a matriz de transforma��o corrente pela
//matriz de escala
void Transformacao::escala(float sx, float sy, float sz)
{
    Matriz4x4 escala;

    escala.identidade_ini();

    //cria a matriz de escala
    escala.setMatriz(0,0,sx);
    escala.setMatriz(1,1,sy);
    escala.setMatriz(2,2,sz);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de escala
    transformacao = transformacao * escala;

    transformacao.impressao();

}


void Transformacao::shering(float s10,float s20,float s21,float s01,float s02,float s12)
{
    Matriz4x4 shering;

    shering.identidade_ini();

    shering.setMatriz(1,0,s10);
    shering.setMatriz(2,0,s20);
    shering.setMatriz(2,1,s21);

    shering.setMatriz(0,1,s01);
    shering.setMatriz(0,2,s02);
    shering.setMatriz(1,2,s12);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de shering
    transformacao = transformacao * shering;
}

void Transformacao::reflexaoXY()
{
    Matriz4x4 reflexaoXY;

    reflexaoXY.identidade_ini();

    reflexaoXY.setMatriz(2,2,-1);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de Refexao
    transformacao = transformacao * reflexaoXY;

}

void Transformacao::reflexaoXZ()
{
    Matriz4x4 reflexaoXY;

    reflexaoXY.identidade_ini();

    reflexaoXY.setMatriz(1,1,-1);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de Refexao
    transformacao = transformacao * reflexaoXY;

}

void Transformacao::reflexaoYZ()
{
    Matriz4x4 reflexaoXY;

    reflexaoXY.identidade_ini();

    reflexaoXY.setMatriz(0,0,-1);

    //a matriz de projecao atual recebe a multiplicacao dela
    //pela matriz de Refexao
    transformacao = transformacao * reflexaoXY;

}



void Transformacao::transformaPonto(Ponto3D &ponto)
{

    Ponto3D temp;


    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //temp.setPonto3D(i,(transformacao.getMatriz(i,j) * ponto.getPonto(i)));

            temp.vetor[i]+= (transformacao.getMatriz(i,j) * ponto.getPonto(j));
        }

    }
    ponto = temp;
}

