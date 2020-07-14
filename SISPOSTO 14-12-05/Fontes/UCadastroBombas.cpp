//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroBombas.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroBombas *formCadastroBombas;
//---------------------------------------------------------------------------
__fastcall TformCadastroBombas::TformCadastroBombas(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblBombas->Open();
   if(dmBaseDados->tblBombas->RecordCount == 0)
   {
   dmBaseDados->tblBombas->Append();
   dmBaseDados->tblBombasCOD_BOM->AsString = "001";
   }
   fldCodTanfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblBombas->State == dsInsert) ||
(dmBaseDados->tblBombas->State == dsEdit))
   {
      dmBaseDados->tblBombas->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblBombas->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnPrimeiroClick(TObject *Sender)
{
   dmBaseDados->tblBombas->First();
   fldCodTanfk->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblBombas->Prior();
   if(dmBaseDados->tblBombas->Bof)
      dmBaseDados->tblBombas->First();
   fldCodTanfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblBombas->Next();
   if(dmBaseDados->tblBombas->Eof)
      dmBaseDados->tblBombas->Last();
   fldCodTanfk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblBombas->Last();
   fldCodTanfk->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblBombas->Delete();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroBombas::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblBombas->State == dsInsert) ||
(dmBaseDados->tblBombas->State == dsEdit))
   {
      dmBaseDados->tblBombas->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblBombas->Last();
   intCodigo = StrToInt(dmBaseDados->tblBombasCOD_BOM->AsString);
   intCodigo++;
   if(intCodigo < 999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,3);

      dmBaseDados->tblBombas->Append();
      dmBaseDados->tblBombasCOD_BOM->AsString = strCodigo;
   }
}
//---------------------------------------------------------------------------


