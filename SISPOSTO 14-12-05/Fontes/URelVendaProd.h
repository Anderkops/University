//---------------------------------------------------------------------------

#ifndef URelVendaProdH
#define URelVendaProdH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelEstoque.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelVendaProd : public TformRelEstoque
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelVendaProd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelVendaProd *formRelVendaProd;
//---------------------------------------------------------------------------
#endif
