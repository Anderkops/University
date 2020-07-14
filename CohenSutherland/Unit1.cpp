//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TJanela *Janela;
int X1, X2, Y1, Y2;                  // variaveis para P1 e P2
int XL=100, XR=400, YT=300, YB=100;  // posicoes das retas q formam a janela
int largIMG, altIMG;

// PROTOTIPOS ---------------------------------------------------------------

int converteY(int Y);
void Desenha_janela();

//---------------------------------------------------------------------------
__fastcall TJanela::TJanela(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int converteY(int Y)
{
return(-Y+altIMG);
}
//---------------------------------------------------------------------------
void __fastcall TJanela::FormCreate(TObject *Sender)
{
    altIMG = Image1->Height;
    largIMG =  Image1->Width;

    //limpa a tela
    Image1->Picture = NULL;

    //escolhe a cor de desenho
    //Image1->Canvas->Pen->Color = clBlack;

    //define a largura das linhas desenhadas
    Image1->Canvas->Pen->Width = 1;

    // desenha as linhas azul claro da tela
    Image1->Canvas->Pen->Color = clAqua;
    Image1->Canvas->MoveTo(0,converteY(YB));
    Image1->Canvas->LineTo(largIMG,converteY(YB));
    Image1->Canvas->MoveTo(XR,converteY(0));
    Image1->Canvas->LineTo(altIMG,converteY(largIMG));
    Image1->Canvas->MoveTo(largIMG,converteY(YT));
    Image1->Canvas->LineTo(0,converteY(YT));
    Image1->Canvas->MoveTo(XL,converteY(altIMG));
    Image1->Canvas->LineTo(XL,converteY(0));

    // desenha a "janela" 
    Image1->Canvas->Pen->Color = clBlack;
    Image1->Canvas->MoveTo(XL,converteY(YB));
    Image1->Canvas->LineTo(XR,converteY(YB));
    Image1->Canvas->LineTo(XR,converteY(YT));
    Image1->Canvas->LineTo(XL,converteY(YT));
    Image1->Canvas->LineTo(XL,converteY(YB));
}
//---------------------------------------------------------------------------

void __fastcall TJanela::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
X1 = X;
Y1 = converteY(Y);
edtP1X->Text=X1;
edtP1Y->Text=Y1;
}
//---------------------------------------------------------------------------

void __fastcall TJanela::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
X2 = X;
Y2 = converteY(Y);
edtP2X->Text=X2;
edtP2Y->Text=Y2;

if((X2>0)&&(X2<500)&&(Y2>0)&&(Y2<400)&&(X1!=X2)&&(Y1!=Y2))
    {
    // PASSO 1: associar oc codigos aos pontos extremos do segmento
    int P1[4], P2[4];

    if(X1<XL) P1[3]=1; else P1[3]=0;
    if(X1>XR) P1[2]=1; else P1[2]=0;
    if(Y1<YB) P1[1]=1; else P1[1]=0;
    if(Y1>YT) P1[0]=1; else P1[0]=0;

    edtP1C1->Text=P1[0];
    edtP1C2->Text=P1[1];
    edtP1C3->Text=P1[2];
    edtP1C4->Text=P1[3];

    if(X2<XL) P2[3]=1; else P2[3]=0;
    if(X2>XR) P2[2]=1; else P2[2]=0;
    if(Y2<YB) P2[1]=1; else P2[1]=0;
    if(Y2>YT) P2[0]=1; else P2[0]=0;
    
    edtP2C1->Text=P2[0];
    edtP2C2->Text=P2[1];
    edtP2C3->Text=P2[2];
    edtP2C4->Text=P2[3];

    // PASSO 2: verificar se eh totalmente visivel
    int P1codZero=1, P2codZero=1, Ptemp[4], resAND=0;
    for(int i=0; i<4; i++)
        {
        if(P1[i]!=0)
            {
            P1codZero=0;
            }
        if(P2[i]!=0)
            {
            P2codZero=0;
            }
        }
    for(int j=0; j<4; j++)
        if((P1[j]==1)&(P2[j])==1)
            Ptemp[j]=1;
        else
            Ptemp[j]=0;
    for(int j=0; j<4; j++)
        if(Ptemp[j]==1)
            {
            resAND=1;
            break;
            }

    if((P1codZero!=0)&&(P2codZero!=0))
        {
        Image1->Canvas->Pen->Color = clBlue;
        Image1->Canvas->MoveTo(X1,converteY(Y1));
        Image1->Canvas->LineTo(X2,converteY(Y2));
        }

    // PASSO 3: verificar se eh totalmente invisivel
    else if(resAND)
        {
        Image1->Canvas->Pen->Color = clLtGray;
        Image1->Canvas->MoveTo(X1,converteY(Y1));
        Image1->Canvas->LineTo(X2,converteY(Y2));
        }

    // PASSO 4: verificar se um dos pontos esta dentro da janela
    else if((P1codZero!=0)||(P2codZero!=0))
        {
        int x_int, y_int, x_ext, y_ext;
        if(P1codZero!=0)
            {
            x_int=X1;
            y_int=Y1;
            x_ext=X2;
            y_ext=Y2;
            }
        else
            {
            x_int=X2;
            y_int=Y2;
            x_ext=X1;
            y_ext=Y1;
            }

        int dx, dy;
        float a, b;
        dx=x_ext-x_int;
        dy=y_ext-y_int;
        a=(float)dy/dx;
        b=(float)-a*x_int+y_int;
        if(x_ext<XL)
            {
            int y_aux;
            y_aux=(int)(a*XL+b);
            if((y_aux>YB)&&(y_aux<YT))
                {
                Image1->Canvas->Pen->Color = clLtGray;
                Image1->Canvas->MoveTo(XL,converteY(y_aux));
                Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                Image1->Canvas->Pen->Color = clBlue;
                Image1->Canvas->MoveTo(x_int,converteY(y_int));
                Image1->Canvas->LineTo(XL,converteY(y_aux));
                }
            else
                if(y_aux<YB)
                    {
                    int x_aux;
                    x_aux=(int)(YB-b)/a;

                    Image1->Canvas->Pen->Color = clLtGray;
                    Image1->Canvas->MoveTo(x_aux,converteY(YB));
                    Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                    Image1->Canvas->Pen->Color = clBlue;
                    Image1->Canvas->MoveTo(x_int,converteY(y_int));
                    Image1->Canvas->LineTo(x_aux,converteY(YB));
                    }
                else
                    {
                    int x_aux;
                    x_aux=(int)(YT-b)/a;

                    Image1->Canvas->Pen->Color = clLtGray;
                    Image1->Canvas->MoveTo(x_aux,converteY(YT));
                    Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                    Image1->Canvas->Pen->Color = clBlue;
                    Image1->Canvas->MoveTo(x_int,converteY(y_int));
                    Image1->Canvas->LineTo(x_aux,converteY(YT));
                    }
            }
        else if(x_ext>XR)
            {
            int y_aux;
            y_aux=(int)(a*XR+b);
            if((y_aux>YB)&&(y_aux<YT))
                {
                Image1->Canvas->Pen->Color = clLtGray;
                Image1->Canvas->MoveTo(XR,converteY(y_aux));
                Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                Image1->Canvas->Pen->Color = clBlue;
                Image1->Canvas->MoveTo(x_int,converteY(y_int));
                Image1->Canvas->LineTo(XR,converteY(y_aux));
                }
            else
                if(y_aux<YB)
                    {
                    int x_aux;
                    x_aux=(int)(YB-b)/a;

                    Image1->Canvas->Pen->Color = clLtGray;
                    Image1->Canvas->MoveTo(x_aux,converteY(YB));
                    Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                    Image1->Canvas->Pen->Color = clBlue;
                    Image1->Canvas->MoveTo(x_int,converteY(y_int));
                    Image1->Canvas->LineTo(x_aux,converteY(YB));
                    }
                else
                    {
                    int x_aux;
                    x_aux=(int)(YT-b)/a;

                    Image1->Canvas->Pen->Color = clLtGray;
                    Image1->Canvas->MoveTo(x_aux,converteY(YT));
                    Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                    Image1->Canvas->Pen->Color = clBlue;
                    Image1->Canvas->MoveTo(x_int,converteY(y_int));
                    Image1->Canvas->LineTo(x_aux,converteY(YT));
                    }
            }
        else if(y_ext<YB)
            {
            int x_aux;
            x_aux=(int)(YB-b)/a;
            if((x_aux>XL)&&(x_aux<XR))
                {
                Image1->Canvas->Pen->Color = clLtGray;
                Image1->Canvas->MoveTo(x_aux,converteY(YB));
                Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                Image1->Canvas->Pen->Color = clBlue;
                Image1->Canvas->MoveTo(x_int,converteY(y_int));
                Image1->Canvas->LineTo(x_aux,converteY(YB));
                }
            }
        else if(y_ext>YT)
            {
            int x_aux;
            x_aux=(int)(YT-b)/a;
            if((x_aux>XL)&&(x_aux<XR))
                {
                Image1->Canvas->Pen->Color = clLtGray;
                Image1->Canvas->MoveTo(x_aux,converteY(YT));
                Image1->Canvas->LineTo(x_ext,converteY(y_ext));

                Image1->Canvas->Pen->Color = clBlue;
                Image1->Canvas->MoveTo(x_int,converteY(y_int));
                Image1->Canvas->LineTo(x_aux,converteY(YT));
                }
            }
        }
    // PASSO 5: a linha eh parcialmente vis�vel ou totalmente invisivel
    else
        {
        int dx, dy;
        float a;
        int x_jan[2], y_jan[2], cont=0;
        int x_aux, y_aux;
        dx=X2-X1;
        dy=Y2-Y1;
        a=(float)dy/dx;
        x_jan[0]=0;
        x_jan[1]=0;
        y_jan[0]=0;
        y_jan[1]=0;

        // intersec��o com XL
        y_aux=(int)(a*(XL-X1))+Y1;
        if((y_aux>YB)&&(y_aux<YT))
            {
            x_jan[cont]=XL;
            y_jan[cont]=y_aux;
            cont++;
            }
        // intersec��o com XR
        y_aux=(int)(a*(XR-X1))+Y1;
        if((y_aux>YB)&&(y_aux<YT))
            {
            x_jan[cont]=XR;
            y_jan[cont]=y_aux;
            cont++;
            }
        // intersec��o com YB
        x_aux=(int)X1+(1/a)*(YB-Y1);
        if((x_aux>XL)&&(x_aux<XR))
            {
            x_jan[cont]=x_aux;
            y_jan[cont]=YB;
            cont++;
            }
        // intersec��o com YT
        x_aux=(int)X1+(1/a)*(YT-Y1);
        if((x_aux>XL)&&(x_aux<XR))
            {
            x_jan[cont]=x_aux;
            y_jan[cont]=YT;
            }

        Image1->Canvas->Pen->Color = clLtGray;
        Image1->Canvas->MoveTo(X1,converteY(Y1));
        Image1->Canvas->LineTo(X2,converteY(Y2));
        if(x_jan[0]!=0)
            {
            Image1->Canvas->Pen->Color = clBlue;
            Image1->Canvas->MoveTo(x_jan[0],converteY(y_jan[0]));
            Image1->Canvas->LineTo(x_jan[1],converteY(y_jan[1]));
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TJanela::Image1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
lblXatual->Caption = X;
lblYatual->Caption = converteY(Y);
}
//---------------------------------------------------------------------------
