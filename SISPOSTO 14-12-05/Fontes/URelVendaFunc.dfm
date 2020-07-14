inherited formRelVendaFunc: TformRelVendaFunc
  Left = 241
  Top = 75
  Width = 375
  Caption = 'Venda por funcion'#225'rio'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 291
    Caption = 'Relat'#243'rio das vendas organizado por funcion'#225'rio'
  end
  inherited DBGrid1: TDBGrid
    Width = 545
    DataSource = dmBaseDados.dsVendaFunc
  end
end
