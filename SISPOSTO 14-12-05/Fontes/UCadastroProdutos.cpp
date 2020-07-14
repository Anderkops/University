//---------------------------------------------------------------------------

#include <vcl.h>
#include <strutils.hpp>
#pragma hdrstop

#include "UCadastroProdutos.h"
#include "UModuloDados.h"
#include "ULocalizaProduto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformCadastroProdutos *formCadastroProdutos;
//---------------------------------------------------------------------------
__fastcall TformCadastroProdutos::TformCadastroProdutos(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TformCadastroProdutos::FormShow(TObject *Sender)
{
   if(!dmBaseDados->IBTransaction1->InTransaction)
      dmBaseDados->IBTransaction1->StartTransaction();
   dmBaseDados->tblProdutos->Open();
   if(dmBaseDados->tblProdutos->RecordCount == 0)
   {
      dmBaseDados->tblProdutos->Append();
      dmBaseDados->tblProdutosCOD_PROD->AsString = "00001";
   }
   fldNomeProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if((dmBaseDados->tblProdutos->State == dsInsert) ||
(dmBaseDados->tblProdutos->State == dsEdit))
   {
      dmBaseDados->tblProdutos->Post();
      dmBaseDados->IBTransaction1->Commit();
   }
   dmBaseDados->tblProdutos->Close();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnPrimeiroClick(TObject *Sender)
{
   dmBaseDados->tblProdutos->First();
   fldNomeProd->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnAnteriorClick(TObject *Sender)
{
   dmBaseDados->tblProdutos->Prior();
   if(dmBaseDados->tblProdutos->Bof)
      dmBaseDados->tblProdutos->First();
   fldNomeProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnProximoClick(TObject *Sender)
{
   dmBaseDados->tblProdutos->Next();
   if(dmBaseDados->tblProdutos->Eof)
      dmBaseDados->tblProdutos->Last();
   fldNomeProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnUltimoClick(TObject *Sender)
{
   dmBaseDados->tblProdutos->Last();
   fldNomeProd->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnNovoClick(TObject *Sender)
{
   String strValor, strCodigo;
   int intTamanho, intCodigo;

   if((dmBaseDados->tblProdutos->State == dsInsert) ||
dmBaseDados->tblProdutos->State == dsEdit)
   {
      dmBaseDados->tblProdutos->Post();
      dmBaseDados->IBTransaction1->CommitRetaining();
   }
   dmBaseDados->tblProdutos->Last();
   intCodigo = StrToInt(dmBaseDados->tblProdutosCOD_PROD->AsString);
   intCodigo++;
   if(intCodigo < 99999)
   {
      strCodigo = IntToStr(intCodigo);
      intTamanho = StrLen(strCodigo.c_str());
      strValor = "00000"+Trim(strCodigo);
      strCodigo = MidStr(strValor,intTamanho+1,5);

      dmBaseDados->tblProdutos->Append();
      dmBaseDados->tblProdutosCOD_PROD->AsString = strCodigo;
   }
   fldNomeProd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnExcluirClick(TObject *Sender)
{
   dmBaseDados->tblProdutos->Delete();        
}
//---------------------------------------------------------------------------

void __fastcall TformCadastroProdutos::btnLocalizarClick(TObject *Sender)
{
   Application->CreateForm(__classid(TformLocalizaProduto),&formLocalizaProduto);
   formLocalizaProduto->ShowModal();
   formLocalizaProduto->Free();
}
//---------------------------------------------------------------------------

