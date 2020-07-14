//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Exit1;
    TMenuItem *About1;
    TMenuItem *Program1;
    TRadioGroup *RadioGroup1;
    TRadioButton *rbCompactar;
    TRadioButton *rbDescompactar;
    TImage *Image1;
    TOpenDialog *odCompactar;
    TOpenDialog *odDescompactar;
    TLabel *Label1;
    TEdit *edtEntrada;
    TLabel *Label2;
    TEdit *edtSaida;
    TButton *Button1;
    TSaveDialog *sdCompactar;
    TSaveDialog *sdDescompactar;
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Program1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
