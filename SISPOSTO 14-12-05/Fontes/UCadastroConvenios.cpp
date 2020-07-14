//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroConvenios.h"
#include "UModuloDados.h"
#include "ULocalizaConvenio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroConvenios *formCadastroConvenios;
//---------------------------------------------------------------------------
__fastcall TformCadastroConvenios::TformCadastroConvenios(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroConvenios::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblConvenios->Open();
   if(dmBaseDados->tblConvenios->RecordCount == 0)
   {
      dmBaseDados->tblConvenios->Append();
      dmBaseDados->tblConveniosCOD_CONV->AsString = "00001";
   }
   fldNomeConv->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroConvenios::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblConvenios->State == dsInsert) ||
(dmBaseDados->tblConvenios->State == dsEdit))
   {
      dmBaseDados->tblConvenios->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblConvenios->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroConvenios::btnPrimeiroClick(TObject *Sender)
{
   dmBaseDados->tblConvenios->First();
   fldNomeConv->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroConvenios::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblConvenios->Prior();
   if(dmBaseDados->tblConvenios->Bof)
      dmBaseDados->tblConvenios->First();
      fldNomeConv->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroConvenios::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblConvenios->Next();
   if(dmBaseDados->tblConvenios->Eof)
      dmBaseDados->tblConvenios->Last();
   fldNomeConv->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroConvenios::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblConvenios->Last();
   fldNomeConv->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroConvenios::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblConvenios->State == dsInsert) ||
(dmBaseDados->tblConvenios->State == dsEdit))
   {
      dmBaseDados->tblConvenios->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblConvenios->Last();
   intCodigo = StrToInt(dmBaseDados->tblConveniosCOD_CONV->AsString);
   intCodigo++;
   if(intCodigo < 99999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "00000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,5);

      dmBaseDados->tblConvenios->Append();
      dmBaseDados->tblConveniosCOD_CONV->AsString = strCodigo;
   }
   fldNomeConv->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroConvenios::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblConvenios->Delete();         
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroConvenios::btnLocalizarClick(TObject *Sender)
{
   Application->CreateForm(__classid(TformLocalizaConvenio),&formLocalizaConvenio);
   formLocalizaConvenio->ShowModal();
   formLocalizaConvenio->Free();
}
//---------------------------------------------------------------------------
