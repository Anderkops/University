//---------------------------------------------------------------------------

#ifndef URelCombustivelH
#define URelCombustivelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelCliente.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelCombustivel : public TformRelCliente
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelCombustivel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelCombustivel *formRelCombustivel;
//---------------------------------------------------------------------------
#endif
