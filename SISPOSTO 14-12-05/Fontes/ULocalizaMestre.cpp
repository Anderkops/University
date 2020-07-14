//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULocalizaMestre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformLocalizaMestre *formLocalizaMestre;
//---------------------------------------------------------------------------
__fastcall TformLocalizaMestre::TformLocalizaMestre(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformLocalizaMestre::FormKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   if(Key == VK_RETURN)
      Perform(WM_NEXTDLGCTL,0,0);        
}
//---------------------------------------------------------------------------
