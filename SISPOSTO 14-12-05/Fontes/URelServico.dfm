inherited formRelServico: TformRelServico
  Caption = 'Relat'#243'rio completo dos servi'#231'os'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 138
    Caption = 'Relat'#243'rio dos servi'#231'os:'
  end
  inherited DBGrid1: TDBGrid
    DataSource = dmBaseDados.dsServicos
  end
end
