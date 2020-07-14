inherited formRelProduto: TformRelProduto
  Left = 208
  Top = 108
  Caption = 'Relat'#243'rio completo dos produtos'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 140
    Caption = 'Relat'#243'rio dos produtos:'
  end
  inherited DBGrid1: TDBGrid
    DataSource = dmBaseDados.dsSoProd
  end
end
