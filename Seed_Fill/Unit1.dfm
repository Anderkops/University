object form_Preenche: Tform_Preenche
  Left = 213
  Top = 132
  Width = 500
  Height = 384
  Caption = 'Seed Fill Algorithm - Vizinhan'#231'a 4 e Vizinhan'#231'a 8'
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
    Left = 8
    Top = 16
    Width = 300
    Height = 300
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
  end
  object lblX: TLabel
    Left = 344
    Top = 160
    Width = 14
    Height = 16
    Caption = 'X:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblY: TLabel
    Left = 344
    Top = 208
    Width = 15
    Height = 16
    Caption = 'Y:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblPosX: TLabel
    Left = 376
    Top = 160
    Width = 54
    Height = 16
    Caption = 'lblPosX'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblPosY: TLabel
    Left = 376
    Top = 208
    Width = 55
    Height = 16
    Caption = 'lblPosY'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object gpbPreenche: TGroupBox
    Left = 344
    Top = 16
    Width = 121
    Height = 105
    Caption = 'Preenchimento'
    TabOrder = 0
    object rdb_V4: TRadioButton
      Left = 16
      Top = 32
      Width = 89
      Height = 17
      Caption = 'Vizinhan'#231'a 4'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object rdb_V8: TRadioButton
      Left = 16
      Top = 64
      Width = 89
      Height = 17
      Caption = 'Vizinhan'#231'a 8'
      TabOrder = 1
    end
  end
end
