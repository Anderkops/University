//---------------------------------------------------------------------------

#ifndef UCadastroTanquesH
#define UCadastroTanquesH
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
class TformCadastroTanques : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodTan;
        TDBEdit *fldCodTan;
        TLabel *lblCodProd;
        TDBLookupComboBox *fldCodProd;
        TLabel *lblAberturaTan;
        TDBEdit *fldAberturaTan;
        TLabel *lblFechamento;
        TDBEdit *fldFechamentoTan;
        TLabel *lblDataregTan;
        TDBEdit *fldDataregTan;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnPrimeiroClick(TObject *Sender);
        void __fastcall btnAnteriorClick(TObject *Sender);
        void __fastcall btnProximoClick(TObject *Sender);
        void __fastcall btnUltimoClick(TObject *Sender);
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformCadastroTanques(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroTanques *formCadastroTanques;
//---------------------------------------------------------------------------
#endif
