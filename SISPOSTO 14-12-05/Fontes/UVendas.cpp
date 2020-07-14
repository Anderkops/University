//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UVendas.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformVenda *formVenda;
//---------------------------------------------------------------------------
__fastcall TformVenda::TformVenda(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TformVenda::BitBtn4Click(TObject *Sender)
{
    Close();        
}
//---------------------------------------------------------------------------

