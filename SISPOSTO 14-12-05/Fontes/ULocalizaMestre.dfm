object formLocalizaMestre: TformLocalizaMestre
  Left = 192
  Top = 114
  BorderStyle = bsDialog
  Caption = 'Localiza'#231#227'o'
  ClientHeight = 278
  ClientWidth = 242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object lblMensagem: TLabel
    Left = 16
    Top = 8
    Width = 142
    Height = 13
    Caption = 'Digite a cadeia de caracteres:'
  end
  object edtValorPesquisa: TEdit
    Left = 16
    Top = 24
    Width = 209
    Height = 21
    TabOrder = 0
  end
  object grdDados: TDBGrid
    Left = 16
    Top = 56
    Width = 209
    Height = 169
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object btnOK: TBitBtn
    Left = 64
    Top = 240
    Width = 75
    Height = 25
    TabOrder = 2
    Kind = bkOK
  end
  object btnCancela: TBitBtn
    Left = 152
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Cancela'
    TabOrder = 3
    Kind = bkCancel
  end
end
