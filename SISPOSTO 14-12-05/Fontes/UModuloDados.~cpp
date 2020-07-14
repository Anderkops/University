//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmBaseDados *dmBaseDados;
//---------------------------------------------------------------------------
__fastcall TdmBaseDados::TdmBaseDados(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdmBaseDados::tblConveniosBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO", MB_YESNO + MB_DEFBUTTON2 + MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------
void __fastcall TdmBaseDados::tblClientesBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
      Abort();        
}
//---------------------------------------------------------------------------

void __fastcall TdmBaseDados::tblFuncionariosBeforeDelete(
      TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------

void __fastcall TdmBaseDados::tblFornecedoresBeforeDelete(
      TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------

void __fastcall TdmBaseDados::tblProdutosBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------


void __fastcall TdmBaseDados::tblTanquesBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------

void __fastcall TdmBaseDados::tblBombasBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) != IDYES)
   Abort();
}
//---------------------------------------------------------------------------

void __fastcall TdmBaseDados::tblBicosBeforeDelete(TDataSet *DataSet)
{
   if(Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) !=IDYES)
   Abort();
}
//---------------------------------------------------------------------------


void __fastcall TdmBaseDados::tblConvCliBeforeDelete(TDataSet *DataSet)
{
    if (Application->MessageBox("Deseja excluir esse registro?",
"EXCLUSÃO",MB_YESNO+MB_DEFBUTTON2+MB_ICONQUESTION) !=IDYES)
    Abort();
}
//---------------------------------------------------------------------------


