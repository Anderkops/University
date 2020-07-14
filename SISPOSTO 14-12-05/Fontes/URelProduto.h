//---------------------------------------------------------------------------

#ifndef URelProdutoH
#define URelProdutoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelCombustivel.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelProduto : public TformRelCombustivel
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelProduto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelProduto *formRelProduto;
//---------------------------------------------------------------------------
#endif
