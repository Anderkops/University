//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URelServico.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "URelProduto"
#pragma resource "*.dfm"
TformRelServico *formRelServico;
//---------------------------------------------------------------------------
__fastcall TformRelServico::TformRelServico(TComponent* Owner)
        : TformRelProduto(Owner)
{
}
//---------------------------------------------------------------------------
