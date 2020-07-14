//---------------------------------------------------------------------------

#ifndef UModuloDadosH
#define UModuloDadosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBTable.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TdmBaseDados : public TDataModule
{
__published:	// IDE-managed Components
        TIBDatabase *dbBaseDados;
        TIBTransaction *IBTransaction1;
        TIBTable *tblConvenios;
        TIntegerField *tblConveniosCOD_CONV;
        TIBStringField *tblConveniosNOME_CONV;
        TIBBCDField *tblConveniosDESCVISTA_CONV;
        TIBBCDField *tblConveniosDESCPRAZO_CONV;
        TIBBCDField *tblConveniosCOMISSAO_CONV;
        TDataSource *dsConvenios;
        TIBTable *tblClientes;
        TIntegerField *tblClientesCOD_CLI;
        TIBStringField *tblClientesNOME_CLI;
        TIBStringField *tblClientesLOGRAD_CLI;
        TIBStringField *tblClientesNUM_CLI;
        TIBStringField *tblClientesCOMPL_CLI;
        TIBStringField *tblClientesBAIRRO_CLI;
        TIBStringField *tblClientesCID_CLI;
        TIBStringField *tblClientesESTADO_CLI;
        TIBStringField *tblClientesCEP_CLI;
        TIBStringField *tblClientesTELCOM_CLI;
        TIBStringField *tblClientesTELRES_CLI;
        TIBStringField *tblClientesREF_CLI;
        TDataSource *dsClientes;
        TIBTable *tblFuncionarios;
        TIntegerField *tblFuncionariosCOD_FUNC;
        TIBStringField *tblFuncionariosNOME_FUNC;
        TIBStringField *tblFuncionariosLOGRAD_FUNC;
        TIBStringField *tblFuncionariosNUM_FUNC;
        TIBStringField *tblFuncionariosCOMPL_FUNC;
        TIBStringField *tblFuncionariosBAIRRO_FUNC;
        TIBStringField *tblFuncionariosCID_FUNC;
        TIBStringField *tblFuncionariosESTADO_FUNC;
        TIBStringField *tblFuncionariosCEP_FUNC;
        TIBStringField *tblFuncionariosTELRES_FUNC;
        TIBStringField *tblFuncionariosCEL_FUNC;
        TIBStringField *tblFuncionariosPIS_FUNC;
        TIBStringField *tblFuncionariosCPF_FUNC;
        TIBStringField *tblFuncionariosRG_FUNC;
        TIBStringField *tblFuncionariosCARGO_FUNC;
        TIBStringField *tblFuncionariosCARTTRAB_FUNC;
        TDateField *tblFuncionariosDATAENTR_FUNC;
        TDateField *tblFuncionariosDATASAIDA_FUNC;
        TIBBCDField *tblFuncionariosSALARIO_FUNC;
        TIBStringField *tblFuncionariosBANCO_FUNC;
        TIBStringField *tblFuncionariosAGENCIA_FUNC;
        TIBStringField *tblFuncionariosCONTA_FUNC;
        TIBStringField *tblFuncionariosREF_FUNC;
        TDataSource *dsFuncionarios;
        TIBTable *tblFornecedores;
        TIntegerField *tblFornecedoresCOD_FORN;
        TIBStringField *tblFornecedoresNOME_FORN;
        TIBStringField *tblFornecedoresNOMECONT_FORN;
        TIBStringField *tblFornecedoresLOGRAD_FORN;
        TIBStringField *tblFornecedoresNUM_FORN;
        TIBStringField *tblFornecedoresCOMPL_FORN;
        TIBStringField *tblFornecedoresBAIRRO_FORN;
        TIBStringField *tblFornecedoresCID_FORN;
        TIBStringField *tblFornecedoresESTADO_FORN;
        TIBStringField *tblFornecedoresCEP_FORN;
        TIBStringField *tblFornecedoresTELCOM_FORN;
        TIBStringField *tblFornecedoresFAX_FORN;
        TIBStringField *tblFornecedoresCGC_FORN;
        TIBStringField *tblFornecedoresIE_FORN;
        TIBStringField *tblFornecedoresREF_FORN;
        TDataSource *dsFornecedores;
        TIBTable *tblProdutos;
        TIntegerField *tblProdutosCOD_PROD;
        TIBStringField *tblProdutosNOME_PROD;
        TIBStringField *tblProdutosMARCA_PROD;
        TIBBCDField *tblProdutosMEDIDA_PROD;
        TIBStringField *tblProdutosUNIDMED_PROD;
        TIntegerField *tblProdutosCOD_FORN_FK;
        TIBStringField *tblProdutosTIPO_PROD;
        TIBBCDField *tblProdutosPRECO_PROD;
        TIntegerField *tblProdutosESTOQUE_PROD;
        TDateField *tblProdutosDATACAD_PROD;
        TDataSource *dsProdutos;
        TIBTable *tblTanques;
        TIntegerField *tblTanquesCOD_TAN;
        TIntegerField *tblTanquesCOD_PROD_FK;
        TIBStringField *tblTanquesABERTURA_TAN;
        TIBStringField *tblTanquesFECHAMENTO_TAN;
        TDateField *tblTanquesDATAREG_TAN;
        TDataSource *dsTanques;
        TIBTable *tblBombas;
        TIntegerField *tblBombasCOD_BOM;
        TIntegerField *tblBombasCOD_TAN_FK;
        TIBBCDField *tblBombasLEITURA_BOM;
        TDateField *tblBombasDATALEIT_BOM;
        TTimeField *tblBombasHORALEIT_BOM;
        TDataSource *dsBombas;
        TIBTable *tblBicos;
        TIntegerField *tblBicosCOD_BIC;
        TIntegerField *tblBicosCOD_BOM_FK;
        TDataSource *dsBicos;
        TIBQuery *ibqCombustiveis;
        TDataSource *dsCombustiveis;
        TIBTable *tblVendas;
        TDataSource *dsVendas;
        TIBTable *tblConvCli;
        TDataSource *dsConvCli;
        TIntegerField *tblConvCliCOD_CLI_FK;
        TIntegerField *tblConvCliCOD_CONV_FK;
        TIBTable *tblItemVenda;
        TDataSource *dsItemVenda;
        TIntegerField *tblItemVendaCOD_VEND_FK2;
        TIntegerField *tblItemVendaCOD_PROD_FK2;
        TIntegerField *tblItemVendaQTDE_ITEM;
        TIBBCDField *tblItemVendaVALORUNIT_ITEM;
        TIBBCDField *tblItemVendaSUBTOTAL_ITEM;
        TIntegerField *tblConvCliCOD_CONVCLI;
        TIBQuery *ibqVendaData;
        TDataSource *dsVendaData;
        TIBQuery *ibqEstoque;
        TDataSource *dsEstoque;
        TIBQuery *ibqVendaFunc;
        TDataSource *dsVendaFunc;
        TIBQuery *ibqVendaProd;
        TDataSource *dsVendaProd;
        TIBQuery *ibqSoProd;
        TDataSource *dsSoProd;
        TIBQuery *ibqServicos;
        TDataSource *dsServicos;
        void __fastcall tblConveniosBeforeDelete(TDataSet *DataSet);
        void __fastcall tblClientesBeforeDelete(TDataSet *DataSet);
        void __fastcall tblFuncionariosBeforeDelete(TDataSet *DataSet);
        void __fastcall tblFornecedoresBeforeDelete(TDataSet *DataSet);
        void __fastcall tblProdutosBeforeDelete(TDataSet *DataSet);
        void __fastcall tblTanquesBeforeDelete(TDataSet *DataSet);
        void __fastcall tblBombasBeforeDelete(TDataSet *DataSet);
        void __fastcall tblBicosBeforeDelete(TDataSet *DataSet);
        void __fastcall tblConvCliBeforeDelete(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TdmBaseDados(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdmBaseDados *dmBaseDados;
//---------------------------------------------------------------------------
#endif
