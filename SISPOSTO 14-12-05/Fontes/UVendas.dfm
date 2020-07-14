object formVenda: TformVenda
  Left = -1
  Top = -1
  Width = 812
  Height = 559
  Caption = 'Movimenta'#231#227'o de venda'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 16
    Top = 48
    Width = 96
    Height = 13
    Caption = 'C'#243'digo do vendedor'
  end
  object lblNomeFuncfk: TLabel
    Left = 160
    Top = 48
    Width = 91
    Height = 13
    Caption = 'Nome do vendedor'
  end
  object Label7: TLabel
    Left = 16
    Top = 88
    Width = 82
    Height = 13
    Caption = 'C'#243'digo do cliente'
  end
  object Label8: TLabel
    Left = 160
    Top = 88
    Width = 77
    Height = 13
    Caption = 'Nome do cliente'
  end
  object Label9: TLabel
    Left = 416
    Top = 480
    Width = 80
    Height = 13
    Caption = 'Total da listagem'
  end
  object DBText2: TDBText
    Left = 432
    Top = 504
    Width = 65
    Height = 17
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 528
    Top = 480
    Width = 46
    Height = 13
    Caption = 'Desconto'
  end
  object DBText3: TDBText
    Left = 512
    Top = 504
    Width = 65
    Height = 17
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 640
    Top = 480
    Width = 63
    Height = 13
    Caption = 'Valor a pagar'
  end
  object DBText4: TDBText
    Left = 594
    Top = 492
    Width = 119
    Height = 25
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -27
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 136
    Width = 95
    Height = 13
    Caption = 'C'#243'digo do conv'#234'nio'
  end
  object Label12: TLabel
    Left = 160
    Top = 136
    Width = 90
    Height = 13
    Caption = 'Nome do conv'#234'nio'
  end
  object Label13: TLabel
    Left = 16
    Top = 4
    Width = 81
    Height = 13
    Caption = 'C'#243'digo da venda'
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 264
    Width = 689
    Height = 161
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBLookupComboBox2: TDBLookupComboBox
    Left = 160
    Top = 64
    Width = 545
    Height = 21
    DataField = 'COD_FUNC_FK'
    DataSource = dmBaseDados.dsVendas
    KeyField = 'COD_FUNC'
    ListField = 'COD_FUNC;NOME_FUNC;'
    ListFieldIndex = 1
    ListSource = dmBaseDados.dsFuncionarios
    TabOrder = 1
  end
  object DBLookupComboBox3: TDBLookupComboBox
    Left = 160
    Top = 104
    Width = 545
    Height = 21
    DataField = 'COD_CLI_FK'
    DataSource = dmBaseDados.dsVendas
    KeyField = 'COD_CLI'
    ListField = 'COD_CLI;NOME_CLI;'
    ListFieldIndex = 1
    ListSource = dmBaseDados.dsClientes
    TabOrder = 2
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 184
    Width = 689
    Height = 65
    Caption = 'Itens do pedido'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 12
      Width = 87
      Height = 13
      Caption = 'C'#243'digo do produto'
    end
    object Label2: TLabel
      Left = 152
      Top = 12
      Width = 82
      Height = 13
      Caption = 'Nome do produto'
    end
    object Label5: TLabel
      Left = 448
      Top = 12
      Width = 55
      Height = 13
      Caption = 'Quantidade'
    end
    object Label6: TLabel
      Left = 592
      Top = 12
      Width = 24
      Height = 13
      Caption = 'Valor'
    end
    object DBText1: TDBText
      Left = 592
      Top = 32
      Width = 65
      Height = 17
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBEdit1: TDBEdit
      Left = 16
      Top = 28
      Width = 121
      Height = 21
      Enabled = False
      TabOrder = 0
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 152
      Top = 28
      Width = 281
      Height = 21
      DataField = 'COD_PROD_FK2'
      DataSource = dmBaseDados.dsItemVenda
      KeyField = 'COD_PROD'
      ListField = 'COD_PROD;NOME_PROD;'
      ListFieldIndex = 1
      ListSource = dmBaseDados.dsProdutos
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 448
      Top = 28
      Width = 121
      Height = 21
      DataField = 'QTDE_ITEM'
      DataSource = dmBaseDados.dsItemVenda
      TabOrder = 2
    end
  end
  object Panel1: TPanel
    Left = 16
    Top = 448
    Width = 387
    Height = 74
    AutoSize = True
    BevelInner = bvLowered
    TabOrder = 4
    object BitBtn2: TBitBtn
      Left = 2
      Top = 2
      Width = 95
      Height = 70
      Caption = 'Cancelar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -5
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object BitBtn1: TBitBtn
      Left = 98
      Top = 2
      Width = 95
      Height = 70
      Caption = 'Confirmar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -7
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object BitBtn3: TBitBtn
      Left = 194
      Top = 2
      Width = 95
      Height = 70
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object BitBtn4: TBitBtn
      Left = 290
      Top = 2
      Width = 95
      Height = 70
      Caption = 'Fechar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = BitBtn4Click
    end
  end
  object BitBtn5: TBitBtn
    Left = 568
    Top = 136
    Width = 139
    Height = 41
    Caption = 'Confirmar '#237'tem'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object DBLookupComboBox4: TDBLookupComboBox
    Left = 160
    Top = 152
    Width = 385
    Height = 21
    DataField = 'COD_CONV_FK'
    DataSource = dmBaseDados.dsVendas
    KeyField = 'COD_CONV'
    ListField = 'COD_CONV;NOME_CONV;'
    ListFieldIndex = 1
    ListSource = dmBaseDados.dsConvenios
    TabOrder = 6
  end
  object DBEdit2: TDBEdit
    Left = 16
    Top = 20
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 7
  end
  object DBEdit4: TDBEdit
    Left = 16
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object DBEdit5: TDBEdit
    Left = 16
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object DBEdit6: TDBEdit
    Left = 16
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 10
  end
end
