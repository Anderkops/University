//---------------------------------------------------------------------------

#ifndef UCriacaoUsuarioH
#define UCriacaoUsuarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <IBServices.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TformCriacaoUsuario : public TForm
{
__published:	// IDE-managed Components
        TIBSecurityService *IBSecurityService1;
        TLabel *Label1;
        TLabel *Label2;
        TBitBtn *BitBtn1;
        TMaskEdit *MaskEdit1;
        TEdit *Edit1;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformCriacaoUsuario(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCriacaoUsuario *formCriacaoUsuario;
//---------------------------------------------------------------------------
#endif
