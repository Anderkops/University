object formPrincipal: TformPrincipal
  Left = 199
  Top = 114
  Width = 301
  Height = 97
  Caption = 'SisPosto - Sistema de Gerenciamento de Posto de Combust'#237'vel'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 256
    Top = 8
    object Arquivos1: TMenuItem
      Caption = 'Arquivos'
      object Cadastro1: TMenuItem
        Caption = 'Cadastro'
        object Clientes1: TMenuItem
          Caption = 'Clientes'
          OnClick = Clientes1Click
        end
        object Fornecedores1: TMenuItem
          Caption = 'Conv'#234'nios'
          OnClick = Fornecedores1Click
        end
        object Fornecedores2: TMenuItem
          Caption = 'Fornecedores'
          OnClick = Fornecedores2Click
        end
        object Funcionrios1: TMenuItem
          Caption = 'Funcion'#225'rios'
          OnClick = Funcionrios1Click
        end
        object Produtos1: TMenuItem
          Caption = 'Produtos'
          OnClick = Produtos1Click
        end
        object N2: TMenuItem
          Caption = '-'
        end
        object Bicos1: TMenuItem
          Caption = 'Bicos'
          OnClick = Bicos1Click
        end
        object Bombas1: TMenuItem
          Caption = 'Bombas'
          OnClick = Bombas1Click
        end
        object Tanques1: TMenuItem
          Caption = 'Tanques'
          OnClick = Tanques1Click
        end
      end
      object Relacionarconvenio1: TMenuItem
        Caption = 'Relacionar cliente/convenio'
        OnClick = Relacionarconvenio1Click
      end
      object Usurio1: TMenuItem
        Caption = 'Usu'#225'rio'
        object Trocadeusurio1: TMenuItem
          Caption = 'Troca de usu'#225'rio'
          OnClick = Trocadeusurio1Click
        end
        object Criarusurio1: TMenuItem
          Caption = 'Criar usu'#225'rio'
          OnClick = Criarusurio1Click
        end
      end
      object FazerRestaurarBackup1: TMenuItem
        Caption = 'Fazer / Restaurar Backup'
        OnClick = FazerRestaurarBackup1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Sair1: TMenuItem
        Caption = 'Sair'
        ShortCut = 32883
        OnClick = Sair1Click
      end
    end
    object Movimentao1: TMenuItem
      Caption = 'Movimenta'#231#227'o'
      object Venda1: TMenuItem
        Caption = 'Vendas'
        OnClick = Venda1Click
      end
    end
    object RElatrios1: TMenuItem
      Caption = 'Relat'#243'rio'
      object Estoque1: TMenuItem
        Caption = 'Estoque'
        OnClick = Estoque1Click
      end
      object Venda2: TMenuItem
        Caption = 'Venda por data'
        OnClick = Venda2Click
      end
      object Vendaporfuncionrio1: TMenuItem
        Caption = 'Venda por funcion'#225'rio'
        OnClick = Vendaporfuncionrio1Click
      end
      object Vendidoporproduto1: TMenuItem
        Caption = 'Venda por produto'
        OnClick = Vendidoporproduto1Click
      end
      object Relatriodoscadastros1: TMenuItem
        Caption = 'Relat'#243'rio dos cadastros'
        object Clientes2: TMenuItem
          Caption = 'Clientes'
          OnClick = Clientes2Click
        end
        object Convnio1: TMenuItem
          Caption = 'Conv'#234'nios'
          OnClick = Convnio1Click
        end
        object Fornecedor1: TMenuItem
          Caption = 'Fornecedores'
          OnClick = Fornecedor1Click
        end
        object Funcionrio1: TMenuItem
          Caption = 'Funcion'#225'rios'
          OnClick = Funcionrio1Click
        end
        object N3: TMenuItem
          Caption = '-'
        end
        object Combustvel1: TMenuItem
          Caption = 'Combust'#237'veis'
          OnClick = Combustvel1Click
        end
        object Produtos2: TMenuItem
          Caption = 'Produtos'
          OnClick = Produtos2Click
        end
        object Servios1: TMenuItem
          Caption = 'Servi'#231'os'
          OnClick = Servios1Click
        end
      end
    end
    object Utilitrios1: TMenuItem
      Caption = 'Utilit'#225'rios'
      object Calculadora1: TMenuItem
        Caption = 'Calculadora'
        OnClick = Calculadora1Click
      end
      object Calendrio1: TMenuItem
        Caption = 'Calend'#225'rio'
        OnClick = Calendrio1Click
      end
      object Calendrios1: TMenuItem
        Caption = 'Data e hora'
        OnClick = Calendrios1Click
      end
    end
    object Sobre1: TMenuItem
      Caption = 'Sobre'
      object Verso1: TMenuItem
        Caption = 'Vers'#227'o'
        OnClick = Verso1Click
      end
    end
  end
end
