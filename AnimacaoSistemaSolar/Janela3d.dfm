object Principal: TPrincipal
  Left = 98
  Top = 119
  Width = 494
  Height = 567
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
    Width = 486
    Height = 533
    Align = alClient
    BevelInner = bvLowered
    Color = clMoneyGreen
    TabOrder = 0
    object imgGrafico: TImage
      Left = 16
      Top = 52
      Width = 447
      Height = 463
    end
    object Button1: TButton
      Left = 16
      Top = 24
      Width = 113
      Height = 25
      Caption = 'Pr'#243'ximo frame'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
end