//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "USplash.h"
//---------------------------------------------------------------------------
USEFORM("Fontes\UPrincipal.cpp", formPrincipal);
USEFORM("Fontes\UCadastroMestre.cpp", formCadastroMestre);
USEFORM("Fontes\UCadastroConvenios.cpp", formCadastroConvenios);
USEFORM("Fontes\UModuloDados.cpp", dmBaseDados); /* TDataModule: File Type */
USEFORM("Fontes\ULocalizaMestre.cpp", formLocalizaMestre);
USEFORM("Fontes\ULocalizaConvenio.cpp", formLocalizaConvenio);
USEFORM("Fontes\UCadastroClientes.cpp", formCadastroClientes);
USEFORM("Fontes\ULocalizaCliente.cpp", formLocalizaCliente);
USEFORM("Fontes\UCadastroProdutos.cpp", formCadastroProdutos);
USEFORM("Fontes\UCadastroFuncionarios.cpp", formCadastroFuncionarios);
USEFORM("Fontes\ULocalizaFuncionario.cpp", formLocalizaFuncionario);
USEFORM("Fontes\UCadastroFornecedores.cpp", formCadastroFornecedores);
USEFORM("Fontes\ULocalizaFornecedor.cpp", formLocalizaFornecedor);
USEFORM("Fontes\ULocalizaProduto.cpp", formLocalizaProduto);
USEFORM("Fontes\UCadastroTanques.cpp", formCadastroTanques);
USEFORM("Fontes\UCadastroBombas.cpp", formCadastroBombas);
USEFORM("Fontes\UCadastroBicos.cpp", formCadastroBicos);
USEFORM("Fontes\UCalendario.cpp", formCalendario);
USEFORM("Fontes\UBackupRestore.cpp", formBackupRestore);
USEFORM("Fontes\USobre.cpp", formSobre);
USEFORM("Fontes\USplash.cpp", formSplash);
USEFORM("Fontes\UVendas.cpp", formVenda);
USEFORM("Fontes\UCadastroConvCli.cpp", formConvCli);
USEFORM("Fontes\UCriacaoUsuario.cpp", formCriacaoUsuario);
USEFORM("Fontes\URelVendaData.cpp", formRelVendaData);
USEFORM("Fontes\URelEstoque.cpp", formRelEstoque);
USEFORM("Fontes\URelVendaFunc.cpp", formRelVendaFunc);
USEFORM("Fontes\URelVendaProd.cpp", formRelVendaProd);
USEFORM("Fontes\URelCliente.cpp", formRelCliente);
USEFORM("Fontes\URelConvenio.cpp", formRelConvenio);
USEFORM("Fontes\URelFornecedor.cpp", formRelFornecedor);
USEFORM("Fontes\URelFuncionario.cpp", formRelFuncionario);
USEFORM("Fontes\URelCombustivel.cpp", formRelCombustivel);
USEFORM("Fontes\URelProduto.cpp", formRelProduto);
USEFORM("Fontes\URelServico.cpp", formRelServico);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 formSplash = new TformSplash (static_cast<void *>(NULL));
                 formSplash->Show();
                 Application->ProcessMessages();
                 Application->Title = "SisPosto";
                 Application->CreateForm(__classid(TformPrincipal), &formPrincipal);
                 Application->CreateForm(__classid(TdmBaseDados), &dmBaseDados);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------

