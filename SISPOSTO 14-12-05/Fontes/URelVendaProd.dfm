inherited formRelVendaProd: TformRelVendaProd
  Left = 102
  Top = 60
  Caption = 'Quantidade vendida por produto'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 279
    Caption = 'Relat'#243'rio para controle de vendas por produto:'
  end
  inherited DBGrid1: TDBGrid
    Width = 473
    DataSource = dmBaseDados.dsVendaProd
  end
end
