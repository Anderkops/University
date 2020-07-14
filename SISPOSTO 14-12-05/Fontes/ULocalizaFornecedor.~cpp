//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaFornecedor.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ULocalizaMestre"
#pragma resource "*.dfm"
TformLocalizaFornecedor *formLocalizaFornecedor;
//---------------------------------------------------------------------------
__fastcall TformLocalizaFornecedor::TformLocalizaFornecedor(TComponent* Owner)
        : TformLocalizaMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformLocalizaFornecedor::edtValorPesquisaKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   TLocateOptions OpcaoPesquisa;
   OpcaoPesquisa.Clear();
   OpcaoPesquisa << loPartialKey;
   dmBaseDados->tblFornecedores->Locate("NOME_FORN",
edtValorPesquisa->Text,OpcaoPesquisa);
}
//---------------------------------------------------------------------------
