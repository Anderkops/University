inherited formLocalizaConvenio: TformLocalizaConvenio
  Left = 441
  Top = 153
  Caption = 'Localiza'#231#227'o de conv'#234'nio'
  ClientWidth = 321
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited lblMensagem: TLabel
    Width = 130
    Caption = 'Digite o nome do conv'#234'nio:'
  end
  inherited edtValorPesquisa: TEdit
    CharCase = ecNormal
    MaxLength = 40
    OnKeyUp = edtValorPesquisaKeyUp
  end
  inherited grdDados: TDBGrid
    Width = 281
    DataSource = dmBaseDados.dsConvenios
    Columns = <
      item
        Expanded = False
        FieldName = 'NOME_CONV'
        Title.Alignment = taCenter
        Title.Caption = 'Nome do conv'#234'nio'
        Visible = True
      end>
  end
end
