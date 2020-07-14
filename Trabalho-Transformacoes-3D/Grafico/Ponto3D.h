#ifndef PONTO3D_H
#define PONTO3D_H

#include <iostream>


class Ponto3D
{
    public:

        float vetor[4];

    public:

        Ponto3D(float x=0.0, float y=0.0, float z = 0.0);
        void setPonto3D(float x, float y, float z);
        void setPonto3D(int index, float value){vetor[index]=value;}
        float getX(){return vetor[0];}
        float getY(){return vetor[1];}
        float getZ(){return vetor[2];}
        float getPonto(int index){return vetor[index];}

        void impressao();

};


#endif

