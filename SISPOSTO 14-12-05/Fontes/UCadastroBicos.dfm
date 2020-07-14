inherited formCadastroBicos: TformCadastroBicos
  Left = 205
  Top = 156
  Caption = 'Cadastro de bicos'
  ClientHeight = 106
  ClientWidth = 321
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodBic: TLabel [0]
    Left = 16
    Top = 56
    Width = 71
    Height = 13
    Caption = 'C'#243'digo do bico'
  end
  object lblCodBomfk: TLabel [1]
    Left = 152
    Top = 56
    Width = 91
    Height = 13
    Caption = 'Bomba relacionada'
  end
  inherited pnlBotoes: TPanel
    Width = 321
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
  object fldCodBic: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COD_BIC'
    DataSource = dmBaseDados.dsBicos
    Enabled = False
    TabOrder = 1
  end
  object fldCodBomfk: TDBLookupComboBox
    Left = 152
    Top = 72
    Width = 153
    Height = 21
    DataField = 'COD_BOM_FK'
    DataSource = dmBaseDados.dsBicos
    DropDownRows = 20
    KeyField = 'COD_BOM'
    ListField = 'COD_BOM'
    ListSource = dmBaseDados.dsBombas
    TabOrder = 2
  end
end
