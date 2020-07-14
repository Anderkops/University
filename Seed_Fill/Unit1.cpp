//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tform_Preenche *form_Preenche;

//-P R O T O T I P O S ------------------------------------------------------

int converteY(int YY);
void Vizinhanca4(int XX, int YY);
void Vizinhanca8(int XX, int YY);

//---------------------------------------------------------------------------
int x_semente, y_semente;
int x_temp, y_temp;
int x_pri, y_pri;
bool aux=true, pri=true;
TColor c_temp;
//---------------------------------------------------------------------------
__fastcall Tform_Preenche::Tform_Preenche(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int converteY(int YY)
{
return(-YY+400);
}
//---------------------------------------------------------------------------
void Vizinhanca4(int XX, int YY)
{
if((XX>=0)&&(XX<300)&&(YY>=0)&&(YY<300))
    {
    c_temp=form_Preenche->Image1->Canvas->Pixels[XX][YY];
    if(c_temp!=clBlack)
        {
        form_Preenche->Image1->Canvas->Pixels[XX][YY]=clBlack;
        Vizinhanca4(XX-1, YY);
        Vizinhanca4(XX+1, YY);
        Vizinhanca4(XX, YY-1);
        Vizinhanca4(XX, YY+1);
        }
    }
}
//---------------------------------------------------------------------------
void Preenchimento_v8(int XX, int YY)
{
if((XX>=0)&&(XX<300)&&(YY>=0)&&(YY<300))
    {
    c_temp=form_Preenche->Image1->Canvas->Pixels[XX][YY];
    if(c_temp!=clBlack)
        {
        form_Preenche->Image1->Canvas->Pixels[XX][YY]=clBlack;
        Preenchimento_v8(XX-1, YY);
        Preenchimento_v8(XX+1, YY);
        Preenchimento_v8(XX, YY-1);
        Preenchimento_v8(XX, YY+1);

        Preenchimento_v8(XX-1, YY-1);
        Preenchimento_v8(XX-1, YY+1);
        Preenchimento_v8(XX+1, YY-1);
        Preenchimento_v8(XX+1, YY+1);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall Tform_Preenche::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(aux==true)
    {
    if(Shift.Contains(ssLeft))
        {
        if(pri==true)
            {
            pri=false;
            x_pri=X;
            y_pri=Y;
            Image1->Canvas->MoveTo(X,Y);
            }
        else
            Image1->Canvas->LineTo(X,Y);
        }
    else
        if(Shift.Contains(ssRight))
            {
            Image1->Canvas->LineTo(x_pri,y_pri);
            aux=false;
            }
    }
else
    {
    x_semente = X;
    y_semente = Y;
    if(rdb_V4->Checked==true)
        Vizinhanca4(x_semente, y_semente);
    if(rdb_V8->Checked==true)
        Preenchimento_v8(x_semente, y_semente);
    }
}
//---------------------------------------------------------------------------
void __fastcall Tform_Preenche::FormCreate(TObject *Sender)
{
    //limpa a tela
    Image1->Picture = NULL;

    //escolhe a cor de desenho
    Image1->Canvas->Pen->Color = clBlack;

    //define a largura das linhas desenhadas
    Image1->Canvas->Pen->Width = 2;    
}
//---------------------------------------------------------------------------

void __fastcall Tform_Preenche::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
lblPosX->Caption=IntToStr(X);
lblPosY->Caption=IntToStr(converteY(Y));
}
//---------------------------------------------------------------------------

