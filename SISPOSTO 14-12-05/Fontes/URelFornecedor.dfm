inherited formRelFornecedor: TformRelFornecedor
  Left = 288
  Top = 12
  Caption = 'Relat'#243'rio completo dos fornecedores'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 231
    Caption = 'Relat'#243'rio com dados do fornecedores:'
  end
  inherited DBGrid1: TDBGrid
    DataSource = dmBaseDados.dsFornecedores
  end
end