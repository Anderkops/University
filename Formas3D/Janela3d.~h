//---------------------------------------------------------------------------

#ifndef Janela3dH
#define Janela3dH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TPrincipal : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TGroupBox *GroupBox2;
        TLabel *lbl_eixoX_esc;
        TLabel *lbl_eixoY_esc;
        TLabel *lbl_eixoZ_esc;
        TEdit *edt_eixoX_esc;
        TEdit *edt_eixoY_esc;
        TEdit *edt_eixoZ_esc;
        TButton *btn_Esc;
    TGroupBox *rdgRotacao;
        TRadioButton *rdb_eixoX_rot;
        TRadioButton *rdb_eixoY_rot;
        TRadioButton *rdb_eixoZ_rot;
        TButton *btn_rot;
    TGroupBox *GroupBox1;
        TLabel *lbl_eixoX_trans;
        TLabel *lbl_eixoY_trans;
        TLabel *lbl_eixoZ_trans;
        TEdit *edt_eixoX_trans;
        TEdit *edt_eixoY_trans;
        TEdit *edt_eixoZ_trans;
        TButton *btn_trans;
        TImage *imgGrafico;
        TGroupBox *GroupBox6;
        TRadioButton *rdb_Cubo;
        TRadioButton *rdb_Esfera;
        TRadioButton *rdb_Cone;
        TRadioButton *rdb_Cilindro;
        TRadioButton *rdb_Plano;
        TRadioButton *rdb_Superficie;
        void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall btn_rotMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall btn_transClick(TObject *Sender);
    void __fastcall btn_EscClick(TObject *Sender);
    void __fastcall Cubo1Click(TObject *Sender);
    void __fastcall Esfera1Click(TObject *Sender);
    void __fastcall Cone1Click(TObject *Sender);
    void __fastcall Cilindro1Click(TObject *Sender);
    void __fastcall Plano1Click(TObject *Sender);
    void __fastcall Superficie1Click(TObject *Sender);
        void __fastcall rdb_CuboClick(TObject *Sender);
        void __fastcall rdb_EsferaClick(TObject *Sender);
        void __fastcall rdb_ConeClick(TObject *Sender);
        void __fastcall rdb_CilindroClick(TObject *Sender);
        void __fastcall rdb_PlanoClick(TObject *Sender);
        void __fastcall rdb_SuperficieClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        
    
        __fastcall TPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrincipal *Principal;
//---------------------------------------------------------------------------
#endif
