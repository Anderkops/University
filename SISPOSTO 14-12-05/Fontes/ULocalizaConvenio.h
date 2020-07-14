//---------------------------------------------------------------------------

#ifndef ULocalizaConvenioH
#define ULocalizaConvenioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ULocalizaMestre.h"
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformLocalizaConvenio : public TformLocalizaMestre
{
__published:	// IDE-managed Components
        void __fastcall edtValorPesquisaKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TformLocalizaConvenio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformLocalizaConvenio *formLocalizaConvenio;
//---------------------------------------------------------------------------
#endif
