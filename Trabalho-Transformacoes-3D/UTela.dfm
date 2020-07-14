object formTela: TformTela
  Left = 232
  Top = 125
  Width = 728
  Height = 543
  Caption = 'formTela'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = menu
  OldCreateOrder = False
  OnCreate = FormCreate
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 720
    Height = 489
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 0
    object pnlGrafico: TPanel
      Left = 8
      Top = 8
      Width = 449
      Height = 465
      Color = clWhite
      TabOrder = 0
      object imgGrafico: TImage
        Left = 1
        Top = 1
        Width = 447
        Height = 463
        Align = alClient
      end
    end
    object GroupBox2: TGroupBox
      Left = 592
      Top = 8
      Width = 113
      Height = 153
      Caption = 'Escala'
      TabOrder = 1
      object Label4: TLabel
        Left = 8
        Top = 32
        Width = 30
        Height = 13
        Caption = 'Eixo X'
      end
      object Label5: TLabel
        Left = 8
        Top = 56
        Width = 30
        Height = 13
        Caption = 'Eixo Y'
      end
      object Label6: TLabel
        Left = 8
        Top = 80
        Width = 30
        Height = 13
        Caption = 'Eixo Z'
      end
      object edtEscX: TEdit
        Left = 48
        Top = 32
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '5'
      end
      object edtEscY: TEdit
        Left = 48
        Top = 56
        Width = 49
        Height = 21
        TabOrder = 1
        Text = '5'
      end
      object edtEscZ: TEdit
        Left = 48
        Top = 80
        Width = 49
        Height = 21
        TabOrder = 2
        Text = '5'
      end
      object btnEscala: TButton
        Left = 16
        Top = 112
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnClick = btnEscalaClick
      end
    end
    object rdgRotacao: TGroupBox
      Left = 472
      Top = 168
      Width = 113
      Height = 137
      Caption = 'Rotação'
      TabOrder = 2
      object rdbEixoX: TRadioButton
        Left = 16
        Top = 24
        Width = 73
        Height = 17
        Caption = 'Eixo X'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rdbEixoY: TRadioButton
        Left = 16
        Top = 48
        Width = 65
        Height = 17
        Caption = 'Eixo Y'
        TabOrder = 1
      end
      object rdbEixoZ: TRadioButton
        Left = 16
        Top = 72
        Width = 65
        Height = 17
        Caption = 'Eixo Z'
        TabOrder = 2
      end
      object btnRotacao: TButton
        Left = 16
        Top = 96
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnMouseDown = btnRotacaoMouseDown
      end
    end
    object GroupBox1: TGroupBox
      Left = 472
      Top = 8
      Width = 113
      Height = 153
      Caption = 'Translação'
      TabOrder = 3
      object Label1: TLabel
        Left = 8
        Top = 32
        Width = 30
        Height = 13
        Caption = 'Eixo X'
      end
      object Label2: TLabel
        Left = 8
        Top = 56
        Width = 30
        Height = 13
        Caption = 'Eixo Y'
      end
      object Label3: TLabel
        Left = 8
        Top = 80
        Width = 30
        Height = 13
        Caption = 'Eixo Z'
      end
      object edtX: TEdit
        Left = 48
        Top = 32
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '-20'
      end
      object edtY: TEdit
        Left = 48
        Top = 56
        Width = 49
        Height = 21
        TabOrder = 1
        Text = '-25'
      end
      object edtZ: TEdit
        Left = 48
        Top = 80
        Width = 49
        Height = 21
        TabOrder = 2
        Text = '-15'
      end
      object Button1: TButton
        Left = 16
        Top = 112
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnClick = Button1Click
      end
    end
    object GroupBox3: TGroupBox
      Left = 592
      Top = 168
      Width = 113
      Height = 81
      Caption = 'Projeção'
      TabOrder = 4
      object rdbParalela: TRadioButton
        Left = 16
        Top = 24
        Width = 65
        Height = 17
        Caption = 'Paralela'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = rdbParalelaClick
      end
      object rdbCavaleira: TRadioButton
        Left = 16
        Top = 48
        Width = 73
        Height = 17
        Caption = 'Cavaleira'
        TabOrder = 1
        OnClick = rdbCavaleiraClick
      end
    end
    object GroupBox4: TGroupBox
      Left = 472
      Top = 328
      Width = 233
      Height = 145
      Caption = 'Shearing'
      TabOrder = 5
      object edtShr00: TEdit
        Left = 8
        Top = 24
        Width = 57
        Height = 21
        Color = clBtnFace
        ReadOnly = True
        TabOrder = 0
        Text = '1'
      end
      object edtShr01: TEdit
        Left = 80
        Top = 24
        Width = 57
        Height = 21
        TabOrder = 1
        Text = '-0,85'
      end
      object edtShr02: TEdit
        Left = 160
        Top = 24
        Width = 57
        Height = 21
        TabOrder = 2
        Text = '0,25'
      end
      object edtShr10: TEdit
        Left = 8
        Top = 56
        Width = 57
        Height = 21
        TabOrder = 3
        Text = '-0,75'
      end
      object edtShr11: TEdit
        Left = 80
        Top = 56
        Width = 57
        Height = 21
        Color = clBtnFace
        ReadOnly = True
        TabOrder = 4
        Text = '1'
      end
      object edtShr12: TEdit
        Left = 160
        Top = 56
        Width = 57
        Height = 21
        TabOrder = 5
        Text = '0,7'
      end
      object edtShr20: TEdit
        Left = 8
        Top = 88
        Width = 57
        Height = 21
        TabOrder = 6
        Text = '0,5'
      end
      object edtShr21: TEdit
        Left = 80
        Top = 88
        Width = 57
        Height = 21
        TabOrder = 7
        Text = '1,0'
      end
      object edtShr22: TEdit
        Left = 160
        Top = 88
        Width = 57
        Height = 21
        Color = clBtnFace
        ReadOnly = True
        TabOrder = 8
        Text = '1'
      end
      object rdbSherAplicar: TRadioButton
        Left = 24
        Top = 120
        Width = 89
        Height = 17
        Caption = 'Aplicar'
        TabOrder = 9
        OnClick = rdbSherAplicarClick
      end
      object RadioButton2: TRadioButton
        Left = 120
        Top = 120
        Width = 89
        Height = 17
        Caption = 'ignorar'
        Checked = True
        TabOrder = 10
        TabStop = True
        OnClick = rdbSherAplicarClick
      end
    end
    object GroupBox5: TGroupBox
      Left = 592
      Top = 248
      Width = 113
      Height = 81
      Caption = 'Reflexão'
      TabOrder = 6
      object rdbRefXY: TRadioButton
        Left = 8
        Top = 24
        Width = 41
        Height = 17
        Caption = 'XY'
        TabOrder = 0
        OnClick = rdbRefXYClick
      end
      object rdbRefXZ: TRadioButton
        Left = 56
        Top = 24
        Width = 41
        Height = 17
        Caption = 'XZ'
        TabOrder = 1
        OnClick = rdbRefXYClick
      end
      object rdbRefYZ: TRadioButton
        Left = 8
        Top = 48
        Width = 41
        Height = 17
        Caption = 'YZ'
        TabOrder = 2
        OnClick = rdbRefXYClick
      end
      object rdbRefSem: TRadioButton
        Left = 56
        Top = 48
        Width = 41
        Height = 17
        Caption = 'Sem'
        Checked = True
        TabOrder = 3
        TabStop = True
        OnClick = rdbRefXYClick
      end
    end
  end
  object menu: TMainMenu
    Left = 352
    Top = 56
    object Abri1: TMenuItem
      Caption = '&Abrir'
      object Sair1: TMenuItem
        Caption = 'Sair'
      end
    end
  end
end
