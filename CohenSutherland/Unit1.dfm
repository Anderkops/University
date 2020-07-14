object Janela: TJanela
  Left = 217
  Top = 109
  Width = 546
  Height = 624
  Caption = 'Alboritmo de recorte bidimensional de Cohen Sutherland'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 17
    Top = 17
    Width = 500
    Height = 400
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Label15: TLabel
    Left = 32
    Top = 432
    Width = 36
    Height = 13
    Caption = 'X atual:'
  end
  object Label16: TLabel
    Left = 160
    Top = 432
    Width = 36
    Height = 13
    Caption = 'Y atual:'
  end
  object lblXatual: TLabel
    Left = 72
    Top = 432
    Width = 5
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblYatual: TLabel
    Left = 200
    Top = 432
    Width = 5
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 456
    Width = 225
    Height = 105
    Caption = 'Ponto 1:'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 16
      Height = 13
      Caption = 'X1:'
    end
    object Label2: TLabel
      Left = 120
      Top = 24
      Width = 16
      Height = 13
      Caption = 'Y1:'
    end
    object Label3: TLabel
      Left = 16
      Top = 72
      Width = 36
      Height = 13
      Caption = 'C'#243'digo:'
    end
    object Label4: TLabel
      Left = 64
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P1'
    end
    object Label5: TLabel
      Left = 144
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P3'
    end
    object Label6: TLabel
      Left = 104
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P2'
    end
    object Label7: TLabel
      Left = 184
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P4'
    end
    object edtP1X: TEdit
      Left = 56
      Top = 20
      Width = 41
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
    object edtP1Y: TEdit
      Left = 160
      Top = 20
      Width = 41
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object edtP1C1: TEdit
      Left = 56
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
    object edtP1C2: TEdit
      Left = 96
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 3
    end
    object edtP1C3: TEdit
      Left = 136
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 4
    end
    object edtP1C4: TEdit
      Left = 176
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 5
    end
  end
  object GroupBox2: TGroupBox
    Left = 288
    Top = 456
    Width = 225
    Height = 105
    Caption = 'Ponto 2:'
    TabOrder = 1
    object Label8: TLabel
      Left = 120
      Top = 24
      Width = 16
      Height = 13
      Caption = 'Y2:'
    end
    object Label9: TLabel
      Left = 16
      Top = 24
      Width = 16
      Height = 13
      Caption = 'X2:'
    end
    object Label10: TLabel
      Left = 16
      Top = 72
      Width = 36
      Height = 13
      Caption = 'C'#243'digo:'
    end
    object Label11: TLabel
      Left = 64
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P1'
    end
    object Label12: TLabel
      Left = 104
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P2'
    end
    object Label13: TLabel
      Left = 144
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P3'
    end
    object Label14: TLabel
      Left = 184
      Top = 48
      Width = 13
      Height = 13
      Caption = 'P4'
    end
    object edtP2X: TEdit
      Left = 56
      Top = 20
      Width = 41
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
    object edtP2Y: TEdit
      Left = 160
      Top = 20
      Width = 41
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object edtP2C1: TEdit
      Left = 56
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
    object edtP2C2: TEdit
      Left = 96
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 3
    end
    object edtP2C3: TEdit
      Left = 136
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 4
    end
    object edtP2C4: TEdit
      Left = 176
      Top = 68
      Width = 33
      Height = 21
      ReadOnly = True
      TabOrder = 5
    end
  end
end
