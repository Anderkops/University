inherited formRelFuncionario: TformRelFuncionario
  Left = 176
  Top = 28
  Caption = 'Relat'#243'rio completo dos funcion'#225'rios'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 216
    Caption = 'Relat'#243'rio com dados do funcion'#225'rio:'
  end
  inherited DBGrid1: TDBGrid
    DataSource = dmBaseDados.dsFuncionarios
  end
end
