//---------------------------------------------------------------------------

#ifndef URelClienteH
#define URelClienteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelEstoque.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelCliente : public TformRelEstoque
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelCliente *formRelCliente;
//---------------------------------------------------------------------------
#endif
