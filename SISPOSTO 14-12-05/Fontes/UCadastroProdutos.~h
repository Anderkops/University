//---------------------------------------------------------------------------

#ifndef UCadastroProdutosH
#define UCadastroProdutosH
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
class TformCadastroProdutos : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodProd;
        TDBEdit *fldCodProd;
        TDBEdit *fldNomeProd;
        TLabel *lblNomeProd;
        TDBEdit *fldMarcaProd;
        TLabel *lblMarcaProd;
        TLabel *lblFornProd;
        TDBEdit *fldMedidaProd;
        TLabel *lblMedidaProd;
        TLabel *lblUnidmedProd;
        TLabel *lblTipoProd;
        TDBEdit *fldPrecoProd;
        TLabel *lblPrecoProd;
        TDBEdit *fldEstoqueProd;
        TLabel *lblEstoqueProd;
        TDBEdit *fldDatacadProd;
        TLabel *lblDatacadProd;
        TDBComboBox *fldTipoProd;
        TDBComboBox *fldUnidmedProd;
        TDBLookupComboBox *fldCodForn;
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
        __fastcall TformCadastroProdutos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroProdutos *formCadastroProdutos;
//---------------------------------------------------------------------------
#endif
