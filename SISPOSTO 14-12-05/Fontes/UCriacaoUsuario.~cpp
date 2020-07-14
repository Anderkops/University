//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCriacaoUsuario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformCriacaoUsuario *formCriacaoUsuario;
//---------------------------------------------------------------------------
__fastcall TformCriacaoUsuario::TformCriacaoUsuario(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformCriacaoUsuario::BitBtn1Click(TObject *Sender)
{
    IBSecurityService1->Attach();
    IBSecurityService1->UserName = Edit1->Text;
    IBSecurityService1->Password = MaskEdit1->Text;
    IBSecurityService1->Active = True;
    IBSecurityService1->ServiceStart();
    ShowMessage("Usuário criado com sucesso.");
}
//---------------------------------------------------------------------------
