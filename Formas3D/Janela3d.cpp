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

enum {CUBO,ESFERA,CONE,CILINDRO,PLANO,SUPERFICIE}Fig_Geometrica;
int cont = 0;


float x_trans = 0.0, y_trans = 0.0, z_trans = 0.0;
float x_esc=1.0, y_esc=1.0, z_esc = 1.0;
float angulo_X=0.0, angulo_Y=0.0, angulo_Z=0.0;

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

    graf.rotacao(angulo_X,1.0,0.0,0.0);
    graf.rotacao(angulo_Y,0.0,1.0,0.0);
    graf.rotacao(angulo_Z,0.0,0.0,1.0);

    graf.translacao(x_trans,y_trans,z_trans);
    desenhar();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::btn_rotMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(rdb_eixoX_rot->Checked)
        angulo_X += 12;

    if(rdb_eixoY_rot->Checked)
        angulo_Y += 12;

    if(rdb_eixoZ_rot->Checked)
        angulo_Z += 12;

    Principal->Paint();
}
//---------------------------------------------------------------------------


void __fastcall TPrincipal::btn_transClick(TObject *Sender)
{
    x_trans = StrToFloat(edt_eixoX_trans->Text);
    y_trans = StrToFloat(edt_eixoY_trans->Text);
    z_trans = StrToFloat(edt_eixoZ_trans->Text);

    Principal->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TPrincipal::btn_EscClick(TObject *Sender)
{
    x_esc = StrToFloat(edt_eixoX_esc->Text);
    y_esc = StrToFloat(edt_eixoY_esc->Text);
    z_esc = StrToFloat(edt_eixoZ_esc->Text);

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


