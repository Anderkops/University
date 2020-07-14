inherited formLocalizaCliente: TformLocalizaCliente
  Left = 243
  Top = 233
  Caption = 'Localiza'#231#227'o de cliente'
  ClientWidth = 316
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited lblMensagem: TLabel
    Width = 117
    Caption = 'Digite o nome do cliente:'
  end
  inherited edtValorPesquisa: TEdit
    Width = 281
    CharCase = ecNormal
    MaxLength = 40
    OnKeyUp = edtValorPesquisaKeyUp
  end
  inherited grdDados: TDBGrid
    Width = 281
    DataSource = dmBaseDados.dsClientes
    Columns = <
      item
        Expanded = False
        FieldName = 'NOME_CLI'
        Title.Alignment = taCenter
        Title.Caption = 'Nome do cliente'
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
