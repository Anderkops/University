inherited formRelEstoque: TformRelEstoque
  Left = 198
  Top = 49
  Width = 472
  Caption = 'Controle de estoque'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 211
    Caption = 'Relat'#243'rio para controle de estoque:'
  end
  inherited DBGrid1: TDBGrid
    Width = 745
    DataSource = dmBaseDados.dsEstoque
  end
end
