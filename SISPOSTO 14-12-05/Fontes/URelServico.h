//---------------------------------------------------------------------------

#ifndef URelServicoH
#define URelServicoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "URelProduto.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelServico : public TformRelProduto
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TformRelServico(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelServico *formRelServico;
//---------------------------------------------------------------------------
#endif
