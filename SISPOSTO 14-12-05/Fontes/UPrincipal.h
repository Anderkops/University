//---------------------------------------------------------------------------

#ifndef UPrincipalH
#define UPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "cdiroutl.h"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Grids.hpp>
#include <Outline.hpp>
#include <FileCtrl.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TformPrincipal : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Arquivos1;
        TMenuItem *Cadastro1;
        TMenuItem *N1;
        TMenuItem *Sair1;
        TMenuItem *Clientes1;
        TMenuItem *Fornecedores1;
        TMenuItem *Fornecedores2;
        TMenuItem *Funcionrios1;
        TMenuItem *Produtos1;
        TMenuItem *N2;
        TMenuItem *Bicos1;
        TMenuItem *Bombas1;
        TMenuItem *Tanques1;
        TMenuItem *Movimentao1;
        TMenuItem *Venda1;
        TMenuItem *Utilitrios1;
        TMenuItem *Calculadora1;
        TMenuItem *Calendrios1;
        TMenuItem *Sobre1;
        TMenuItem *Verso1;
        TMenuItem *RElatrios1;
        TMenuItem *Venda2;
        TMenuItem *Usurio1;
        TMenuItem *Trocadeusurio1;
        TMenuItem *Criarusurio1;
        TMenuItem *Calendrio1;
        TMenuItem *FazerRestaurarBackup1;
        TMenuItem *Relacionarconvenio1;
        TMenuItem *Estoque1;
        TMenuItem *Vendaporfuncionrio1;
        TMenuItem *Vendidoporproduto1;
        TMenuItem *Relatriodoscadastros1;
        TMenuItem *Clientes2;
        TMenuItem *Convnio1;
        TMenuItem *Fornecedor1;
        TMenuItem *Funcionrio1;
        TMenuItem *N3;
        TMenuItem *Produtos2;
        TMenuItem *Servios1;
        TMenuItem *Combustvel1;
        void __fastcall Sair1Click(TObject *Sender);
        void __fastcall Fornecedores1Click(TObject *Sender);
        void __fastcall Clientes1Click(TObject *Sender);
        void __fastcall Funcionrios1Click(TObject *Sender);
        void __fastcall Fornecedores2Click(TObject *Sender);
        void __fastcall Calculadora1Click(TObject *Sender);
        void __fastcall Calendrios1Click(TObject *Sender);
        void __fastcall Produtos1Click(TObject *Sender);
        void __fastcall Tanques1Click(TObject *Sender);
        void __fastcall Bombas1Click(TObject *Sender);
        void __fastcall Bicos1Click(TObject *Sender);
        void __fastcall Trocadeusurio1Click(TObject *Sender);
        void __fastcall Calendrio1Click(TObject *Sender);
        void __fastcall FazerRestaurarBackup1Click(TObject *Sender);
        void __fastcall Verso1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Venda1Click(TObject *Sender);
        void __fastcall Relacionarconvenio1Click(TObject *Sender);
        void __fastcall Criarusurio1Click(TObject *Sender);
        void __fastcall Venda2Click(TObject *Sender);
        void __fastcall Estoque1Click(TObject *Sender);
        void __fastcall Vendaporfuncionrio1Click(TObject *Sender);
        void __fastcall Vendidoporproduto1Click(TObject *Sender);
        void __fastcall Clientes2Click(TObject *Sender);
        void __fastcall Convnio1Click(TObject *Sender);
        void __fastcall Fornecedor1Click(TObject *Sender);
        void __fastcall Funcionrio1Click(TObject *Sender);
        void __fastcall Combustvel1Click(TObject *Sender);
        void __fastcall Produtos2Click(TObject *Sender);
        void __fastcall Servios1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformPrincipal(TComponent* Owner);
        AnsiString CurrentFile;
};
//---------------------------------------------------------------------------
extern PACKAGE TformPrincipal *formPrincipal;
//---------------------------------------------------------------------------
#endif
