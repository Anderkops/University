//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroTanques.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroTanques *formCadastroTanques;
//---------------------------------------------------------------------------
__fastcall TformCadastroTanques::TformCadastroTanques(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroTanques::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblTanques->Open();
   if(dmBaseDados->tblTanques->RecordCount == 0)
      {
         dmBaseDados->tblTanques->Append();
         dmBaseDados->tblTanquesCOD_TAN->AsString = "001";
      }
      fldCodProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblTanques->State == dsInsert) ||
(dmBaseDados->tblTanques->State == dsEdit))
   {
      dmBaseDados->tblTanques->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblTanques->Close();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnPrimeiroClick(TObject *Sender)
{
   dmBaseDados->tblTanques->First();
   fldCodProd->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblTanques->Prior();
   if(dmBaseDados->tblTanques->Bof)
      dmBaseDados->tblTanques->First();
   fldCodProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblTanques->Next();
   if(dmBaseDados->tblTanques->Eof)
      dmBaseDados->tblTanques->Last();
   fldCodProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblTanques->Last();
   fldCodProd->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblTanques->State == dsInsert) ||
(dmBaseDados->tblTanques->State == dsEdit))
   {
      dmBaseDados->tblTanques->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblTanques->Last();
   intCodigo = StrToInt(dmBaseDados->tblTanquesCOD_TAN->AsString);
   intCodigo++;
   if(intCodigo < 999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,3);

      dmBaseDados->tblTanques->Append();
      dmBaseDados->tblTanquesCOD_TAN->AsString = strCodigo;
   }
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroTanques::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblTanques->Delete();        
}
//---------------------------------------------------------------------------

