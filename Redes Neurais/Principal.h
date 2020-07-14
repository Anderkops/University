//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "Library/RedeNeural.h"
#include <ComCtrls.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TOpenDialog *OpenDialog3;
    TOpenDialog *OpenDialog4;
    TSaveDialog *SaveDialog3;
    TMainMenu *MainMenu1;
    TMenuItem *Menu_Arquivo;
    TMenuItem *AbrirArquivoTreinamento1;
    TMenuItem *AbrirArquivoTeste1;
    TMenuItem *Sair1;
    TSaveDialog *SaveDialog2;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TGroupBox *GroupBox12;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TGroupBox *GroupBox9;
        TStringGrid *StringGrid2;
        TGroupBox *GroupBox8;
        TButton *BotaoReconhecimento;
        TGroupBox *GroupBox6;
        TButton *Button4;
        TGroupBox *GroupBox4;
        TStringGrid *StringGrid4;
        TGroupBox *GroupBox10;
        TStringGrid *StringGrid3;
        TStatusBar *StatusBar1;

        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall BotaoReconhecimentoClick(TObject *Sender);
    void __fastcall AbrirArquivoTreinamento1Click(TObject *Sender);
    void __fastcall AbrirArquivoTeste1Click(TObject *Sender);
        void __fastcall Sair1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void joganamatriz(Double classe,Double resultado);
        void resetamatrizconf();
        void imprimematrizconf();
        //OBJETO BPNN
        BackPropagation BP1;
        BackPropagation BP2;

        AnsiString Arquivo_Teste;  
        int xNosDeEntrada;
        int xCamadasOcultas;
        int xNosDeSaida;
        int xAmostras;
        int x2NosDeEntrada;
        int x2NosDeSaida;
        int x2Amostras;
        Matrix2D xAmostraEntrada;
        Matrix2D xAmostraSaida;
        Matrix2D x2AmostraEntrada;
        Matrix2D x2AmostraSaida;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
