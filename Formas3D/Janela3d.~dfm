object Principal: TPrincipal
  Left = 153
  Top = 118
  Width = 624
  Height = 608
  Caption = 'Objetos 3D utilizando Z-buffer'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 616
    Height = 574
    Align = alClient
    BevelInner = bvLowered
    Color = clMoneyGreen
    TabOrder = 0
    object imgGrafico: TImage
      Left = 144
      Top = 92
      Width = 447
      Height = 463
    end
    object GroupBox2: TGroupBox
      Left = 16
      Top = 256
      Width = 113
      Height = 153
      Caption = 'Escala'
      Color = clSilver
      ParentColor = False
      TabOrder = 0
      object lbl_eixoX_esc: TLabel
        Left = 8
        Top = 32
        Width = 30
        Height = 13
        Caption = 'Eixo X'
      end
      object lbl_eixoY_esc: TLabel
        Left = 8
        Top = 56
        Width = 30
        Height = 13
        Caption = 'Eixo Y'
      end
      object lbl_eixoZ_esc: TLabel
        Left = 8
        Top = 80
        Width = 30
        Height = 13
        Caption = 'Eixo Z'
      end
      object edt_eixoX_esc: TEdit
        Left = 48
        Top = 32
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '1'
      end
      object edt_eixoY_esc: TEdit
        Left = 48
        Top = 56
        Width = 49
        Height = 21
        TabOrder = 1
        Text = '1'
      end
      object edt_eixoZ_esc: TEdit
        Left = 48
        Top = 80
        Width = 49
        Height = 21
        TabOrder = 2
        Text = '1'
      end
      object btn_Esc: TButton
        Left = 16
        Top = 112
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnClick = btn_EscClick
      end
    end
    object rdgRotacao: TGroupBox
      Left = 16
      Top = 416
      Width = 113
      Height = 137
      Caption = 'Rota'#231#227'o'
      Color = clSilver
      ParentColor = False
      TabOrder = 1
      object rdb_eixoX_rot: TRadioButton
        Left = 16
        Top = 24
        Width = 73
        Height = 17
        Caption = 'Eixo X'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rdb_eixoY_rot: TRadioButton
        Left = 16
        Top = 48
        Width = 65
        Height = 17
        Caption = 'Eixo Y'
        TabOrder = 1
      end
      object rdb_eixoZ_rot: TRadioButton
        Left = 16
        Top = 72
        Width = 65
        Height = 17
        Caption = 'Eixo Z'
        TabOrder = 2
      end
      object btn_rot: TButton
        Left = 16
        Top = 96
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnMouseDown = btn_rotMouseDown
      end
    end
    object GroupBox1: TGroupBox
      Left = 16
      Top = 88
      Width = 113
      Height = 153
      Caption = 'Transla'#231#227'o'
      Color = clSilver
      ParentColor = False
      TabOrder = 2
      object lbl_eixoX_trans: TLabel
        Left = 8
        Top = 32
        Width = 30
        Height = 13
        Caption = 'Eixo X'
      end
      object lbl_eixoY_trans: TLabel
        Left = 8
        Top = 56
        Width = 30
        Height = 13
        Caption = 'Eixo Y'
      end
      object lbl_eixoZ_trans: TLabel
        Left = 8
        Top = 80
        Width = 30
        Height = 13
        Caption = 'Eixo Z'
      end
      object edt_eixoX_trans: TEdit
        Left = 48
        Top = 32
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '0'
      end
      object edt_eixoY_trans: TEdit
        Left = 48
        Top = 56
        Width = 49
        Height = 21
        TabOrder = 1
        Text = '0'
      end
      object edt_eixoZ_trans: TEdit
        Left = 48
        Top = 80
        Width = 49
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object btn_trans: TButton
        Left = 16
        Top = 112
        Width = 75
        Height = 25
        Caption = 'Executar'
        TabOrder = 3
        OnClick = btn_transClick
      end
    end
    object GroupBox6: TGroupBox
      Left = 144
      Top = 8
      Width = 449
      Height = 73
      Caption = 'Objeto'
      Color = clSilver
      ParentColor = False
      TabOrder = 3
      object rdb_Cubo: TRadioButton
        Left = 16
        Top = 16
        Width = 113
        Height = 17
        Caption = 'Cubo'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = rdb_CuboClick
      end
      object rdb_Esfera: TRadioButton
        Left = 192
        Top = 16
        Width = 113
        Height = 17
        Caption = 'Esfera'
        TabOrder = 1
        OnClick = rdb_EsferaClick
      end
      object rdb_Cone: TRadioButton
        Left = 328
        Top = 16
        Width = 113
        Height = 17
        Caption = 'Cone'
        TabOrder = 2
        OnClick = rdb_ConeClick
      end
      object rdb_Cilindro: TRadioButton
        Left = 16
        Top = 40
        Width = 113
        Height = 17
        Caption = 'Cilindro'
        TabOrder = 3
        OnClick = rdb_CilindroClick
      end
      object rdb_Plano: TRadioButton
        Left = 192
        Top = 40
        Width = 113
        Height = 17
        Caption = 'Plano'
        TabOrder = 4
        OnClick = rdb_PlanoClick
      end
      object rdb_Superficie: TRadioButton
        Left = 328
        Top = 40
        Width = 113
        Height = 17
        Caption = 'Superf'#237'cie'
        TabOrder = 5
        OnClick = rdb_SuperficieClick
      end
    end
  end
end
