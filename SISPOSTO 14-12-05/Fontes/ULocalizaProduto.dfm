inherited formLocalizaProduto: TformLocalizaProduto
  Caption = 'Localiza'#231#227'o de produto'
  ClientWidth = 313
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited lblMensagem: TLabel
    Width = 122
    Caption = 'Digite o nome do produto:'
  end
  inherited edtValorPesquisa: TEdit
    Width = 281
    CharCase = ecNormal
    MaxLength = 40
    OnKeyUp = edtValorPesquisaKeyUp
  end
  inherited grdDados: TDBGrid
    Width = 281
    DataSource = dmBaseDados.dsProdutos
    Columns = <
      item
        Expanded = False
        FieldName = 'NOME_PROD'
        Title.Alignment = taCenter
        Title.Caption = 'Nome do produto'
        Visible = True
      end>
  end
  inherited btnOK: TBitBtn
    Left = 136
  end
  inherited btnCancela: TBitBtn
    Left = 224
  end
end
