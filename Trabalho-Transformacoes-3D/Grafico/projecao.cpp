
#include "projecao.h"

void Projecao::setCavaleira()
{
    //representa o seno e coseno de 45�
    const float cte(0.7071067781);

    //primeira coluna
    projecao.setMatriz(0,0,1.0);
    projecao.setMatriz(1,0,0.0);//0
    projecao.setMatriz(2,0,cte);
    projecao.setMatriz(3,0,0.0);

    //segunda coluna
    projecao.setMatriz(0,1,0.0);
    projecao.setMatriz(1,1,1.0);
    projecao.setMatriz(2,1,cte);
    projecao.setMatriz(3,1,0.0);

    //terceira coluna
    projecao.setMatriz(0,2,0.0);
    projecao.setMatriz(1,2,0.0);
    projecao.setMatriz(2,2,0.0);
    projecao.setMatriz(3,2,0.0);

    //quarta coluna
    projecao.setMatriz(0,3,0.0);
    projecao.setMatriz(1,3,0.0);
    projecao.setMatriz(2,3,0.0);
    projecao.setMatriz(3,3,1.0);
}

void Projecao::setOrtogonalParalela()
{
    //primeira coluna
    projecao.setMatriz(0,0,1.0);
    projecao.setMatriz(1,0,0.0);
    projecao.setMatriz(2,0,0.0);
    projecao.setMatriz(3,0,0.0);

    //segunda coluna
    projecao.setMatriz(0,1,0.0);
    projecao.setMatriz(1,1,1.0);
    projecao.setMatriz(2,1,0.0);
    projecao.setMatriz(3,1,0.0);

    //terceira coluna
    projecao.setMatriz(0,2,0.0);
    projecao.setMatriz(1,2,0.0);
    projecao.setMatriz(2,2,0.0);
    projecao.setMatriz(3,2,0.0);

    //quarta coluna
    projecao.setMatriz(0,3,0.0);
    projecao.setMatriz(1,3,0.0);
    projecao.setMatriz(2,3,0.0);
    projecao.setMatriz(3,3,1.0);
}

void Projecao::projetaPonto(Ponto3D &ponto)
{

    Ponto3D temp;


    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //temp.setPonto3D(i,(transformacao.getMatriz(i,j) * ponto.getPonto(i)));

            temp.vetor[i]+= (projecao.getMatriz(i,j) * ponto.getPonto(j));
        }

    }
    ponto = temp;
}
