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
        TImage *imgGrafico;
    TButton *Button1;
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
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        
    
        __fastcall TPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrincipal *Principal;
//---------------------------------------------------------------------------
#endif
