//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URelCliente.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "URelEstoque"
#pragma resource "*.dfm"
TformRelCliente *formRelCliente;
//---------------------------------------------------------------------------
__fastcall TformRelCliente::TformRelCliente(TComponent* Owner)
        : TformRelEstoque(Owner)
{
}
//---------------------------------------------------------------------------
