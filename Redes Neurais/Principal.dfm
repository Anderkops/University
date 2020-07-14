object Form1: TForm1
  Left = 190
  Top = 117
  Width = 864
  Height = 466
  Caption = 'Trabalho de Intelig'#234'ncia Artificial - Redes Neurais '
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 201
    Height = 129
    Caption = 'Neuronios da Rede Neural'
    TabOrder = 0
    object Label1: TLabel
      Left = 31
      Top = 28
      Width = 77
      Height = 13
      Caption = 'N'#243's de Entrada:'
    end
    object Label2: TLabel
      Left = 21
      Top = 60
      Width = 86
      Height = 13
      Caption = 'Camadas Ocultas:'
    end
    object Label4: TLabel
      Left = 41
      Top = 92
      Width = 65
      Height = 13
      Caption = 'N'#243's de saida:'
    end
    object Edit1: TEdit
      Left = 112
      Top = 28
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '6'
    end
    object Edit2: TEdit
      Left = 112
      Top = 60
      Width = 41
      Height = 21
      TabOrder = 1
      Text = '1'
      OnChange = Edit2Change
    end
    object Edit3: TEdit
      Left = 112
      Top = 92
      Width = 41
      Height = 21
      TabOrder = 2
      Text = '1'
    end
  end
  object GroupBox12: TGroupBox
    Left = 224
    Top = 8
    Width = 169
    Height = 129
    Caption = 'Fun'#231#227'o de Transferencia'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 24
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Linear'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 24
      Top = 56
      Width = 65
      Height = 17
      Caption = 'Logistica'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 24
      Top = 88
      Width = 121
      Height = 17
      Caption = 'Tangente Hiperb'#243'lica'
      TabOrder = 2
    end
  end
  object GroupBox9: TGroupBox
    Left = 8
    Top = 144
    Width = 385
    Height = 177
    Caption = 'Entrada'
    TabOrder = 2
    object StringGrid2: TStringGrid
      Left = 2
      Top = 15
      Width = 381
      Height = 160
      Align = alClient
      DefaultColWidth = 80
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
      TabOrder = 0
    end
  end
  object GroupBox8: TGroupBox
    Left = 448
    Top = 144
    Width = 121
    Height = 57
    Caption = 'Teste'
    TabOrder = 3
    object BotaoReconhecimento: TButton
      Left = 15
      Top = 17
      Width = 98
      Height = 26
      Caption = 'Executar Teste'
      TabOrder = 0
      OnClick = BotaoReconhecimentoClick
    end
  end
  object GroupBox6: TGroupBox
    Left = 8
    Top = 328
    Width = 169
    Height = 57
    Caption = 'Treinamento'
    TabOrder = 4
    object Button4: TButton
      Left = 16
      Top = 16
      Width = 129
      Height = 25
      Caption = 'Fazer Treinamento'
      Enabled = False
      TabOrder = 0
      OnClick = Button4Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 576
    Top = 144
    Width = 273
    Height = 177
    Caption = 'Matriz de Confus'#227'o'
    TabOrder = 5
    object StringGrid4: TStringGrid
      Left = 2
      Top = 15
      Width = 269
      Height = 160
      Align = alClient
      ColCount = 6
      DefaultColWidth = 80
      RowCount = 6
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
      TabOrder = 0
      ColWidths = (
        80
        34
        34
        33
        32
        32)
    end
  end
  object GroupBox10: TGroupBox
    Left = 448
    Top = 8
    Width = 401
    Height = 129
    Caption = 'Tabela de Teste'
    TabOrder = 6
    object StringGrid3: TStringGrid
      Left = 2
      Top = 15
      Width = 397
      Height = 112
      Align = alClient
      DefaultColWidth = 80
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing]
      TabOrder = 0
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 393
    Width = 856
    Height = 19
    Panels = <>
    ParentShowHint = False
    ShowHint = False
    SimplePanel = True
    SimpleText = 'Rede Neural'
  end
  object OpenDialog3: TOpenDialog
    Filter = 'All Files|*.*'
    Left = 152
    Top = 456
  end
  object OpenDialog4: TOpenDialog
    Filter = 'All Files|*.*'
    Left = 232
    Top = 456
  end
  object SaveDialog3: TSaveDialog
    Filter = 'All Files|*.*'
    Left = 192
    Top = 456
  end
  object MainMenu1: TMainMenu
    Left = 280
    Top = 456
    object Menu_Arquivo: TMenuItem
      Caption = 'Arquivo'
      object AbrirArquivoTreinamento1: TMenuItem
        Caption = '&Abrir Arquivo Treinamento'
        ShortCut = 112
        OnClick = AbrirArquivoTreinamento1Click
      end
      object AbrirArquivoTeste1: TMenuItem
        Caption = '&Abrir Arquivo Teste'
        ShortCut = 113
        OnClick = AbrirArquivoTeste1Click
      end
      object Sair1: TMenuItem
        Caption = '&Sair'
        ShortCut = 115
        OnClick = Sair1Click
      end
    end
  end
  object SaveDialog2: TSaveDialog
    Filter = 'All Files|*.*'
    Left = 320
    Top = 456
  end
  object OpenDialog1: TOpenDialog
    Filter = 'All Files|*.*'
    Left = 360
    Top = 456
  end
  object SaveDialog1: TSaveDialog
    Filter = 'All Files|*.*'
    Left = 400
    Top = 456
  end
end
