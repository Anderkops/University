//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrincipal.h"
#include "UCadastroConvenios.h"
#include "UCadastroClientes.h"
#include "UCadastroFuncionarios.h"
#include "UCadastroFornecedores.h"
#include "UCadastroProdutos.h"
#include "UCadastroTanques.h"
#include "UCadastroBombas.h"
#include "UCadastroBicos.h"
#include "UModuloDados.h"
#include "UCalendario.h"
#include "UBackupRestore.h"
#include "USobre.h"
#include "USplash.h"
#include "UVendas.h"
#include "UCadastroConvCli.h"
#include "UCriacaoUsuario.h"
#include "URelVendaData.h"
#include "URelEstoque.h"
#include "URelVendaFunc.h"
#include "URelVendaProd.h"
#include "URelCliente.h"
#include "URelConvenio.h"
#include "URelFornecedor.h"
#include "URelFuncionario.h"
#include "URelCombustivel.h"
#include "URelProduto.h"
#include "URelServico.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cdiroutl"
#pragma resource "*.dfm"
TformPrincipal *formPrincipal;
//---------------------------------------------------------------------------
__fastcall TformPrincipal::TformPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformPrincipal::Sair1Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TformPrincipal::Fornecedores1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroConvenios),&formCadastroConvenios);
   formCadastroConvenios->ShowModal();
   formCadastroConvenios->Free();        
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Clientes1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroClientes),&formCadastroClientes);
   formCadastroClientes->ShowModal();
   formCadastroClientes->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Funcionrios1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroFuncionarios),&formCadastroFuncionarios);
   formCadastroFuncionarios->ShowModal();
   formCadastroFuncionarios->Free();        
}
//---------------------------------------------------------------------------


void __fastcall TformPrincipal::Fornecedores2Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroFornecedores),&formCadastroFornecedores);
   formCadastroFornecedores->ShowModal();
   formCadastroFornecedores->Free();        
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Calculadora1Click(TObject *Sender)
{
WinExec("Calc", NULL);
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Calendrios1Click(TObject *Sender)
{
//WinExec("control.exe Timedate.cpl , 1", SW_SHOW);
ShowMessage("Hoje é "+ FormatDateTime("dddddd", Now())+ "   Horário: " + FormatDateTime("t AMPM", Now()));
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Produtos1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroProdutos),&formCadastroProdutos);
   formCadastroProdutos->ShowModal();
   formCadastroProdutos->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Tanques1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroTanques),&formCadastroTanques);
   formCadastroTanques->ShowModal();
   formCadastroTanques->Free();        
}
//---------------------------------------------------------------------------



void __fastcall TformPrincipal::Bombas1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroBombas),&formCadastroBombas);
   formCadastroBombas->ShowModal();
   formCadastroBombas->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Bicos1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCadastroBicos),&formCadastroBicos);
   formCadastroBicos->ShowModal();
   formCadastroBicos->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Trocadeusurio1Click(TObject *Sender)
{
dmBaseDados->dbBaseDados->Connected=false;
dmBaseDados->dbBaseDados->Connected=true;
}
//---------------------------------------------------------------------------



void __fastcall TformPrincipal::Calendrio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCalendario),&formCalendario);
   formCalendario->ShowModal();
   formCalendario->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::FazerRestaurarBackup1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformBackupRestore),&formBackupRestore);
   formBackupRestore->ShowModal();
   formBackupRestore->Free();
}
//---------------------------------------------------------------------------


void __fastcall TformPrincipal::Verso1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformSobre),&formSobre);
   formSobre->ShowModal();
   formSobre->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::FormShow(TObject *Sender)
{
if (formSplash)
{
delete formSplash;
formSplash = NULL;
}

}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::FormCreate(TObject *Sender)
{
if (formSplash)
{
Sleep(1); // tempo desejado
}
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Venda1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformVenda),&formVenda);
   formVenda->ShowModal();
   formVenda->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Relacionarconvenio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformConvCli),&formConvCli);
   formConvCli->ShowModal();
   formConvCli->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Criarusurio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformCriacaoUsuario),&formCriacaoUsuario);
   formCriacaoUsuario->ShowModal();
   formCriacaoUsuario->Free();
}
//---------------------------------------------------------------------------


void __fastcall TformPrincipal::Venda2Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelVendaData),&formRelVendaData);
   formRelVendaData->ShowModal();
   formRelVendaData->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Estoque1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelEstoque),&formRelEstoque);
   formRelEstoque->ShowModal();
   formRelEstoque->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Vendaporfuncionrio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelVendaFunc),&formRelVendaFunc);
   formRelVendaFunc->ShowModal();
   formRelVendaFunc->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Vendidoporproduto1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelVendaProd),&formRelVendaProd);
   formRelVendaProd->ShowModal();
   formRelVendaProd->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Clientes2Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelCliente),&formRelCliente);
   formRelCliente->ShowModal();
   formRelCliente->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Convnio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelConvenio),&formRelConvenio);
   formRelConvenio->ShowModal();
   formRelConvenio->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Fornecedor1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelFornecedor),&formRelFornecedor);
   formRelFornecedor->ShowModal();
   formRelFornecedor->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Funcionrio1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelFuncionario),&formRelFuncionario);
   formRelFuncionario->ShowModal();
   formRelFuncionario->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Combustvel1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelCombustivel),&formRelCombustivel);
   formRelCombustivel->ShowModal();
   formRelCombustivel->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Produtos2Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelProduto),&formRelProduto);
   formRelProduto->ShowModal();
   formRelProduto->Free();
}
//---------------------------------------------------------------------------

void __fastcall TformPrincipal::Servios1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TformRelServico),&formRelServico);
   formRelServico->ShowModal();
   formRelServico->Free();
}
//---------------------------------------------------------------------------




