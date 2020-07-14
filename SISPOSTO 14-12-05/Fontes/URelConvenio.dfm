inherited formRelConvenio: TformRelConvenio
  Left = 209
  Top = 94
  Height = 567
  Caption = 'Relat'#243'rio completo dos conv'#234'nios'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 206
    Caption = 'Relat'#243'rio com dados do conv'#234'nio:'
  end
  inherited DBGrid1: TDBGrid
    Width = 657
    DataSource = dmBaseDados.dsConvenios
  end
end
