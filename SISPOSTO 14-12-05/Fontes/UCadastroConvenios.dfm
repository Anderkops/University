inherited formCadastroConvenios: TformCadastroConvenios
  Left = 209
  Top = 182
  Caption = 'Cadastro de conv'#234'nios'
  ClientHeight = 140
  ClientWidth = 411
  OldCreateOrder = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCodConv: TLabel [0]
    Left = 16
    Top = 48
    Width = 95
    Height = 13
    Caption = 'C'#243'digo do conv'#234'nio'
  end
  object lblNomeConv: TLabel [1]
    Left = 144
    Top = 48
    Width = 90
    Height = 13
    Caption = 'Nome do conv'#234'nio'
  end
  object lblDescvistaConv: TLabel [2]
    Left = 16
    Top = 88
    Width = 80
    Height = 13
    Caption = 'Desconto '#224' vista'
  end
  object lblDescprazoConv: TLabel [3]
    Left = 144
    Top = 88
    Width = 84
    Height = 13
    Caption = 'Desconto '#224' prazo'
  end
  object lblComissaoConv: TLabel [4]
    Left = 272
    Top = 88
    Width = 45
    Height = 13
    Caption = 'Comiss'#227'o'
  end
  inherited pnlBotoes: TPanel
    Width = 411
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
  object fldCodConv: TDBEdit
    Left = 16
    Top = 64
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COD_CONV'
    DataSource = dmBaseDados.dsConvenios
    Enabled = False
    TabOrder = 1
  end
  object fldNomeConv: TDBEdit
    Left = 144
    Top = 64
    Width = 249
    Height = 21
    AutoSize = False
    DataField = 'NOME_CONV'
    DataSource = dmBaseDados.dsConvenios
    TabOrder = 2
  end
  object fldDescvistaConv: TDBEdit
    Left = 16
    Top = 104
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'DESCVISTA_CONV'
    DataSource = dmBaseDados.dsConvenios
    TabOrder = 3
  end
  object fldDescprazoConv: TDBEdit
    Left = 144
    Top = 104
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'DESCPRAZO_CONV'
    DataSource = dmBaseDados.dsConvenios
    TabOrder = 4
  end
  object fldComissaoConv: TDBEdit
    Left = 272
    Top = 104
    Width = 121
    Height = 21
    AutoSize = False
    DataField = 'COMISSAO_CONV'
    DataSource = dmBaseDados.dsConvenios
    TabOrder = 5
  end
end
