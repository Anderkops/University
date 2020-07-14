//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCadastroMestre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformCadastroMestre *formCadastroMestre;
//---------------------------------------------------------------------------
__fastcall TformCadastroMestre::TformCadastroMestre(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCadastroMestre::btnSairClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------


void __fastcall TformCadastroMestre::FormKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if(Key == VK_RETURN)
      Perform(WM_NEXTDLGCTL,0,0);        
}
//---------------------------------------------------------------------------

