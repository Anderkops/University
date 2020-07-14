//---------------------------------------------------------------------------

#ifndef URelEstoqueH
#define URelEstoqueH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelVendaData.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelEstoque : public TformRelVendaData
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelEstoque(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelEstoque *formRelEstoque;
//---------------------------------------------------------------------------
#endif
