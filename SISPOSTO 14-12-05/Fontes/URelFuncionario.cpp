//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URelFuncionario.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "URelCliente"
#pragma resource "*.dfm"
TformRelFuncionario *formRelFuncionario;
//---------------------------------------------------------------------------
__fastcall TformRelFuncionario::TformRelFuncionario(TComponent* Owner)
        : TformRelCliente(Owner)
{
}
//---------------------------------------------------------------------------
