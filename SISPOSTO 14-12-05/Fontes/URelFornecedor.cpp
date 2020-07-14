//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URelFornecedor.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "URelCliente"
#pragma resource "*.dfm"
TformRelFornecedor *formRelFornecedor;
//---------------------------------------------------------------------------
__fastcall TformRelFornecedor::TformRelFornecedor(TComponent* Owner)
        : TformRelCliente(Owner)
{
}
//---------------------------------------------------------------------------
