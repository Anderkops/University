inherited formCadastroFuncionarios: TformCadastroFuncionarios
  Left = 207
  Top = 112
  Caption = 'Cadastro de funcion'#225'rios'
  ClientHeight = 416
  ClientWidth = 441
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodFunc: TLabel [0]
    Left = 16
    Top = 56
    Width = 103
    Height = 13
    Caption = 'C'#243'digo do funcion'#225'rio'
  end
  object lblNomeFunc: TLabel [1]
    Left = 152
    Top = 56
    Width = 98
    Height = 13
    Caption = 'Nome do funcion'#225'rio'
  end
  object lblLogradFunc: TLabel [2]
    Left = 16
    Top = 96
    Width = 54
    Height = 13
    Caption = 'Logradouro'
  end
  object lblNumFunc: TLabel [3]
    Left = 224
    Top = 96
    Width = 37
    Height = 13
    Caption = 'N'#250'mero'
  end
  object lblComplFunc: TLabel [4]
    Left = 296
    Top = 96
    Width = 64
    Height = 13
    Caption = 'Complemento'
  end
  object lblBairroFunc: TLabel [5]
    Left = 16
    Top = 136
    Width = 27
    Height = 13
    Caption = 'Bairro'
  end
  object lblCidFunc: TLabel [6]
    Left = 192
    Top = 136
    Width = 33
    Height = 13
    Caption = 'Cidade'
  end
  object lblEstadoFunc: TLabel [7]
    Left = 368
    Top = 136
    Width = 33
    Height = 13
    Caption = 'Estado'
  end
  object lblCepFunc: TLabel [8]
    Left = 16
    Top = 176
    Width = 19
    Height = 13
    Caption = 'Cep'
  end
  object lblCelFunc: TLabel [9]
    Left = 288
    Top = 176
    Width = 32
    Height = 13
    Caption = 'Celular'
  end
  object lblTelresFunc: TLabel [10]
    Left = 144
    Top = 176
    Width = 95
    Height = 13
    Caption = 'Telefone residencial'
  end
  object lblPisFunc: TLabel [11]
    Left = 16
    Top = 216
    Width = 14
    Height = 13
    Caption = 'Pis'
  end
  object lblCpfFunc: TLabel [12]
    Left = 112
    Top = 216
    Width = 16
    Height = 13
    Caption = 'Cpf'
  end
  object lblRgFunc: TLabel [13]
    Left = 208
    Top = 216
    Width = 14
    Height = 13
    Caption = 'Rg'
  end
  object lblCarttrabFunc: TLabel [14]
    Left = 304
    Top = 216
    Width = 92
    Height = 13
    Caption = 'Carteira de trabalho'
  end
  object lblCargoFunc: TLabel [15]
    Left = 16
    Top = 256
    Width = 98
    Height = 13
    Caption = 'Cargo do funcion'#225'rio'
  end
  object Label2: TLabel [16]
    Left = 184
    Top = 256
    Width = 77
    Height = 13
    Caption = 'Data de entrada'
  end
  object Label3: TLabel [17]
    Left = 264
    Top = 256
    Width = 68
    Height = 13
    Caption = 'Data de sa'#237'da'
  end
  object Label4: TLabel [18]
    Left = 344
    Top = 256
    Width = 32
    Height = 13
    Caption = 'Sal'#225'rio'
  end
  object lblBancoFunc: TLabel [19]
    Left = 16
    Top = 296
    Width = 76
    Height = 13
    Caption = 'Nome do banco'
  end
  object lblAgenciaFunc: TLabel [20]
    Left = 224
    Top = 296
    Width = 39
    Height = 13
    Caption = 'Ag'#234'ncia'
  end
  object lblContaFunc: TLabel [21]
    Left = 320
    Top = 296
    Width = 71
    Height = 13
    Caption = 'Conta Corrente'
  end
  object lblRefFunc: TLabel [22]
    Left = 16
    Top = 336
    Width = 52
    Height = 13
    Caption = 'Refer'#234'ncia'
  end
  inherited pnlBotoes: TPanel
    Width = 441
    inherited btnPrimeiro: TSpeedButton
      OnClick = btnPrimeiroClick
    end
    inherited btnAnterior: TSpeedButton
      OnClick = btnAnteriorClick
    end
    inherited btnProximo: TSpeedButton
      OnClick = btnProximoClick
    end
    inherited btnUltimo: TSpeedButton
      OnClick = btnUltimoClick
    end
    inherited btnNovo: TSpeedButton
      OnClick = btnNovoClick
    end
    inherited btnLocalizar: TSpeedButton
      OnClick = btnLocalizarClick
    end
    inherited btnExcluir: TSpeedButton
      OnClick = btnExcluirClick
    end
  end
  object fldCodFunc: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COD_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    Enabled = False
    TabOrder = 1
  end
  object fldNomeFunc: TDBEdit
    Left = 152
    Top = 72
    Width = 273
    Height = 21
    AutoSize = False
    DataField = 'NOME_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 2
  end
  object fldLogradFunc: TDBEdit
    Left = 16
    Top = 112
    Width = 193
    Height = 21
    AutoSize = False
    DataField = 'LOGRAD_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 3
  end
  object fldNumFunc: TDBEdit
    Left = 224
    Top = 112
    Width = 57
    Height = 21
    AutoSize = False
    DataField = 'NUM_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 4
  end
  object fldComplFunc: TDBEdit
    Left = 296
    Top = 112
    Width = 129
    Height = 21
    AutoSize = False
    DataField = 'COMPL_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 5
  end
  object fldBairroFunc: TDBEdit
    Left = 16
    Top = 152
    Width = 169
    Height = 21
    AutoSize = False
    DataField = 'BAIRRO_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 6
  end
  object fldCidFunc: TDBEdit
    Left = 192
    Top = 152
    Width = 169
    Height = 21
    AutoSize = False
    DataField = 'CID_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 7
  end
  object fldEstadoFunc: TDBComboBox
    Left = 368
    Top = 152
    Width = 57
    Height = 21
    DataField = 'ESTADO_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    ItemHeight = 13
    Items.Strings = (
      'AC'
      'AL'
      'AM'
      'AP'
      'BA'
      'CE'
      'DF'
      'ES'
      'GO'
      'MA'
      'MG'
      'MS'
      'MT'
      'PA'
      'PB'
      'PE'
      'PI'
      'PR'
      'RJ'
      'RN'
      'RO'
      'RR'
      'RS'
      'SC'
      'SE'
      'SP'
      'TO')
    TabOrder = 8
  end
  object fldCepFunc: TDBEdit
    Left = 16
    Top = 192
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'CEP_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 9
  end
  object fldCelFunc: TDBEdit
    Left = 288
    Top = 192
    Width = 137
    Height = 21
    AutoSize = False
    DataField = 'CEL_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 11
  end
  object fldTelresFunc: TDBEdit
    Left = 144
    Top = 192
    Width = 137
    Height = 21
    AutoSize = False
    DataField = 'TELRES_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 10
  end
  object fldPisFunc: TDBEdit
    Left = 16
    Top = 232
    Width = 89
    Height = 21
    AutoSize = False
    DataField = 'PIS_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 12
  end
  object fldCpfFunc: TDBEdit
    Left = 112
    Top = 232
    Width = 89
    Height = 21
    AutoSize = False
    DataField = 'CPF_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 13
  end
  object fldRgFunc: TDBEdit
    Left = 208
    Top = 232
    Width = 89
    Height = 21
    AutoSize = False
    DataField = 'RG_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 14
  end
  object fldCarttrabFunc: TDBEdit
    Left = 304
    Top = 232
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'CARTTRAB_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 15
  end
  object fldCargoFunc: TDBEdit
    Left = 16
    Top = 272
    Width = 161
    Height = 21
    AutoSize = False
    DataField = 'CARGO_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 16
  end
  object fldDataaentrFunc: TDBEdit
    Left = 184
    Top = 272
    Width = 73
    Height = 21
    AutoSize = False
    DataField = 'DATAENTR_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 17
  end
  object fldDatasaidaFunc: TDBEdit
    Left = 264
    Top = 272
    Width = 73
    Height = 21
    AutoSize = False
    DataField = 'DATASAIDA_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 18
  end
  object SalarioFunc: TDBEdit
    Left = 344
    Top = 272
    Width = 81
    Height = 21
    AutoSize = False
    DataField = 'SALARIO_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 19
  end
  object fldBancoFunc: TDBEdit
    Left = 16
    Top = 312
    Width = 193
    Height = 21
    AutoSize = False
    DataField = 'BANCO_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 20
  end
  object fldAgenciaFunc: TDBEdit
    Left = 224
    Top = 312
    Width = 81
    Height = 21
    AutoSize = False
    DataField = 'AGENCIA_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 21
  end
  object fldContaFunc: TDBEdit
    Left = 320
    Top = 312
    Width = 105
    Height = 21
    AutoSize = False
    DataField = 'CONTA_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 22
  end
  object fldRefFunc: TDBMemo
    Left = 16
    Top = 352
    Width = 409
    Height = 49
    DataField = 'REF_FUNC'
    DataSource = dmBaseDados.dsFuncionarios
    TabOrder = 23
  end
end
