inherited formConvCli: TformConvCli
  Left = 197
  Top = 157
  Caption = 'Relacionar cliente/conv'#234'nio'
  ClientHeight = 208
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodClifk: TLabel [0]
    Left = 16
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Cliente'
  end
  object lblCodConvfk: TLabel [1]
    Left = 16
    Top = 152
    Width = 45
    Height = 13
    Caption = 'Conv'#234'nio'
  end
  object lblCodConvCli: TLabel [2]
    Left = 16
    Top = 56
    Width = 123
    Height = 13
    Caption = 'C'#243'digo do relacionamento'
  end
  inherited pnlBotoes: TPanel
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
  object fldCodConvfk: TDBLookupComboBox
    Left = 16
    Top = 168
    Width = 289
    Height = 21
    DataField = 'COD_CONV_FK'
    DataSource = dmBaseDados.dsConvCli
    KeyField = 'COD_CONV'
    ListField = 'COD_CONV;NOME_CONV;'
    ListFieldIndex = 1
    ListSource = dmBaseDados.dsConvenios
    TabOrder = 1
  end
  object fldCodClifk: TDBLookupComboBox
    Left = 16
    Top = 120
    Width = 289
    Height = 21
    DataField = 'COD_CLI_FK'
    DataSource = dmBaseDados.dsConvCli
    KeyField = 'COD_CLI'
    ListField = 'COD_CLI;NOME_CLI;'
    ListFieldIndex = 1
    ListSource = dmBaseDados.dsClientes
    TabOrder = 2
  end
  object fldCodConvCli: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    DataField = 'COD_CONVCLI'
    DataSource = dmBaseDados.dsConvCli
    Enabled = False
    TabOrder = 3
  end
end
