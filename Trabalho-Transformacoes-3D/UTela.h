//---------------------------------------------------------------------------

#ifndef UTelaH
#define UTelaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TformTela : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *menu;
    TMenuItem *Abri1;
    TMenuItem *Sair1;
    TPanel *Panel1;
    TPanel *pnlGrafico;
    TImage *imgGrafico;
    TGroupBox *GroupBox2;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edtEscX;
    TEdit *edtEscY;
    TEdit *edtEscZ;
    TButton *btnEscala;
    TGroupBox *rdgRotacao;
    TRadioButton *rdbEixoX;
    TRadioButton *rdbEixoY;
    TRadioButton *rdbEixoZ;
    TButton *btnRotacao;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *edtX;
    TEdit *edtY;
    TEdit *edtZ;
    TButton *Button1;
    TGroupBox *GroupBox3;
    TRadioButton *rdbParalela;
    TRadioButton *rdbCavaleira;
    TGroupBox *GroupBox4;
    TEdit *edtShr00;
    TEdit *edtShr01;
    TEdit *edtShr02;
    TEdit *edtShr10;
    TEdit *edtShr11;
    TEdit *edtShr12;
    TEdit *edtShr20;
    TEdit *edtShr21;
    TEdit *edtShr22;
    TRadioButton *rdbSherAplicar;
    TRadioButton *RadioButton2;
    TGroupBox *GroupBox5;
    TRadioButton *rdbRefXY;
    TRadioButton *rdbRefXZ;
    TRadioButton *rdbRefYZ;
    TRadioButton *rdbRefSem;
        void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall btnRotacaoMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall btnEscalaClick(TObject *Sender);
    void __fastcall rdbParalelaClick(TObject *Sender);
    void __fastcall rdbCavaleiraClick(TObject *Sender);
    void __fastcall rdbSherAplicarClick(TObject *Sender);
    void __fastcall rdbRefXYClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    
        __fastcall TformTela(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformTela *formTela;
//---------------------------------------------------------------------------
#endif
