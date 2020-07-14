//---------------------------------------------------------------------------

#ifndef UCadastroConvCliH
#define UCadastroConvCliH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UCadastroMestre.h"
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TformConvCli : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TDBLookupComboBox *fldCodConvfk;
        TLabel *lblCodClifk;
        TLabel *lblCodConvfk;
        TDBLookupComboBox *fldCodClifk;
        TLabel *lblCodConvCli;
        TDBEdit *fldCodConvCli;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnPrimeiroClick(TObject *Sender);
        void __fastcall btnAnteriorClick(TObject *Sender);
        void __fastcall btnProximoClick(TObject *Sender);
        void __fastcall btnUltimoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformConvCli(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformConvCli *formConvCli;
//---------------------------------------------------------------------------
#endif
