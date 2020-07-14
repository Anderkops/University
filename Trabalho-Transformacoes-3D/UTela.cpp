//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTela.h"
#include "Grafico.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformTela *formTela;
Grafico grafico;
Ponto3D casa[10];

float anguloX=0.0, anguloY=0.0, anguloZ=0.0;
float transX = -20.0, transY = -25.0, transZ=-15.0;
float escX=5.0, escY=5.0, escZ = 5.0;

void inicializaCasa()
{
    //Cria a casa3D

    //frente da casa
    casa[0] = Ponto3D(10,30,1);
    casa[1] = Ponto3D(10,10,1);
    casa[2] = Ponto3D(30,10,1);
    casa[3] = Ponto3D(30,30,1);
    casa[4] = Ponto3D(20,40,1);

    //parte de tras da casa
    casa[5] = Ponto3D(10,30,30);
    casa[6] = Ponto3D(10,10,30);
    casa[7] = Ponto3D(30,10,30);
    casa[8] = Ponto3D(30,30,30);
    casa[9] = Ponto3D(20,40,30);





}

void desenhaCasa()
{
    int i;
    //Desenha a parte da frente da casa
    for(i=0; i<4; i++)
        grafico.grpDesenhaLinha(casa[i],casa[i+1]);

    grafico.grpDesenhaLinha(casa[i],casa[0]);
    //grafico.grpDesenhaLinha(casa[i],casa[0]);

    //desnha a parte de tras da casa
    i++;
    for(;i<9;i++)
        grafico.grpDesenhaLinha(casa[i],casa[i+1]);
    grafico.grpDesenhaLinha(casa[i],casa[5]);

    //desenha as laterais da casa

    for(i=0;i<5;i++)
        grafico.grpDesenhaLinha(casa[i],casa[i+5]);

}

//---------------------------------------------------------------------------
__fastcall TformTela::TformTela(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TformTela::FormCreate(TObject *Sender)
{
    //limpa a tela
    imgGrafico->Picture = NULL;

    //escolhe a cor de preenchimento
    imgGrafico->Canvas->Pen->Color = clBlack;

    //define a largura das linhas desenhadas
    imgGrafico->Canvas->Pen->Width = 2;

    grafico.setGrafico(this);
    grafico.setProjOrtogonalParalela();

    inicializaCasa();






}
//---------------------------------------------------------------------------
void __fastcall TformTela::FormPaint(TObject *Sender)
{

    Transformacao trans;
    imgGrafico->Picture = NULL;


    grafico.limpaTransformacao();
    grafico.escala(escX,escY,escZ);

    //grafico.escala(5,5,1);
    //trans.escala(5,5,1);

    if(rdbSherAplicar->Checked)
    {
        float s10,s20,s21,s01,s02,s12;

        s10 = StrToFloat(edtShr10->Text);
        s20 = StrToFloat(edtShr20->Text);
        s21 = StrToFloat(edtShr21->Text);

        s01 = StrToFloat(edtShr01->Text);
        s02 = StrToFloat(edtShr02->Text);
        s12 = StrToFloat(edtShr12->Text);

        grafico.shering(s10,s20,s21,s01,s02,s12);
    }

    if(rdbRefXY->Checked)
    {
       grafico.reflexaoXY();

    }
    else if(rdbRefXZ->Checked)
    {
        grafico.reflexaoXZ();
    }
    else if(rdbRefYZ->Checked)
    {
        grafico.reflexaoYZ();
    }


    grafico.rotacao(anguloX,1.0,0.0,0.0);
    grafico.rotacao(anguloY,0.0,1.0,0.0);
    grafico.rotacao(anguloZ,0.0,0.0,1.0);

    grafico.translacao(transX,transY,transZ);



    /*grafico.translacao(5,0,0);
    grafico.grpDesenhaLinha(Ponto3D(0,0,0),Ponto3D(50,0,0));
    //imgGrafico->Canvas->Rectangle(Rect(100,100,200,200));*/
    desenhaCasa();


}
//---------------------------------------------------------------------------

void __fastcall TformTela::btnRotacaoMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(rdbEixoX->Checked)
        anguloX += 12;

    if(rdbEixoY->Checked)
        anguloY += 12;

    if(rdbEixoZ->Checked)
        anguloZ += 12;

    formTela->Paint();
}
//---------------------------------------------------------------------------


void __fastcall TformTela::Button1Click(TObject *Sender)
{
    transX = StrToFloat(edtX->Text);
    transY = StrToFloat(edtY->Text);
    transZ = StrToFloat(edtZ->Text);

    formTela->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TformTela::btnEscalaClick(TObject *Sender)
{
    escX = StrToFloat(edtEscX->Text);
    escY = StrToFloat(edtEscY->Text);
    escZ = StrToFloat(edtEscZ->Text);

    formTela->Paint();
}
//---------------------------------------------------------------------------





void __fastcall TformTela::rdbParalelaClick(TObject *Sender)
{
    grafico.setProjOrtogonalParalela();
    formTela->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TformTela::rdbCavaleiraClick(TObject *Sender)
{
    grafico.setProjCavaleira();
    formTela->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TformTela::rdbSherAplicarClick(TObject *Sender)
{
    formTela->Paint();
}
//---------------------------------------------------------------------------

void __fastcall TformTela::rdbRefXYClick(TObject *Sender)
{
    formTela->Paint();
}
//---------------------------------------------------------------------------

