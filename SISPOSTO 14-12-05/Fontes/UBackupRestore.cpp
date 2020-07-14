//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UBackupRestore.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformBackupRestore *formBackupRestore;
//---------------------------------------------------------------------------
__fastcall TformBackupRestore::TformBackupRestore(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TformBackupRestore::BitBtn1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
    Edit1->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TformBackupRestore::BitBtn2Click(TObject *Sender)
{
    IBBackupService1->Attach();
    IBBackupService1->DatabaseName=Edit1->Text;
    IBBackupService1->BackupFile->Add(Edit2->Text);
    IBBackupService1->Active = True;
    IBBackupService1->ServiceStart();
    ShowMessage("Backup realizado com sucesso.");
}
//---------------------------------------------------------------------------
void __fastcall TformBackupRestore::BitBtn3Click(TObject *Sender)
{
if (OpenDialog2->Execute())
    Edit3->Text = OpenDialog2->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TformBackupRestore::BitBtn4Click(TObject *Sender)
{
  IBRestoreService1->Attach();
  //IBRestoreService1->Options->Replace = True;
  IBRestoreService1->DatabaseName->Add(Edit4->Text);
  IBRestoreService1->BackupFile->Add(Edit3->Text);
  IBRestoreService1->Active = True;
  IBRestoreService1->ServiceStart();
  ShowMessage("Restore realizado com sucesso");
}
//---------------------------------------------------------------------------
