//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaCliente.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ULocalizaMestre"
#pragma resource "*.dfm"
TformLocalizaCliente *formLocalizaCliente;
//---------------------------------------------------------------------------
__fastcall TformLocalizaCliente::TformLocalizaCliente(TComponent* Owner)
        : TformLocalizaMestre(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TformLocalizaCliente::edtValorPesquisaKeyUp(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   TLocateOptions OpcaoPesquisa;
   OpcaoPesquisa.Clear();
   OpcaoPesquisa << loPartialKey;
   dmBaseDados->tblClientes->Locate("NOME_CLI",
edtValorPesquisa->Text,OpcaoPesquisa);        
}
//---------------------------------------------------------------------------

