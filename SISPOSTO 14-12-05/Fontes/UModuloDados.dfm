object dmBaseDados: TdmBaseDados
  OldCreateOrder = False
  Left = 427
  Top = 113
  Height = 490
  Width = 555
  object dbBaseDados: TIBDatabase
    DatabaseName = 'F:\SISPOSTO 14-12-05\Banco de Dados'
    Params.Strings = (
      'user_name=pirapo'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTransaction1
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 32
    Top = 16
  end
  object IBTransaction1: TIBTransaction
    Active = False
    AutoStopAction = saNone
    Left = 120
    Top = 16
  end
  object tblConvenios: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblConveniosBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_CONV'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NOME_CONV'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'DESCVISTA_CONV'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 4
        Size = 4
      end
      item
        Name = 'DESCPRAZO_CONV'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 4
        Size = 4
      end
      item
        Name = 'COMISSAO_CONV'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 4
        Size = 4
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY3'
        Fields = 'COD_CONV'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'CONVENIOS'
    Left = 32
    Top = 80
    object tblConveniosCOD_CONV: TIntegerField
      FieldName = 'COD_CONV'
      Required = True
    end
    object tblConveniosNOME_CONV: TIBStringField
      FieldName = 'NOME_CONV'
      Required = True
      Size = 40
    end
    object tblConveniosDESCVISTA_CONV: TIBBCDField
      FieldName = 'DESCVISTA_CONV'
      Required = True
      DisplayFormat = '##,##0.00'
      Precision = 4
      Size = 4
    end
    object tblConveniosDESCPRAZO_CONV: TIBBCDField
      FieldName = 'DESCPRAZO_CONV'
      Required = True
      DisplayFormat = '##,##0.00'
      Precision = 4
      Size = 4
    end
    object tblConveniosCOMISSAO_CONV: TIBBCDField
      FieldName = 'COMISSAO_CONV'
      Required = True
      DisplayFormat = '##,##0.00'
      Precision = 4
      Size = 4
    end
  end
  object dsConvenios: TDataSource
    DataSet = tblConvenios
    Left = 120
    Top = 80
  end
  object tblClientes: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblClientesBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_CLI'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NOME_CLI'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'LOGRAD_CLI'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'NUM_CLI'
        DataType = ftString
        Size = 7
      end
      item
        Name = 'COMPL_CLI'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'BAIRRO_CLI'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CID_CLI'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ESTADO_CLI'
        DataType = ftString
        Size = 2
      end
      item
        Name = 'CEP_CLI'
        DataType = ftString
        Size = 9
      end
      item
        Name = 'TELCOM_CLI'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'TELRES_CLI'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'REF_CLI'
        DataType = ftString
        Size = 200
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'COD_CLI'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'CLIENTES'
    Left = 32
    Top = 144
    object tblClientesCOD_CLI: TIntegerField
      FieldName = 'COD_CLI'
      Required = True
    end
    object tblClientesNOME_CLI: TIBStringField
      FieldName = 'NOME_CLI'
      Required = True
      Size = 40
    end
    object tblClientesLOGRAD_CLI: TIBStringField
      FieldName = 'LOGRAD_CLI'
      Size = 40
    end
    object tblClientesNUM_CLI: TIBStringField
      FieldName = 'NUM_CLI'
      Size = 7
    end
    object tblClientesCOMPL_CLI: TIBStringField
      FieldName = 'COMPL_CLI'
      Size = 15
    end
    object tblClientesBAIRRO_CLI: TIBStringField
      FieldName = 'BAIRRO_CLI'
    end
    object tblClientesCID_CLI: TIBStringField
      FieldName = 'CID_CLI'
    end
    object tblClientesESTADO_CLI: TIBStringField
      FieldName = 'ESTADO_CLI'
      Size = 2
    end
    object tblClientesCEP_CLI: TIBStringField
      FieldName = 'CEP_CLI'
      EditMask = '99999-999;1;_'
      Size = 9
    end
    object tblClientesTELCOM_CLI: TIBStringField
      FieldName = 'TELCOM_CLI'
      Size = 15
    end
    object tblClientesTELRES_CLI: TIBStringField
      FieldName = 'TELRES_CLI'
      Size = 15
    end
    object tblClientesREF_CLI: TIBStringField
      FieldName = 'REF_CLI'
      Size = 200
    end
  end
  object dsClientes: TDataSource
    DataSet = tblClientes
    Left = 120
    Top = 144
  end
  object tblFuncionarios: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblFuncionariosBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_FUNC'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NOME_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'LOGRAD_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'NUM_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 7
      end
      item
        Name = 'COMPL_FUNC'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'BAIRRO_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CID_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ESTADO_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 2
      end
      item
        Name = 'CEP_FUNC'
        DataType = ftString
        Size = 9
      end
      item
        Name = 'TELRES_FUNC'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'CEL_FUNC'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'PIS_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CPF_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RG_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CARGO_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CARTTRAB_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DATAENTR_FUNC'
        Attributes = [faRequired]
        DataType = ftDate
      end
      item
        Name = 'DATASAIDA_FUNC'
        DataType = ftDate
      end
      item
        Name = 'SALARIO_FUNC'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'BANCO_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'AGENCIA_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 10
      end
      item
        Name = 'CONTA_FUNC'
        Attributes = [faRequired]
        DataType = ftString
        Size = 15
      end
      item
        Name = 'REF_FUNC'
        DataType = ftString
        Size = 200
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'COD_FUNC'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'FUNCIONARIOS'
    Left = 32
    Top = 208
    object tblFuncionariosCOD_FUNC: TIntegerField
      FieldName = 'COD_FUNC'
      Required = True
    end
    object tblFuncionariosNOME_FUNC: TIBStringField
      FieldName = 'NOME_FUNC'
      Required = True
      Size = 40
    end
    object tblFuncionariosLOGRAD_FUNC: TIBStringField
      FieldName = 'LOGRAD_FUNC'
      Required = True
      Size = 40
    end
    object tblFuncionariosNUM_FUNC: TIBStringField
      FieldName = 'NUM_FUNC'
      Required = True
      Size = 7
    end
    object tblFuncionariosCOMPL_FUNC: TIBStringField
      FieldName = 'COMPL_FUNC'
      Size = 15
    end
    object tblFuncionariosBAIRRO_FUNC: TIBStringField
      FieldName = 'BAIRRO_FUNC'
      Required = True
    end
    object tblFuncionariosCID_FUNC: TIBStringField
      FieldName = 'CID_FUNC'
      Required = True
    end
    object tblFuncionariosESTADO_FUNC: TIBStringField
      FieldName = 'ESTADO_FUNC'
      Required = True
      Size = 2
    end
    object tblFuncionariosCEP_FUNC: TIBStringField
      FieldName = 'CEP_FUNC'
      EditMask = '99999-999;1;_'
      Size = 9
    end
    object tblFuncionariosTELRES_FUNC: TIBStringField
      FieldName = 'TELRES_FUNC'
      Size = 15
    end
    object tblFuncionariosCEL_FUNC: TIBStringField
      FieldName = 'CEL_FUNC'
      Size = 15
    end
    object tblFuncionariosPIS_FUNC: TIBStringField
      FieldName = 'PIS_FUNC'
      Required = True
      EditMask = '999.99999.99-A;1;_'
    end
    object tblFuncionariosCPF_FUNC: TIBStringField
      FieldName = 'CPF_FUNC'
      Required = True
      EditMask = '999.999.999-99;1;_'
    end
    object tblFuncionariosRG_FUNC: TIBStringField
      FieldName = 'RG_FUNC'
      Required = True
      EditMask = '99.999.999-A;1;_'
    end
    object tblFuncionariosCARGO_FUNC: TIBStringField
      FieldName = 'CARGO_FUNC'
      Required = True
    end
    object tblFuncionariosCARTTRAB_FUNC: TIBStringField
      FieldName = 'CARTTRAB_FUNC'
      Required = True
    end
    object tblFuncionariosDATAENTR_FUNC: TDateField
      FieldName = 'DATAENTR_FUNC'
      Required = True
      EditMask = '99/99/9999;1;_'
    end
    object tblFuncionariosDATASAIDA_FUNC: TDateField
      FieldName = 'DATASAIDA_FUNC'
      EditMask = '99/99/9999;1;_'
    end
    object tblFuncionariosSALARIO_FUNC: TIBBCDField
      FieldName = 'SALARIO_FUNC'
      Required = True
      DisplayFormat = '#######,##0.00'
      Precision = 18
      Size = 2
    end
    object tblFuncionariosBANCO_FUNC: TIBStringField
      FieldName = 'BANCO_FUNC'
      Required = True
    end
    object tblFuncionariosAGENCIA_FUNC: TIBStringField
      FieldName = 'AGENCIA_FUNC'
      Required = True
      Size = 10
    end
    object tblFuncionariosCONTA_FUNC: TIBStringField
      FieldName = 'CONTA_FUNC'
      Required = True
      Size = 15
    end
    object tblFuncionariosREF_FUNC: TIBStringField
      FieldName = 'REF_FUNC'
      Size = 200
    end
  end
  object dsFuncionarios: TDataSource
    DataSet = tblFuncionarios
    Left = 120
    Top = 208
  end
  object tblFornecedores: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblFornecedoresBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_FORN'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NOME_FORN'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'NOMECONT_FORN'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'LOGRAD_FORN'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'NUM_FORN'
        DataType = ftString
        Size = 7
      end
      item
        Name = 'COMPL_FORN'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'BAIRRO_FORN'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'CID_FORN'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ESTADO_FORN'
        DataType = ftString
        Size = 2
      end
      item
        Name = 'CEP_FORN'
        DataType = ftString
        Size = 9
      end
      item
        Name = 'TELCOM_FORN'
        Attributes = [faRequired]
        DataType = ftString
        Size = 15
      end
      item
        Name = 'FAX_FORN'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'CGC_FORN'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'IE_FORN'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'REF_FORN'
        DataType = ftString
        Size = 200
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY7'
        Fields = 'COD_FORN'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'FORNECEDORES'
    Left = 32
    Top = 272
    object tblFornecedoresCOD_FORN: TIntegerField
      FieldName = 'COD_FORN'
      Required = True
    end
    object tblFornecedoresNOME_FORN: TIBStringField
      FieldName = 'NOME_FORN'
      Required = True
      Size = 40
    end
    object tblFornecedoresNOMECONT_FORN: TIBStringField
      FieldName = 'NOMECONT_FORN'
      Size = 40
    end
    object tblFornecedoresLOGRAD_FORN: TIBStringField
      FieldName = 'LOGRAD_FORN'
      Size = 40
    end
    object tblFornecedoresNUM_FORN: TIBStringField
      FieldName = 'NUM_FORN'
      Size = 7
    end
    object tblFornecedoresCOMPL_FORN: TIBStringField
      FieldName = 'COMPL_FORN'
      Size = 15
    end
    object tblFornecedoresBAIRRO_FORN: TIBStringField
      FieldName = 'BAIRRO_FORN'
    end
    object tblFornecedoresCID_FORN: TIBStringField
      FieldName = 'CID_FORN'
    end
    object tblFornecedoresESTADO_FORN: TIBStringField
      FieldName = 'ESTADO_FORN'
      Size = 2
    end
    object tblFornecedoresCEP_FORN: TIBStringField
      FieldName = 'CEP_FORN'
      EditMask = '99999-999;1;_'
      Size = 9
    end
    object tblFornecedoresTELCOM_FORN: TIBStringField
      FieldName = 'TELCOM_FORN'
      Required = True
      Size = 15
    end
    object tblFornecedoresFAX_FORN: TIBStringField
      FieldName = 'FAX_FORN'
      Size = 15
    end
    object tblFornecedoresCGC_FORN: TIBStringField
      FieldName = 'CGC_FORN'
      EditMask = '999.999.999/9999-99;1;_'
      Size = 15
    end
    object tblFornecedoresIE_FORN: TIBStringField
      FieldName = 'IE_FORN'
      Size = 15
    end
    object tblFornecedoresREF_FORN: TIBStringField
      FieldName = 'REF_FORN'
      Size = 200
    end
  end
  object dsFornecedores: TDataSource
    DataSet = tblFornecedores
    Left = 120
    Top = 272
  end
  object tblProdutos: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblProdutosBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_PROD'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NOME_PROD'
        Attributes = [faRequired]
        DataType = ftString
        Size = 40
      end
      item
        Name = 'MARCA_PROD'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'MEDIDA_PROD'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'UNIDMED_PROD'
        Attributes = [faRequired]
        DataType = ftString
        Size = 15
      end
      item
        Name = 'COD_FORN_FK'
        DataType = ftInteger
      end
      item
        Name = 'TIPO_PROD'
        Attributes = [faRequired]
        DataType = ftString
        Size = 1
      end
      item
        Name = 'PRECO_PROD'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'ESTOQUE_PROD'
        DataType = ftInteger
      end
      item
        Name = 'DATACAD_PROD'
        DataType = ftDate
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY8'
        Fields = 'COD_PROD'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN9'
        Fields = 'COD_FORN_FK'
      end>
    StoreDefs = True
    TableName = 'PRODUTOS'
    Left = 32
    Top = 336
    object tblProdutosCOD_PROD: TIntegerField
      FieldName = 'COD_PROD'
      Required = True
    end
    object tblProdutosNOME_PROD: TIBStringField
      FieldName = 'NOME_PROD'
      Required = True
      Size = 40
    end
    object tblProdutosMARCA_PROD: TIBStringField
      FieldName = 'MARCA_PROD'
    end
    object tblProdutosMEDIDA_PROD: TIBBCDField
      FieldName = 'MEDIDA_PROD'
      Precision = 18
      Size = 2
    end
    object tblProdutosUNIDMED_PROD: TIBStringField
      FieldName = 'UNIDMED_PROD'
      Required = True
      Size = 15
    end
    object tblProdutosCOD_FORN_FK: TIntegerField
      FieldName = 'COD_FORN_FK'
    end
    object tblProdutosTIPO_PROD: TIBStringField
      FieldName = 'TIPO_PROD'
      Required = True
      Size = 1
    end
    object tblProdutosPRECO_PROD: TIBBCDField
      FieldName = 'PRECO_PROD'
      Required = True
      DisplayFormat = '######,##0.00'
      Precision = 18
      Size = 2
    end
    object tblProdutosESTOQUE_PROD: TIntegerField
      FieldName = 'ESTOQUE_PROD'
    end
    object tblProdutosDATACAD_PROD: TDateField
      FieldName = 'DATACAD_PROD'
      EditMask = '99/99/9999;1;_'
    end
  end
  object dsProdutos: TDataSource
    DataSet = tblProdutos
    Left = 120
    Top = 336
  end
  object tblTanques: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblTanquesBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_TAN'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_PROD_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'ABERTURA_TAN'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'FECHAMENTO_TAN'
        Attributes = [faRequired]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DATAREG_TAN'
        Attributes = [faRequired]
        DataType = ftDate
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY17'
        Fields = 'COD_TAN'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN18'
        Fields = 'COD_PROD_FK'
      end>
    StoreDefs = True
    TableName = 'TANQUES'
    Left = 232
    Top = 16
    object tblTanquesCOD_TAN: TIntegerField
      FieldName = 'COD_TAN'
      Required = True
    end
    object tblTanquesCOD_PROD_FK: TIntegerField
      FieldName = 'COD_PROD_FK'
      Required = True
    end
    object tblTanquesABERTURA_TAN: TIBStringField
      FieldName = 'ABERTURA_TAN'
      Required = True
    end
    object tblTanquesFECHAMENTO_TAN: TIBStringField
      FieldName = 'FECHAMENTO_TAN'
      Required = True
    end
    object tblTanquesDATAREG_TAN: TDateField
      FieldName = 'DATAREG_TAN'
      Required = True
      EditMask = '99/99/9999;1;_'
    end
  end
  object dsTanques: TDataSource
    DataSet = tblTanques
    Left = 312
    Top = 16
  end
  object tblBombas: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblBombasBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_BOM'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_TAN_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'LEITURA_BOM'
        Attributes = [faRequired]
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'DATALEIT_BOM'
        Attributes = [faRequired]
        DataType = ftDate
      end
      item
        Name = 'HORALEIT_BOM'
        Attributes = [faRequired]
        DataType = ftTime
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY19'
        Fields = 'COD_BOM'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN20'
        Fields = 'COD_TAN_FK'
      end>
    StoreDefs = True
    TableName = 'BOMBAS'
    Left = 232
    Top = 80
    object tblBombasCOD_BOM: TIntegerField
      FieldName = 'COD_BOM'
      Required = True
    end
    object tblBombasCOD_TAN_FK: TIntegerField
      FieldName = 'COD_TAN_FK'
      Required = True
    end
    object tblBombasLEITURA_BOM: TIBBCDField
      FieldName = 'LEITURA_BOM'
      Required = True
      Precision = 18
      Size = 2
    end
    object tblBombasDATALEIT_BOM: TDateField
      FieldName = 'DATALEIT_BOM'
      Required = True
      EditMask = '99/99/9999;1;_'
    end
    object tblBombasHORALEIT_BOM: TTimeField
      FieldName = 'HORALEIT_BOM'
      Required = True
      EditMask = '99:99;1;_'
    end
  end
  object dsBombas: TDataSource
    DataSet = tblBombas
    Left = 312
    Top = 80
  end
  object tblBicos: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblBicosBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_BIC'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_BOM_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY21'
        Fields = 'COD_BIC'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN22'
        Fields = 'COD_BOM_FK'
      end>
    StoreDefs = True
    TableName = 'BICOS'
    Left = 232
    Top = 144
    object tblBicosCOD_BIC: TIntegerField
      FieldName = 'COD_BIC'
      Required = True
    end
    object tblBicosCOD_BOM_FK: TIntegerField
      FieldName = 'COD_BOM_FK'
      Required = True
    end
  end
  object dsBicos: TDataSource
    DataSet = tblBicos
    Left = 312
    Top = 144
  end
  object ibqCombustiveis: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from combustiveis')
    Left = 232
    Top = 216
  end
  object dsCombustiveis: TDataSource
    DataSet = ibqCombustiveis
    Left = 312
    Top = 216
  end
  object tblVendas: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_VEND'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_CLI_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_FUNC_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_CONV_FK'
        DataType = ftInteger
      end
      item
        Name = 'SUBTOTAL_VEND'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'DESCONTO_VEND'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'TOTAL_VEND'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'DATA_VEND'
        DataType = ftDate
      end
      item
        Name = 'HORA_VEND'
        DataType = ftTime
      end
      item
        Name = 'SITUACAO_VEND'
        Attributes = [faRequired]
        DataType = ftString
        Size = 5
      end
      item
        Name = 'DATAPAG_VEND'
        DataType = ftDate
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY10'
        Fields = 'COD_VEND'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN11'
        Fields = 'COD_CLI_FK'
      end
      item
        Name = 'RDB$FOREIGN12'
        Fields = 'COD_FUNC_FK'
      end
      item
        Name = 'RDB$FOREIGN13'
        Fields = 'COD_CONV_FK'
      end>
    StoreDefs = True
    TableName = 'VENDAS'
    Left = 32
    Top = 400
  end
  object dsVendas: TDataSource
    DataSet = tblVendas
    Left = 120
    Top = 400
  end
  object tblConvCli: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BeforeDelete = tblConvCliBeforeDelete
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_CONVCLI'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_CLI_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_CONV_FK'
        Attributes = [faRequired]
        DataType = ftInteger
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY11'
        Fields = 'COD_CONVCLI'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN16'
        Fields = 'COD_CLI_FK'
      end
      item
        Name = 'RDB$FOREIGN17'
        Fields = 'COD_CONV_FK'
      end>
    StoreDefs = True
    TableName = 'CONVCLI'
    Left = 232
    Top = 272
    object tblConvCliCOD_CLI_FK: TIntegerField
      FieldName = 'COD_CLI_FK'
      Required = True
    end
    object tblConvCliCOD_CONV_FK: TIntegerField
      FieldName = 'COD_CONV_FK'
      Required = True
    end
    object tblConvCliCOD_CONVCLI: TIntegerField
      FieldName = 'COD_CONVCLI'
      Required = True
    end
  end
  object dsConvCli: TDataSource
    DataSet = tblConvCli
    Left = 312
    Top = 272
  end
  object tblItemVenda: TIBTable
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'COD_VEND_FK2'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'COD_PROD_FK2'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'QTDE_ITEM'
        DataType = ftInteger
      end
      item
        Name = 'VALORUNIT_ITEM'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end
      item
        Name = 'SUBTOTAL_ITEM'
        DataType = ftBCD
        Precision = 18
        Size = 2
      end>
    IndexDefs = <
      item
        Name = 'RDB$FOREIGN14'
        Fields = 'COD_VEND_FK2'
      end
      item
        Name = 'RDB$FOREIGN15'
        Fields = 'COD_PROD_FK2'
      end
      item
        Name = 'RDB$PRIMARY16'
        Fields = 'COD_VEND_FK2;COD_PROD_FK2'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'ITEMVENDA'
    Left = 216
    Top = 400
    object tblItemVendaCOD_VEND_FK2: TIntegerField
      FieldName = 'COD_VEND_FK2'
      Required = True
    end
    object tblItemVendaCOD_PROD_FK2: TIntegerField
      FieldName = 'COD_PROD_FK2'
      Required = True
    end
    object tblItemVendaQTDE_ITEM: TIntegerField
      FieldName = 'QTDE_ITEM'
    end
    object tblItemVendaVALORUNIT_ITEM: TIBBCDField
      FieldName = 'VALORUNIT_ITEM'
      Precision = 18
      Size = 2
    end
    object tblItemVendaSUBTOTAL_ITEM: TIBBCDField
      FieldName = 'SUBTOTAL_ITEM'
      Precision = 18
      Size = 2
    end
  end
  object dsItemVenda: TDataSource
    DataSet = tblItemVenda
    Left = 304
    Top = 400
  end
  object ibqVendaData: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from venda_data order by data_vd desc')
    Left = 416
    Top = 16
  end
  object dsVendaData: TDataSource
    DataSet = ibqVendaData
    Left = 496
    Top = 16
  end
  object ibqEstoque: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from estoque')
    Left = 416
    Top = 80
  end
  object dsEstoque: TDataSource
    DataSet = ibqEstoque
    Left = 496
    Top = 80
  end
  object ibqVendaFunc: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from venda_func order by data_vf')
    Left = 416
    Top = 144
  end
  object dsVendaFunc: TDataSource
    DataSet = ibqVendaFunc
    Left = 496
    Top = 144
  end
  object ibqVendaProd: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from qtde_vendida_prod')
    Left = 416
    Top = 216
  end
  object dsVendaProd: TDataSource
    DataSet = ibqVendaProd
    Left = 496
    Top = 216
  end
  object ibqSoProd: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from soprodutos')
    Left = 416
    Top = 272
  end
  object dsSoProd: TDataSource
    DataSet = ibqSoProd
    Left = 488
    Top = 272
  end
  object ibqServicos: TIBQuery
    Database = dbBaseDados
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * from servicos')
    Left = 416
    Top = 344
  end
  object dsServicos: TDataSource
    DataSet = ibqServicos
    Left = 488
    Top = 344
  end
end
