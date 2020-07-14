//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <strutils.hpp>

#include "UCadastroConvCli.h"
#include "UModuloDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCadastroMestre"
#pragma resource "*.dfm"
TformConvCli *formConvCli;
//---------------------------------------------------------------------------
__fastcall TformConvCli::TformConvCli(TComponent* Owner)
        : TformCadastroMestre(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if((dmBaseDados->tblConvCli->State == dsInsert) ||
(dmBaseDados->tblConvCli->State == dsEdit))
    {
    dmBaseDados->tblConvCli->Post();
    dmBaseDados->IBTransaction1->Commit();
    }
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnPrimeiroClick(TObject *Sender)
{
    dmBaseDados->tblConvCli->First();
    fldCodClifk->SetFocus();        
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnAnteriorClick(TObject *Sender)
{
    dmBaseDados->tblConvCli->Prior();
    if(dmBaseDados->tblConvCli->Bof)
        dmBaseDados->tblConvCli->First();
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnProximoClick(TObject *Sender)
{
    dmBaseDados->tblConvCli->Next();
    if(dmBaseDados->tblConvCli->Eof)
        dmBaseDados->tblConvCli->Last();
    fldCodClifk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnUltimoClick(TObject *Sender)
{
    dmBaseDados->tblConvCli->Last();
    fldCodClifk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnExcluirClick(TObject *Sender)
{
    dmBaseDados->tblConvCli->Delete();
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::btnNovoClick(TObject *Sender)
{
    String strValor, strCodigo;
    int intTamanho, intCodigo;

    if((dmBaseDados->tblConvCli->State == dsInsert) ||
(dmBaseDados->tblConvCli->State == dsEdit))
    {
    dmBaseDados->tblConvCli->Post();
    dmBaseDados->IBTransaction1->CommitRetaining();
    }
    dmBaseDados->tblConvCli->Last();
    intCodigo = StrToInt(dmBaseDados->tblConvCliCOD_CONVCLI->AsString);
    intCodigo++;
    if(intCodigo < 999)
       {
       strCodigo = IntToStr(intCodigo);
       intTamanho = StrLen(strCodigo.c_str());
       strValor = "00000"+Trim(strCodigo);
       strCodigo = MidStr(strValor,intTamanho+1,5);

       dmBaseDados->tblConvCli->Append();
       dmBaseDados->tblConvCliCOD_CONVCLI->AsString = strCodigo;
       }
    fldCodClifk->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TformConvCli::FormShow(TObject *Sender)
{
    if(!dmBaseDados->IBTransaction1->InTransaction)
        dmBaseDados->IBTransaction1->StartTransaction();
    dmBaseDados->tblConvCli->Open();
    if(dmBaseDados->tblConvCli->RecordCount == 0)
        {
        dmBaseDados->tblConvCli->Append();
        dmBaseDados->tblConvCliCOD_CONVCLI->AsString = "00001";
        }
    fldCodClifk->SetFocus();
}
//---------------------------------------------------------------------------

