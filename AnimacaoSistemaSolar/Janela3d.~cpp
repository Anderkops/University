//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Janela3d.h"
#include "Grafico3D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrincipal *Principal;
Grafico3D graf;

long int numIMG = 101;

enum {CUBO,ESFERA,CONE,CILINDRO,PLANO,SUPERFICIE}Fig_Geometrica;
int cont = 0;


float x_trans = 0.0, y_trans = 0.0, z_trans = 0.0;
float x_esc=1.0, y_esc=1.0, z_esc = 1.0;
float angulo_X=0.0, angulo_Y=0.0, angulo_Z=0.0;

int angP1=0, angP2=0, angP3=0, angP4=0, angP5=0, angP6=0, angP7=0, angP8=0, angP9=0;

void desenhar()
{
    switch(Fig_Geometrica)
    {
        case CUBO:
            graf.setCor(clBlack);
            graf.figura_Cubo();
        break;

        case ESFERA:
            graf.setCor(clGreen);
            graf.figura_Esfera();
        break;

        case CONE:
            graf.setCor(clYellow);
            graf.figura_Cone();
        break;

        case CILINDRO:
            graf.setCor(clAqua);
            graf.figura_Cilindro();
        break;

        case PLANO:
             graf.setCor(clRed);
             graf.figura_Plano();
        break;

        case SUPERFICIE:
             graf.setCor(clBlue);
             graf.figura_Superficie();
        break;
    }

}

//---------------------------------------------------------------------------
__fastcall TPrincipal::TPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::FormCreate(TObject *Sender)
{
    graf.setGrafico(this);
    graf.setProjOrtogonalParalela();

    Fig_Geometrica = CUBO;

}
//---------------------------------------------------------------------------
void __fastcall TPrincipal::FormPaint(TObject *Sender)
{

    Transformacao3D trans;
    imgGrafico->Picture = NULL;

    graf.zera_Z_Buffer();

    graf.zera_Transformacao();
    graf.escala(x_esc,y_esc,z_esc);
    for(int i=0;i<MAX_TAM_X;i++)
     for(int j=0;j<MAX_TAM_Y;j++)
     {
      Principal->imgGrafico->Canvas->Pixels[i][j] = clBlack;
     }
    graf.rotacao(angulo_X,1.0,0.0,0.0);
    graf.rotacao(angulo_Y,0.0,1.0,0.0);
    graf.rotacao(angulo_Z,0.0,0.0,1.0);

    graf.translacao(x_trans,y_trans,z_trans);
    //desenhar();

    graf.rotacao(45,1.0,0.0,0.0);

    //SOL
    graf.empilhaTransformacao();
        graf.setCor(clYellow);
        graf.figura_Esfera(30);
    graf.desempilhaTransformacao();

    // MERCURIO
    graf.empilhaTransformacao();

        graf.setCor(clRed);
        graf.rotacao(angP1 ,0.0,1.0,0.0);
        graf.translacao(50,0,0);
        graf.figura_Esfera(2);
    graf.desempilhaTransformacao();

    // VENUS
    graf.empilhaTransformacao();
        graf.rotacao(angP2,0.0,1.0,0.0);
        graf.translacao(60,0,0);
        graf.setCor(cl3DDkShadow);
        graf.figura_Esfera(4);
    graf.desempilhaTransformacao();

    // TERRA
    graf.empilhaTransformacao();
        graf.rotacao(angP3,0.0,1.0,0.0);
        graf.translacao(75,0,0);
        graf.setCor(clHotLight);
        graf.figura_Esfera(5);
    graf.desempilhaTransformacao();

    // MARTE
    graf.empilhaTransformacao();
        graf.rotacao(angP4,0.0,1.0,0.0);
        graf.translacao(90,0,0);
        graf.setCor(clRed);
        graf.figura_Esfera(3);
    graf.desempilhaTransformacao();

    // JUPITER
    graf.empilhaTransformacao();
        graf.rotacao(angP5,0.0,1.0,0.0);
        graf.translacao(110,0,0);
        graf.setCor(clMaroon);
        graf.figura_Esfera(12);
    graf.desempilhaTransformacao();

    // SATURNO
    graf.empilhaTransformacao();
        graf.rotacao(angP6,0.0,1.0,0.0);
        graf.translacao(150,0,0);
        graf.setCor(clOlive);
        graf.figura_Esfera(10);
    graf.desempilhaTransformacao();

    graf.empilhaTransformacao();
        graf.rotacao(angP6,0.0,1.0,0.0);
        graf.translacao(150,0,0);
        graf.rotacao(80,1.0,0.0,0.0);
        graf.rotacao(10,0.0,1.0,0.0);
        graf.setCor(clOlive);
        graf.figura_Cilindro(3, 20);
    graf.desempilhaTransformacao();

    // URANO
    graf.empilhaTransformacao();
        graf.rotacao(angP7,0.0,1.0,0.0);
        graf.translacao(185,0,0);
        graf.setCor(clAqua);
        graf.figura_Esfera(8);
    graf.desempilhaTransformacao();

    // NETUNO
    graf.empilhaTransformacao();
        graf.rotacao(angP8,0.0,1.0,0.0);
        graf.translacao(210,0,0);
        graf.setCor(clBlue);
        graf.figura_Esfera(7);
    graf.desempilhaTransformacao();

    /*
    // PLUTAO
    graf.empilhaTransformacao();
        graf.rotacao(angP9,0.0,1.0,0.0);
        graf.translacao(215,0,0);
        //graf.setCor(clBlue);
        graf.figura_Esfera(2);
    graf.desempilhaTransformacao();
    */

        graf.setCor(clGray);

        graf.figura_Cilindro(0.1, 50);
        graf.figura_Cilindro(0.1, 60);
        graf.figura_Cilindro(0.1, 75);
        graf.figura_Cilindro(0.1, 90);
        graf.figura_Cilindro(0.1, 110);
        graf.figura_Cilindro(0.1, 150);
        graf.figura_Cilindro(0.1, 185);
        graf.figura_Cilindro(0.1, 210);

    imgGrafico->Picture->SaveToFile("imagens\\solar"+IntToStr(numIMG++)+".bmp");
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::btn_rotMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    
    Principal->Paint();
}
//---------------------------------------------------------------------------


void __fastcall TPrincipal::btn_transClick(TObject *Sender)
{
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::btn_EscClick(TObject *Sender)
{
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Cubo1Click(TObject *Sender)
{
    Fig_Geometrica =CUBO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Esfera1Click(TObject *Sender)
{
    Fig_Geometrica=ESFERA;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Cone1Click(TObject *Sender)
{
    Fig_Geometrica=CONE;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Cilindro1Click(TObject *Sender)
{
    Fig_Geometrica=CILINDRO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Plano1Click(TObject *Sender)
{
    Fig_Geometrica=PLANO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::Superficie1Click(TObject *Sender)
{
    Fig_Geometrica =SUPERFICIE;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_CuboClick(TObject *Sender)
{
    Fig_Geometrica =CUBO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_EsferaClick(TObject *Sender)
{
    Fig_Geometrica=ESFERA;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_ConeClick(TObject *Sender)
{
    Fig_Geometrica =CONE;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_CilindroClick(TObject *Sender)
{
    Fig_Geometrica =CILINDRO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_PlanoClick(TObject *Sender)
{
    Fig_Geometrica =PLANO;
    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::rdb_SuperficieClick(TObject *Sender)
{
    Fig_Geometrica =SUPERFICIE;
    Principal->Paint();
}
//---------------------------------------------------------------------------


void __fastcall TPrincipal::Button1Click(TObject *Sender)
{
       angP1+=12;
       angP2+=10;
       angP3+=9;
       angP4+=7;
       angP5+=6;
       angP6+=4;
       angP7+=3;
       angP8+=2;
       angP9+=1;
       Principal->Paint();
}
//---------------------------------------------------------------------------

