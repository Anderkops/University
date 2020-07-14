//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Visualizador3D.res");
USEFORM("UTela.cpp", formTela);
USEUNIT("Grafico\Grafico.cpp");
USEUNIT("Grafico\matriz.cpp");
USEUNIT("Grafico\Ponto3D.cpp");
USEUNIT("Grafico\projecao.cpp");
USEUNIT("Grafico\transformacao.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TformTela), &formTela);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
