//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroBicos.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroBicos *formCadastroBicos;
//---------------------------------------------------------------------------
__fastcall TformCadastroBicos::TformCadastroBicos(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblBicos->Open();
   if(dmBaseDados->tblBicos->RecordCount == 0)
   {
      dmBaseDados->tblBicos->Append();
      dmBaseDados->tblBicosCOD_BIC->AsString = "001";
   }
   fldCodBomfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblBicos->State == dsInsert) ||
(dmBaseDados->tblBicos->State == dsEdit))
   {
      dmBaseDados->tblBicos->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblBicos->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnPrimeiroClick(TObject *Sender)
{
   dmBaseDados->tblBicos->First();
   fldCodBomfk->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblBicos->Prior();
   if(dmBaseDados->tblBicos->Bof)
      dmBaseDados->tblBicos->First();
   fldCodBomfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblBicos->Next();
   if(dmBaseDados->tblBicos->Eof)
      dmBaseDados->tblBicos->Last();
   fldCodBomfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblBicos->Last();
   fldCodBomfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblBicos->Delete();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBicos::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblBicos->State == dsInsert) ||
(dmBaseDados->tblBicos->State == dsEdit))
   {
      dmBaseDados->tblBicos->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblBicos->Last();
   intCodigo = StrToInt(dmBaseDados->tblBicosCOD_BIC->AsString);
   intCodigo++;
   if(intCodigo < 999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,3);

      dmBaseDados->tblBicos->Append();
      dmBaseDados->tblBicosCOD_BIC->AsString = strCodigo;
   }
   fldCodBomfk->SetFocus();
}
//---------------------------------------------------------------------------

