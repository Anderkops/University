inherited formCadastroFornecedores: TformCadastroFornecedores
  Caption = 'Cadastro de fornecedores'
  ClientHeight = 337
  ClientWidth = 458
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodForn: TLabel [0]
    Left = 16
    Top = 56
    Width = 102
    Height = 13
    Caption = 'C'#243'digo do fornecedor'
  end
  object lblNomeForn: TLabel [1]
    Left = 152
    Top = 56
    Width = 97
    Height = 13
    Caption = 'Nome do fornecedor'
  end
  object lblNomecontForn: TLabel [2]
    Left = 16
    Top = 96
    Width = 85
    Height = 13
    Caption = 'Nome pra contato'
  end
  object lblLogradForn: TLabel [3]
    Left = 232
    Top = 96
    Width = 54
    Height = 13
    Caption = 'Logradouro'
  end
  object lblNumForn: TLabel [4]
    Left = 16
    Top = 136
    Width = 37
    Height = 13
    Caption = 'N'#250'mero'
  end
  object lblComplForn: TLabel [5]
    Left = 104
    Top = 136
    Width = 64
    Height = 13
    Caption = 'Complemento'
  end
  object lblBairroForn: TLabel [6]
    Left = 240
    Top = 136
    Width = 27
    Height = 13
    Caption = 'Bairro'
  end
  object lblCidForn: TLabel [7]
    Left = 16
    Top = 176
    Width = 33
    Height = 13
    Caption = 'Cidade'
  end
  object lblEstadoForn: TLabel [8]
    Left = 184
    Top = 176
    Width = 33
    Height = 13
    Caption = 'Estado'
  end
  object lblCepForn: TLabel [9]
    Left = 248
    Top = 176
    Width = 19
    Height = 13
    Caption = 'Cep'
  end
  object lblTelcomForn: TLabel [10]
    Left = 344
    Top = 176
    Width = 90
    Height = 13
    Caption = 'Telefone comercial'
  end
  object lblFaxForn: TLabel [11]
    Left = 16
    Top = 216
    Width = 17
    Height = 13
    Caption = 'Fax'
  end
  object lblIeForn: TLabel [12]
    Left = 160
    Top = 216
    Width = 86
    Height = 13
    Caption = 'Inscri'#231#227'o estadual'
  end
  object lbCgcForn: TLabel [13]
    Left = 304
    Top = 216
    Width = 31
    Height = 13
    Caption = 'C.G.C.'
  end
  object lblRefForn: TLabel [14]
    Left = 16
    Top = 256
    Width = 52
    Height = 13
    Caption = 'Refer'#234'ncia'
  end
  inherited pnlBotoes: TPanel
    Width = 458
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
  object fldCodForn: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COD_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 1
  end
  object fldNomeForn: TDBEdit
    Left = 152
    Top = 72
    Width = 289
    Height = 21
    AutoSize = False
    DataField = 'NOME_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 2
  end
  object fldNomecontForn: TDBEdit
    Left = 16
    Top = 112
    Width = 201
    Height = 21
    AutoSize = False
    DataField = 'NOMECONT_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 3
  end
  object fldLogradForn: TDBEdit
    Left = 232
    Top = 112
    Width = 209
    Height = 21
    AutoSize = False
    DataField = 'LOGRAD_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 4
  end
  object fldNumForn: TDBEdit
    Left = 16
    Top = 152
    Width = 73
    Height = 21
    AutoSize = False
    DataField = 'NUM_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 5
  end
  object fldComplForn: TDBEdit
    Left = 104
    Top = 152
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COMPL_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 6
  end
  object fldBairroForn: TDBEdit
    Left = 240
    Top = 152
    Width = 201
    Height = 21
    AutoSize = False
    DataField = 'BAIRRO_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 7
  end
  object fldCidForn: TDBEdit
    Left = 16
    Top = 192
    Width = 161
    Height = 21
    AutoSize = False
    DataField = 'CID_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 8
  end
  object fldEstadoForn: TDBComboBox
    Left = 184
    Top = 192
    Width = 57
    Height = 21
    DataField = 'ESTADO_FORN'
    DataSource = dmBaseDados.dsFornecedores
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
    TabOrder = 9
  end
  object fldCepForn: TDBEdit
    Left = 248
    Top = 192
    Width = 89
    Height = 21
    AutoSize = False
    DataField = 'CEP_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 10
  end
  object fldTelcomForn: TDBEdit
    Left = 344
    Top = 192
    Width = 97
    Height = 21
    AutoSize = False
    DataField = 'TELCOM_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 11
  end
  object fldFaxForn: TDBEdit
    Left = 16
    Top = 232
    Width = 137
    Height = 21
    AutoSize = False
    DataField = 'FAX_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 12
  end
  object fldIeForn: TDBEdit
    Left = 160
    Top = 232
    Width = 137
    Height = 21
    AutoSize = False
    DataField = 'IE_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 13
  end
  object fldCgcForn: TDBEdit
    Left = 304
    Top = 232
    Width = 137
    Height = 21
    AutoSize = False
    DataField = 'CGC_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 14
  end
  object fldRefForn: TDBMemo
    Left = 16
    Top = 272
    Width = 425
    Height = 49
    DataField = 'REF_FORN'
    DataSource = dmBaseDados.dsFornecedores
    TabOrder = 15
  end
end
