inherited formCadastroBombas: TformCadastroBombas
  Left = 220
  Top = 200
  Caption = 'Cadastro de bombas'
  ClientHeight = 149
  ClientWidth = 354
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodBom: TLabel [0]
    Left = 16
    Top = 56
    Width = 83
    Height = 13
    Caption = 'C'#243'digo da bomba'
  end
  object lblCodTan: TLabel [1]
    Left = 144
    Top = 56
    Width = 84
    Height = 13
    Caption = 'C'#243'digo do tanque'
  end
  object lblLeituraBom: TLabel [2]
    Left = 240
    Top = 56
    Width = 32
    Height = 13
    Caption = 'Leitura'
  end
  object lblDataleitBom: TLabel [3]
    Left = 16
    Top = 96
    Width = 69
    Height = 13
    Caption = 'Data da leitura'
  end
  object lblHoraleitBom: TLabel [4]
    Left = 192
    Top = 96
    Width = 80
    Height = 13
    Caption = 'Horario da leitura'
  end
  inherited pnlBotoes: TPanel
    Width = 354
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
  object fldCodBom: TDBEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    DataField = 'COD_BOM'
    DataSource = dmBaseDados.dsBombas
    Enabled = False
    TabOrder = 1
  end
  object fldLeituraBom: TDBEdit
    Left = 240
    Top = 72
    Width = 97
    Height = 21
    DataField = 'LEITURA_BOM'
    DataSource = dmBaseDados.dsBombas
    TabOrder = 2
  end
  object fldDataleitBom: TDBEdit
    Left = 16
    Top = 112
    Width = 161
    Height = 21
    DataField = 'DATALEIT_BOM'
    DataSource = dmBaseDados.dsBombas
    MaxLength = 10
    TabOrder = 3
  end
  object fldHoraleitBom: TDBEdit
    Left = 192
    Top = 112
    Width = 145
    Height = 21
    DataField = 'HORALEIT_BOM'
    DataSource = dmBaseDados.dsBombas
    MaxLength = 5
    TabOrder = 4
  end
  object fldCodTanfk: TDBLookupComboBox
    Left = 144
    Top = 72
    Width = 89
    Height = 21
    DataField = 'COD_TAN_FK'
    DataSource = dmBaseDados.dsBombas
    DropDownRows = 20
    KeyField = 'COD_TAN'
    ListField = 'COD_TAN'
    ListSource = dmBaseDados.dsTanques
    TabOrder = 5
  end
end
