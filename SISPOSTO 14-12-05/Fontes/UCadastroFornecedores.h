//---------------------------------------------------------------------------

#ifndef UCadastroFornecedoresH
#define UCadastroFornecedoresH
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
class TformCadastroFornecedores : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodForn;
        TDBEdit *fldCodForn;
        TDBEdit *fldNomeForn;
        TLabel *lblNomeForn;
        TDBEdit *fldNomecontForn;
        TLabel *lblNomecontForn;
        TDBEdit *fldLogradForn;
        TLabel *lblLogradForn;
        TDBEdit *fldNumForn;
        TLabel *lblNumForn;
        TLabel *lblComplForn;
        TDBEdit *fldComplForn;
        TLabel *lblBairroForn;
        TDBEdit *fldBairroForn;
        TLabel *lblCidForn;
        TDBEdit *fldCidForn;
        TLabel *lblEstadoForn;
        TDBComboBox *fldEstadoForn;
        TDBEdit *fldCepForn;
        TLabel *lblCepForn;
        TDBEdit *fldTelcomForn;
        TLabel *lblTelcomForn;
        TDBEdit *fldFaxForn;
        TLabel *lblFaxForn;
        TDBEdit *fldIeForn;
        TLabel *lblIeForn;
        TDBEdit *fldCgcForn;
        TLabel *lbCgcForn;
        TLabel *lblRefForn;
        TDBMemo *fldRefForn;
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
        __fastcall TformCadastroFornecedores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroFornecedores *formCadastroFornecedores;
//---------------------------------------------------------------------------
#endif
