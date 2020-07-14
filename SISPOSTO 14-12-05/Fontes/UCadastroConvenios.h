//---------------------------------------------------------------------------

#ifndef UCadastroConveniosH
#define UCadastroConveniosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UCadastroMestre.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TformCadastroConvenios : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodConv;
        TDBEdit *fldCodConv;
        TLabel *lblNomeConv;
        TDBEdit *fldNomeConv;
        TLabel *lblDescvistaConv;
        TDBEdit *fldDescvistaConv;
        TLabel *lblDescprazoConv;
        TDBEdit *fldDescprazoConv;
        TLabel *lblComissaoConv;
        TDBEdit *fldComissaoConv;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnPrimeiroClick(TObject *Sender);
        void __fastcall btnAnteriorClick(TObject *Sender);
        void __fastcall btnProximoClick(TObject *Sender);
        void __fastcall btnUltimoClick(TObject *Sender);
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnLocalizarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformCadastroConvenios(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroConvenios *formCadastroConvenios;
//---------------------------------------------------------------------------
#endif
