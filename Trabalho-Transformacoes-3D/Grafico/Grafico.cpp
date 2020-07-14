#include "Grafico.h"


void Grafico::grpDesenhaLinha(Ponto3D p1, Ponto3D p2)
{
    float largura = formTela->pnlGrafico->Width/2;
    float altura = formTela->pnlGrafico->Height/2;

    //aplica transformações de transformações sobre um ponto
    transformaPonto3D(p1);
    transformaPonto3D(p2);

    //aplica transformações de projeção sobre um ponto
    projetaPonto3D(p1);
    projetaPonto3D(p2);

    formTela->imgGrafico->Canvas->MoveTo((int)(p1.getX()+largura), (int)(altura-p1.getY()));
    formTela->imgGrafico->Canvas->LineTo((int)(p2.getX()+largura), (int)(altura-p2.getY()));
}
