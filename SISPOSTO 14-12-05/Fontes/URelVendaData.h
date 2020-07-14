//---------------------------------------------------------------------------

#ifndef URelVendaDataH
#define URelVendaDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformRelVendaData : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TLabel *Label1;
private:	// User declarations
public:		// User declarations
        __fastcall TformRelVendaData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformRelVendaData *formRelVendaData;
//---------------------------------------------------------------------------
#endif
