//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaConvenio.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ULocalizaMestre"
#pragma resource "*.dfm"
TformLocalizaConvenio *formLocalizaConvenio;
//---------------------------------------------------------------------------
__fastcall TformLocalizaConvenio::TformLocalizaConvenio(TComponent* Owner)
        : TformLocalizaMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformLocalizaConvenio::edtValorPesquisaKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   TLocateOptions OpcaoPesquisa;
   OpcaoPesquisa.Clear();
   OpcaoPesquisa << loPartialKey;
   dmBaseDados->tblConvenios->Locate("NOME_CONV",
edtValorPesquisa->Text,OpcaoPesquisa);
}
//---------------------------------------------------------------------------

