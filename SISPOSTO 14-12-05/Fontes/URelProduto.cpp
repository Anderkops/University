//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URelProduto.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "URelCombustivel"
#pragma resource "*.dfm"
TformRelProduto *formRelProduto;
//---------------------------------------------------------------------------
__fastcall TformRelProduto::TformRelProduto(TComponent* Owner)
        : TformRelCombustivel(Owner)
{
}
//---------------------------------------------------------------------------
