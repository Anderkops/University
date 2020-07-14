//---------------------------------------------------------------------------

#ifndef URelFornecedorH
#define URelFornecedorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelCliente.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelFornecedor : public TformRelCliente
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelFornecedor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelFornecedor *formRelFornecedor;
//---------------------------------------------------------------------------
#endif
