//---------------------------------------------------------------------------

#ifndef UCadastroBombasH
#define UCadastroBombasH
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
class TformCadastroBombas : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodBom;
        TDBEdit *fldCodBom;
        TLabel *lblCodTan;
        TDBEdit *fldLeituraBom;
        TLabel *lblLeituraBom;
        TDBEdit *fldDataleitBom;
        TLabel *lblDataleitBom;
        TDBEdit *fldHoraleitBom;
        TLabel *lblHoraleitBom;
        TDBLookupComboBox *fldCodTanfk;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnPrimeiroClick(TObject *Sender);
        void __fastcall btnAnteriorClick(TObject *Sender);
        void __fastcall btnProximoClick(TObject *Sender);
        void __fastcall btnUltimoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnNovoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformCadastroBombas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroBombas *formCadastroBombas;
//---------------------------------------------------------------------------
#endif
