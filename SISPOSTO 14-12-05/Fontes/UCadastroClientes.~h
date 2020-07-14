//---------------------------------------------------------------------------

#ifndef UCadastroClientesH
#define UCadastroClientesH
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
class TformCadastroClientes : public TformCadastroMestre
{
__published:	// IDE-managed Components
        TLabel *lblCodFuncfk;
        TDBEdit *fldCodCli;
        TLabel *lblNomeCli;
        TDBEdit *fldNomeCli;
        TLabel *lblLogradCli;
        TDBEdit *fldLogradCli;
        TLabel *lblNumCli;
        TDBEdit *fldNumCli;
        TLabel *lblComplCli;
        TDBEdit *fldComplCli;
        TLabel *lblBairroCli;
        TDBEdit *fldBairroCli;
        TLabel *lblCidCli;
        TDBEdit *fldCidCli;
        TLabel *lblEstadoCli;
        TDBComboBox *fldEstadoCli;
        TDBEdit *fldCepCli;
        TLabel *lblCepCli;
        TLabel *lblTelcomCli;
        TDBEdit *fldTelcomCli;
        TLabel *lblTelresCli;
        TDBEdit *fldTelresCli;
        TLabel *lblRefCli;
        TDBMemo *fldRefCli;
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
        __fastcall TformCadastroClientes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCadastroClientes *formCadastroClientes;
//---------------------------------------------------------------------------
#endif
