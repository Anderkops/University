object FormPrincipal: TFormPrincipal
  Left = 277
  Top = 143
  Width = 786
  Height = 638
  Caption = 'CompiladorZin'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 8
    Top = 432
    Width = 39
    Height = 13
    Caption = 'Diret'#243'rio'
  end
  object pnl_Texto: TGroupBox
    Left = 8
    Top = 8
    Width = 257
    Height = 257
    Caption = 'C'#243'digo'
    TabOrder = 0
    object Texto: TRichEdit
      Left = 8
      Top = 16
      Width = 241
      Height = 233
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object pnl_Buffer: TGroupBox
    Left = 272
    Top = 8
    Width = 241
    Height = 257
    Caption = 'Buffer'
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 37
      Height = 13
      Caption = 'Buffer 1'
    end
    object Label2: TLabel
      Left = 8
      Top = 132
      Width = 37
      Height = 13
      Caption = 'Buffer 2'
    end
    object Rich_buffer1: TRichEdit
      Left = 8
      Top = 32
      Width = 217
      Height = 89
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      HideSelection = False
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
    end
    object Rich_buffer2: TRichEdit
      Left = 8
      Top = 147
      Width = 217
      Height = 94
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      HideSelection = False
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 1
    end
  end
  object pnl_Tabela_Simbolo: TGroupBox
    Left = 8
    Top = 272
    Width = 257
    Height = 153
    Caption = 'Tabela de S'#237'mbolos'
    TabOrder = 2
    object Rich_Tabela_Simbolo: TRichEdit
      Left = 8
      Top = 16
      Width = 241
      Height = 129
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object pnl_Propriedades: TGroupBox
    Left = 272
    Top = 272
    Width = 241
    Height = 153
    Caption = 'Propriedades'
    TabOrder = 3
    object lbledt_Lexema: TLabeledEdit
      Left = 8
      Top = 32
      Width = 217
      Height = 21
      EditLabel.Width = 40
      EditLabel.Height = 13
      EditLabel.Caption = 'Lexema:'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object lbledt_Pos_Tabela: TLabeledEdit
      Left = 8
      Top = 72
      Width = 217
      Height = 21
      EditLabel.Width = 92
      EditLabel.Height = 13
      EditLabel.Caption = 'Posi'#231#227'o na Tabela:'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 1
    end
    object lbledt_Token: TLabeledEdit
      Left = 8
      Top = 112
      Width = 217
      Height = 21
      EditLabel.Width = 34
      EditLabel.Height = 13
      EditLabel.Caption = 'Token:'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 2
    end
  end
  object pnl_Lista_Gerada: TGroupBox
    Left = 520
    Top = 8
    Width = 251
    Height = 462
    Caption = 'Lista Gerada'
    TabOrder = 4
    object strgrd_Lista_Gerada: TStringGrid
      Left = 8
      Top = 16
      Width = 235
      Height = 439
      ColCount = 2
      DefaultColWidth = 105
      DefaultRowHeight = 21
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      TabOrder = 0
    end
  end
  object Mensagens: TStringGrid
    Left = 8
    Top = 480
    Width = 505
    Height = 89
    ColCount = 3
    DefaultRowHeight = 19
    FixedColor = clMoneyGreen
    FixedCols = 0
    ScrollBars = ssVertical
    TabOrder = 5
    ColWidths = (
      47
      47
      382)
  end
  object edt_Diretorio: TEdit
    Left = 8
    Top = 448
    Width = 505
    Height = 21
    Enabled = False
    TabOrder = 6
  end
  object Menu1: TMainMenu
    Left = 792
    Top = 16
    object Arquivo: TMenuItem
      Caption = '&Arquivo'
      object Abrir1: TMenuItem
        Caption = '&Abrir'
        ShortCut = 112
        OnClick = Abrir1Click
      end
      object Fechar1: TMenuItem
        Caption = '&Fechar'
        Enabled = False
        ShortCut = 113
        OnClick = Fechar1Click
      end
      object Sair1: TMenuItem
        Caption = '&Sair'
        ShortCut = 115
        OnClick = Sair1Click
      end
    end
    object Anlise1: TMenuItem
      Caption = '&An'#225'lise'
      object Lexica1: TMenuItem
        Caption = '&L'#233'xica'
        Checked = True
        OnClick = Lexica1Click
      end
      object Sintatica1: TMenuItem
        Caption = '&Sint'#225'tica'
        OnClick = Sintatica1Click
      end
    end
    object Executar1: TMenuItem
      Caption = '&Executar'
      object NextToken1: TMenuItem
        Caption = '&Next Token'
        Enabled = False
        ShortCut = 119
        OnClick = NextToken1Click
      end
      object AnaliseSintatica: TMenuItem
        Caption = '&An'#225'lise Sint'#225'tica'
        Enabled = False
        ShortCut = 120
        OnClick = AnaliseSintaticaClick
      end
      object AtualizarTabela: TMenuItem
        Caption = 'Atualizar Tabela de Simbolo'
        Enabled = False
        ShortCut = 121
        OnClick = AtualizarTabelaClick
      end
    end
    object Ajuda1: TMenuItem
      Caption = '&Ajuda'
      object SobreCompiladorZin1: TMenuItem
        Caption = 'Sobre CompiladorZin'
        OnClick = SobreCompiladorZin1Click
      end
      object GuiaParaExecutarumarquivoPascal1: TMenuItem
        Caption = 'Guia Para Executar um arquivo Pascal'
        OnClick = GuiaParaExecutarumarquivoPascal1Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    InitialDir = 'exemplos'
    Left = 792
    Top = 64
  end
end
