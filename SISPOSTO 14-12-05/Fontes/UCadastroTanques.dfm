inherited formCadastroTanques: TformCadastroTanques
  Left = 198
  Top = 107
  Caption = 'Cadastro de tanques'
  ClientHeight = 151
  ClientWidth = 489
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodTan: TLabel [0]
    Left = 16
    Top = 56
    Width = 84
    Height = 13
    Caption = 'C'#243'digo do tanque'
  end
  object lblCodProd: TLabel [1]
    Left = 152
    Top = 56
    Width = 59
    Height = 13
    Caption = 'Combust'#237'vel'
  end
  object lblAberturaTan: TLabel [2]
    Left = 16
    Top = 96
    Width = 40
    Height = 13
    Caption = 'Abertura'
  end
  object lblFechamento: TLabel [3]
    Left = 192
    Top = 96
    Width = 59
    Height = 13
    Caption = 'Fechamento'
  end
  object lblDataregTan: TLabel [4]
    Left = 368
    Top = 96
    Width = 75
    Height = 13
    Caption = 'Data do registro'
  end
  inherited pnlBotoes: TPanel
    Width = 489
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
      Enabled = False
    end
    inherited btnExcluir: TSpeedButton
      OnClick = btnExcluirClick
    end
  end
  object fldCodTan: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COD_TAN'
    DataSource = dmBaseDados.dsTanques
    Enabled = False
    TabOrder = 1
  end
  object fldCodProd: TDBLookupComboBox
    Left = 152
    Top = 72
    Width = 321
    Height = 21
    DataField = 'COD_PROD_FK'
    DataSource = dmBaseDados.dsTanques
    KeyField = 'COD_COMB'
    ListField = 'NOME_COMB'
    ListSource = dmBaseDados.dsCombustiveis
    TabOrder = 2
  end
  object fldAberturaTan: TDBEdit
    Left = 16
    Top = 112
    Width = 169
    Height = 21
    AutoSize = False
    DataField = 'ABERTURA_TAN'
    DataSource = dmBaseDados.dsTanques
    TabOrder = 3
  end
  object fldFechamentoTan: TDBEdit
    Left = 192
    Top = 112
    Width = 169
    Height = 21
    AutoSize = False
    DataField = 'FECHAMENTO_TAN'
    DataSource = dmBaseDados.dsTanques
    TabOrder = 4
  end
  object fldDataregTan: TDBEdit
    Left = 368
    Top = 112
    Width = 105
    Height = 21
    AutoSize = False
    DataField = 'DATAREG_TAN'
    DataSource = dmBaseDados.dsTanques
    MaxLength = 10
    TabOrder = 5
  end
end
