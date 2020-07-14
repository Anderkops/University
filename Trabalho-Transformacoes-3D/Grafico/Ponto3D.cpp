#include "Ponto3D.h"


Ponto3D::Ponto3D(float x, float y, float z)
{
    setPonto3D(x,y,z);
}


void Ponto3D::setPonto3D(float x, float y, float z)
{
    vetor[0] = x;
    vetor[1] = y;
    vetor[2] = z;
    vetor[3] = 1.0;

}

void Ponto3D::impressao()
{
    std::cout<<"x: "<<getX()<<", "<<"y: "<<getY()<<", "<<"z: "<<getZ()<<std::endl;
}
 