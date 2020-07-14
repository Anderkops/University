//---------------------------------------------------------------------------

#ifndef UCadastroMestreH
#define UCadastroMestreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformCadastroMestre : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlBotoes;
        TSpeedButton *btnPrimeiro;
        TSpeedButton *btnAnterior;
        TSpeedButton *btnProximo;
        TSpeedButton *btnUltimo;
        TSpeedButton *btnNovo;
        TSpeedButton *btnLocalizar;
        TSpeedButton *btnExcluir;
        TSpeedButton *btnSair;
        void __fastcall btnSairClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TformCadastroMestre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroMestre *formCadastroMestre;
//---------------------------------------------------------------------------
#endif
