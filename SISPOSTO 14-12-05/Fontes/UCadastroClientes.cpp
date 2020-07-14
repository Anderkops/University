//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroClientes.h"
#include "UModuloDados.h"
#include "ULocalizaCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroClientes *formCadastroClientes;
//---------------------------------------------------------------------------
__fastcall TformCadastroClientes::TformCadastroClientes(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblClientes->Open();
   if(dmBaseDados->tblClientes->RecordCount == 0)
   {
      dmBaseDados->tblClientes->Append();
      dmBaseDados->tblClientesCOD_CLI->AsString = "00001";
   }
   fldNomeCli->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblClientes->State == dsInsert) ||
(dmBaseDados->tblClientes->State == dsEdit))
   {
      dmBaseDados->tblClientes->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblClientes->Close();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnPrimeiroClick(TObject *Sender)
{
      dmBaseDados->tblClientes->First();
      fldNomeCli->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblClientes->Prior();
   if(dmBaseDados->tblClientes->Bof)
      dmBaseDados->tblClientes->First();
   fldNomeCli->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblClientes->Next();
   if(dmBaseDados->tblClientes->Eof)
      dmBaseDados->tblClientes->Last();
   fldNomeCli->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblClientes->Last();
   fldNomeCli->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblClientes->State == dsInsert) ||
(dmBaseDados->tblClientes->State == dsEdit))
   {
      dmBaseDados->tblClientes->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblClientes->Last();
   intCodigo = StrToInt(dmBaseDados->tblClientesCOD_CLI->AsString);
   intCodigo++;
   if(intCodigo < 99999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "00000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,5);

      dmBaseDados->tblClientes->Append();
      dmBaseDados->tblClientesCOD_CLI->AsString = strCodigo;
   }
   fldNomeCli->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblClientes->Delete();        
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroClientes::btnLocalizarClick(TObject *Sender)
{
   Application->CreateForm(__classid(TformLocalizaCliente),&formLocalizaCliente);
   formLocalizaCliente->ShowModal();
   formLocalizaCliente->Free();
}
//---------------------------------------------------------------------------
