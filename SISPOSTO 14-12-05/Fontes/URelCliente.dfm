inherited formRelCliente: TformRelCliente
  Left = 167
  Top = 156
  Caption = 'Relat'#243'rio completo dos clientes'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 190
    Caption = 'Relat'#243'rio com dados do cliente:'
  end
  inherited DBGrid1: TDBGrid
    DataSource = dmBaseDados.dsClientes
  end
end