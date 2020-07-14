//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaProduto.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ULocalizaMestre"
#pragma resource "*.dfm"
TformLocalizaProduto *formLocalizaProduto;
//---------------------------------------------------------------------------
__fastcall TformLocalizaProduto::TformLocalizaProduto(TComponent* Owner)
        : TformLocalizaMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformLocalizaProduto::edtValorPesquisaKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   TLocateOptions OpcaoPesquisa;
   OpcaoPesquisa.Clear();
   OpcaoPesquisa << loPartialKey;
   dmBaseDados->tblProdutos->Locate("NOME_PROD",
edtValorPesquisa->Text,OpcaoPesquisa);
}
//---------------------------------------------------------------------------
