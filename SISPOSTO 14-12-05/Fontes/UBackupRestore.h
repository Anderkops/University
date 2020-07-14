//---------------------------------------------------------------------------

#ifndef UBackupRestoreH
#define UBackupRestoreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <IBServices.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TformBackupRestore : public TForm
{
__published:	// IDE-managed Components
        TImageList *ImageList1;
        TOpenDialog *OpenDialog1;
        TIBBackupService *IBBackupService1;
        TIBRestoreService *IBRestoreService1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label3;
        TEdit *Edit3;
        TBitBtn *BitBtn3;
        TLabel *Label4;
        TEdit *Edit4;
        TBitBtn *BitBtn4;
        TOpenDialog *OpenDialog2;
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformBackupRestore(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformBackupRestore *formBackupRestore;
//---------------------------------------------------------------------------
#endif
