//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaFuncionario.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ULocalizaMestre"
#pragma resource "*.dfm"
TformLocalizaFuncionario *formLocalizaFuncionario;
//---------------------------------------------------------------------------
__fastcall TformLocalizaFuncionario::TformLocalizaFuncionario(TComponent* Owner)
        : TformLocalizaMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformLocalizaFuncionario::edtValorPesquisaKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   TLocateOptions OpcaoPesquisa;
   OpcaoPesquisa.Clear();
   OpcaoPesquisa << loPartialKey;
   dmBaseDados->tblFuncionarios->Locate("NOME_FUNC",
edtValorPesquisa->Text,OpcaoPesquisa);
}
//---------------------------------------------------------------------------

