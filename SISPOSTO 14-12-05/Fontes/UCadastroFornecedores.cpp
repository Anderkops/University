//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroFornecedores.h"
#include "UModuloDados.h"
#include "ULocalizaFornecedor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroFornecedores *formCadastroFornecedores;
//---------------------------------------------------------------------------
__fastcall TformCadastroFornecedores::TformCadastroFornecedores(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblFornecedores->Open();
   if(dmBaseDados->tblFornecedores->RecordCount == 0)
   {
      dmBaseDados->tblFornecedores->Append();
      dmBaseDados->tblFornecedoresCOD_FORN->AsString = "00001";
   }
   fldNomeForn->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblFornecedores->State == dsInsert) ||
(dmBaseDados->tblFornecedores->State == dsEdit))
   {
      dmBaseDados->tblFornecedores->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblFornecedores->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnPrimeiroClick(
      TObject *Sender)
{
   dmBaseDados->tblFornecedores->First();
   fldNomeForn->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnAnteriorClick(
      TObject *Sender)
{
   dmBaseDados->tblFornecedores->Prior();
   if(dmBaseDados->tblFornecedores->Bof)
      dmBaseDados->tblFornecedores->First();
   fldNomeForn->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblFornecedores->Next();
   if(dmBaseDados->tblFornecedores->Eof)
      dmBaseDados->tblFornecedores->Last();
   fldNomeForn->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblFornecedores->Last();
   fldNomeForn->SetFocus();
           
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblFornecedores->State == dsInsert) ||
(dmBaseDados->tblFornecedores->State == dsEdit))
   {
      dmBaseDados->tblFornecedores->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblFornecedores->Last();
   intCodigo = StrToInt(dmBaseDados->tblFornecedoresCOD_FORN->AsString);
   intCodigo++;
   if(intCodigo < 99999)
   {
   strCodigo = IntToStr(intCodigo);
   intTamanho = StrLen(strCodigo.c_str());
   strValor = "00000"+Trim(strCodigo);
   strCodigo = MidStr(strValor,intTamanho+1,5);

   dmBaseDados->tblFornecedores->Append();
   dmBaseDados->tblFornecedoresCOD_FORN->AsString = strCodigo;
   }
   fldNomeForn->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblFornecedores->Delete();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFornecedores::btnLocalizarClick(
      TObject *Sender)
{
   Application->CreateForm(__classid(TformLocalizaFornecedor),&formLocalizaFornecedor);
   formLocalizaFornecedor->ShowModal();
   formLocalizaFornecedor->Free();
}
//---------------------------------------------------------------------------
