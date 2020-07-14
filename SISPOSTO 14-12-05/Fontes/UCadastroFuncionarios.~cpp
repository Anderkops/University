//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroFuncionarios.h"
#include "UModuloDados.h"
#include "ULocalizaFuncionario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroFuncionarios *formCadastroFuncionarios;
//---------------------------------------------------------------------------
__fastcall TformCadastroFuncionarios::TformCadastroFuncionarios(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblFuncionarios->Open();
   if(dmBaseDados->tblFuncionarios->RecordCount == 0)
   {
      dmBaseDados->tblFuncionarios->Append();
      dmBaseDados->tblFuncionariosCOD_FUNC->AsString = "00001";
   }
   fldNomeFunc->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblFuncionarios->State == dsInsert) ||
(dmBaseDados->tblFuncionarios->State == dsEdit))
   {
      dmBaseDados->tblFuncionarios->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblFuncionarios->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnPrimeiroClick(
      TObject *Sender)
{
   dmBaseDados->tblFuncionarios->First();
   fldNomeFunc->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnAnteriorClick(
      TObject *Sender)
{
   dmBaseDados->tblFuncionarios->Prior();
   if(dmBaseDados->tblFuncionarios->Bof)
      dmBaseDados->tblFuncionarios->First();
   fldNomeFunc->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnProximoClick(TObject *Sender)
{
  dmBaseDados->tblFuncionarios->Next();
  if(dmBaseDados->tblFuncionarios->Eof)
     dmBaseDados->tblFuncionarios->Last();
  fldNomeFunc->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblFuncionarios->Last();
   fldNomeFunc->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblFuncionarios->State == dsInsert) ||
(dmBaseDados->tblFuncionarios->State == dsEdit))
   {
   dmBaseDados->tblFuncionarios->Post();
   dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblFuncionarios->Last();
   intCodigo = StrToInt(dmBaseDados->tblFuncionariosCOD_FUNC->AsString);
   intCodigo++;
   if(intCodigo < 99999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "00000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,5);

      dmBaseDados->tblFuncionarios->Append();
      dmBaseDados->tblFuncionariosCOD_FUNC->AsString = strCodigo;
   }
   fldNomeFunc->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblFuncionarios->Delete();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroFuncionarios::btnLocalizarClick(
      TObject *Sender)
{
   Application->CreateForm(__classid(TformLocalizaFuncionario),&formLocalizaFuncionario);
   formLocalizaFuncionario->ShowModal();
   formLocalizaFuncionario->Free();        
}
//---------------------------------------------------------------------------
