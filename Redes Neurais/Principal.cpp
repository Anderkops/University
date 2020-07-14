//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString arquivoredeneural="ArquivoRede.txt";
AnsiString arquivoresultadotreinamento="Treinamento.txt";
AnsiString arquivoresultadoteste="Teste.txt";
Double     matrizconf[5][5];
int        arrayCamadaOculta[2][1000];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

    Form1->StatusBar1->SimpleText = "Rede Neural Iniciada";
    arrayCamadaOculta[1][1] = 10;

    StringGrid4->ColCount=6;
    StringGrid4->RowCount=6;
    StringGrid4->Cells[0][1]="Linha 1";
    StringGrid4->Cells[0][2]="Linha 2";
    StringGrid4->Cells[0][3]="Linha 3";
    StringGrid4->Cells[0][4]="Linha 4";
    StringGrid4->Cells[0][5]="Linha 5";
    StringGrid4->Cells[1][0]="1";
    StringGrid4->Cells[2][0]="2";
    StringGrid4->Cells[3][0]="3";
    StringGrid4->Cells[4][0]="4";
    StringGrid4->Cells[5][0]="5";


    resetamatrizconf();
    imprimematrizconf();
    Form1->Arquivo_Teste = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
    AnsiString asTemp;
    if(Edit2->Text!="")
    {
     if((Edit2->Text.ToInt()+1)>1)
      {
       for(int i=0;i<Edit2->Text.ToInt();i++)
        {
         arrayCamadaOculta[1][i+1] = 10;
        }
      }
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
    int x = 0, i = 0, iteracao = 0;
    double dTemp;

    AnsiString asTemp;

    iteracao = 2000;                                    // 2000 Iteracoes.

    Form1->BP1.SetaCamadasOcultas(xCamadasOcultas);
    Form1->BP1.SetaNosDeEntrada(0,Form1->xNosDeEntrada);
    if(Form1->xCamadasOcultas!=0)
    for(i=0;i<Form1->xCamadasOcultas;i++)
      Form1->BP1.SetaNosDeEntrada(i+1,arrayCamadaOculta[1][i+1]);

    Form1->BP1.SetaNosDeEntrada(Form1->xCamadasOcultas+1,Form1->xNosDeSaida);
    Form1->BP1.SetaQtasAmostrasTreinar(Form1->xAmostras);
    Form1->BP1.SetaQtosTiposAmostrasTreinar(Form1->xAmostraEntrada);
    Form1->BP1.SetaQtasSaidasTreinar(Form1->xAmostraSaida);
    Form1->BP1.TaxaDeAprendizagem = 0.01;
    Form1->BP1.dnInertia          = 0.05;

    //Cria a rede neural
    Form1->BP1.CreateNeuralNetwork();
    int atualizar = 100;
    int cont = 0;
    for(x = 0;x<iteracao;x++)
     {
      Form1->BP1.Treina(); // Aprende uma vez.
     if(x%atualizar == 0) {

      if(cont == 0){ Form1->StatusBar1->SimpleText = " Treinando Neuronios ."; cont = 1;}
      else
      if(cont == 1){ Form1->StatusBar1->SimpleText = " Treinando Neuronios .."; cont = 2;}
      else
      if(cont == 2){ Form1->StatusBar1->SimpleText = " Treinando Neuronios ..."; cont = 0;}
      }
     }

     Form1->BP1.SalvaRedeNeural(arquivoredeneural);
     Form1->StatusBar1->SimpleText = "Carregue o Arquivo de teste e Clique em     [Executar Teste]      Para Testar";
     MessageBox(Form1->Handle,"Operação Completada","OK", MB_OK);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::BotaoReconhecimentoClick(TObject *Sender)
{
int i,j;
    AnsiString asTemp;
    double dTemp;
    char ei;

resetamatrizconf();

if(Form1->Arquivo_Teste == NULL)
  ShowMessage("ERRO: Escolha o Arquivo de teste");
  else
 {
        ifstream fin;
        ofstream fout;
        Form1->StatusBar1->SimpleText = " Teste de Dados de Entrada";
        fin.open(Form1->Arquivo_Teste.c_str());
        fout.open(arquivoresultadoteste.c_str());

        for(i=0;i<Form1->x2Amostras;i++)
        {

            for(j=0;j<x2NosDeEntrada;j++)
            {
                fin>>dTemp;
                if(x2NosDeEntrada>1) fin>>ei;
                BP2.InsereEntradasNaAmostraDeRec(j,dTemp);
            }

            //Step 3. Recall
            BP2.Reconhece();
            AnsiString auxiliar;
            //Show the recall result
            for(j=0;j<x2NosDeSaida;j++)
            {
                fin>>dTemp;
                if(BP2.cSaidas()>1) fin>>ei;
                fout<<dTemp;
                fout<<"\t";
                Double resultado= BP2.ImprimeResultadoReconhecimento(j);
                fout<<resultado;
                joganamatriz(dTemp,resultado);
                auxiliar=dTemp;
                auxiliar+="\t";
                auxiliar+=resultado;
            }
            fout<<"\n";
    }
    fin.close();
    fout.close();

    imprimematrizconf();
    ShowMessage("Teste Completado");
  }

}

//---------------------------------------------------------------------------


void TForm1::joganamatriz(Double classe, Double resultado)
{

int classeint=(int)classe;

if(resultado < 1.5)
        matrizconf[classeint-1][0]+=1;
else if((resultado >= 1.5)&&(resultado < 2.5))
        matrizconf[classeint-1][1]+=1;
else if((resultado >= 2.5)&&(resultado < 3.5))
        matrizconf[classeint-1][2]+=1;
else if((resultado >= 3.5)&&(resultado < 4.5))
        matrizconf[classeint-1][3]+=1;
else if(resultado >= 4.5)
        matrizconf[classeint-1][4]+=1;
}

//---------------------------------------------------------------------------

void TForm1::resetamatrizconf()
{
for(int x=0;x<5;x++)
        for(int y=0;y<5;y++)
                matrizconf[x][y]=0;
}

//---------------------------------------------------------------------------

void TForm1::imprimematrizconf()
{
for(int x=0;x<5;x++)
        for(int y=0;y<5;y++)
                StringGrid4->Cells[x+1][y+1]=(String)matrizconf[x][y];
}

//---------------------------------------------------------------------------

void __fastcall TForm1::AbrirArquivoTreinamento1Click(TObject *Sender)
{
     AnsiString asTemp;

    Form1->OpenDialog1->Title="Abrir arquivo de Treinamento";

    if(Form1->OpenDialog1->Execute())
    {
        Button4->Enabled=true;
        //Button5->Enabled=true;
        Form1->StatusBar1->SimpleText = "Arquivo Treinamento Aberto - Clique em     [Fazer Treinamento]     Para Iniciar";
        ifstream fin,fin2;    //stream de Arquivo

        asTemp=OpenDialog1->FileName;
        fin.open(asTemp.c_str());

        Form1->xNosDeEntrada=Form1->Edit1->Text.ToInt();
        Form1->xCamadasOcultas=Form1->Edit2->Text.ToInt();
        Form1->xNosDeSaida=Form1->Edit3->Text.ToInt();

        Form1->xAmostraEntrada.Libera();
        Form1->xAmostraSaida.Libera();
        int iamostras=0;
        char aux1[100];

        while(fin.good())
        {
            fin.getline(aux1,100);
            iamostras++;
        }
        fin.close();

        iamostras--;
        Form1->xAmostras=iamostras;

        Form1->xAmostraEntrada.Instancia(iamostras,Form1->xNosDeEntrada);
        Form1->xAmostraSaida.Instancia(iamostras,Form1->xNosDeSaida);

        int i,j;
        double dTemp;
        char ei;

        fin2.open(asTemp.c_str());
        for(i=0;i<iamostras;i++)
        {

            for(j=0;j<Form1->xNosDeEntrada;j++)
            {

                fin2>>dTemp;
                if(xNosDeEntrada>1) fin2>>ei;
                Form1->xAmostraEntrada.arrvalor[i][j]=dTemp;
            }

            for(j=0;j<Form1->xNosDeSaida;j++)
            {
                fin2>>dTemp;
                if(xNosDeSaida>1) fin2>>ei;
                Form1->xAmostraSaida.arrvalor[i][j]=dTemp;
            }

        }
        fin2.close();

        StringGrid2->ColCount=Form1->xNosDeEntrada+Form1->xNosDeSaida+1;
        StringGrid2->RowCount=Form1->xAmostras+1;

        for(i=0;i<Form1->xNosDeEntrada;i++)
            StringGrid2->Cells[i+1][0] = AnsiString(i);
        for(i=0;i<Form1->xNosDeSaida;i++)
            StringGrid2->Cells[Form1->xNosDeEntrada+i+1][0] = AnsiString(i);
        for(i=0;i<Form1->xAmostras;i++)
            StringGrid2->Cells[0][i+1] = AnsiString("Linha ")+AnsiString(i);

        for(i=0;i<Form1->xAmostras;i++)
        {
            for(j=0;j<Form1->xNosDeEntrada;j++)
                StringGrid2->Cells[j+1][i+1]=Form1->xAmostraEntrada.arrvalor[i][j];
            for(j=0;j<Form1->xNosDeSaida;j++)
                StringGrid2->Cells[Form1->xNosDeEntrada+j+1][i+1]=Form1->xAmostraSaida.arrvalor[i][j];
        }
        //mostrar o stringrid2

    }


}

//---------------------------------------------------------------------------

void __fastcall TForm1::AbrirArquivoTeste1Click(TObject *Sender)
{
    Form1->OpenDialog4->Title="Abrir amostra de arquivo";

        if(Form1->OpenDialog4->Execute())
        {
        Form1->Arquivo_Teste=Form1->OpenDialog4->FileName;

        Form1->StatusBar1->SimpleText = "Arquivo de Teste Aberto";

        BP2.AbreRedeNeural(arquivoredeneural);

        x2NosDeEntrada=BP2.cEntradas();
        x2NosDeSaida=BP2.cSaidas();

        ifstream fin,fin2;    //stream de Arquivo

        fin.open(Form1->Arquivo_Teste.c_str());

        Form1->x2AmostraEntrada.Libera();
        Form1->x2AmostraSaida.Libera();

        int iamostras=0;
        char aux1[100];

        while(fin.good())
        {
            fin.getline(aux1,100);
            iamostras++;
        }
        fin.close();

        iamostras--;
        Form1->x2Amostras=iamostras;

        Form1->x2AmostraEntrada.Instancia(iamostras,Form1->x2NosDeEntrada);
        Form1->x2AmostraSaida.Instancia(iamostras,Form1->x2NosDeSaida);

        int i,j;
        double dTemp;
        char ei;

        fin2.open(Form1->Arquivo_Teste.c_str());
        for(i=0;i<Form1->x2Amostras;i++)
        {

            for(j=0;j<x2NosDeEntrada;j++)
            {

                fin2>>dTemp;
                if(x2NosDeEntrada>1) fin2>>ei;
                Form1->x2AmostraEntrada.arrvalor[i][j]=dTemp;
            }

            for(j=0;j<x2NosDeSaida;j++)
            {
                fin2>>dTemp;
                if(x2NosDeSaida>1) fin2>>ei;
                Form1->x2AmostraSaida.arrvalor[i][j]=dTemp;
            }

        }
        fin2.close();

        StringGrid3->ColCount=Form1->x2NosDeEntrada+Form1->x2NosDeSaida+1;
        StringGrid3->RowCount=Form1->x2Amostras+1;

        for(i=0;i<Form1->x2NosDeEntrada;i++)
            StringGrid3->Cells[i+1][0]=AnsiString(i);
        for(i=0;i<Form1->x2NosDeSaida;i++)
            StringGrid3->Cells[Form1->x2NosDeEntrada+i+1][0]=AnsiString(i);
        for(i=0;i<Form1->x2Amostras;i++)
            StringGrid3->Cells[0][i+1]=AnsiString("Linha ")+AnsiString(i);

        for(i=0;i<Form1->x2Amostras;i++)
        {
            for(j=0;j<Form1->x2NosDeEntrada;j++)
                StringGrid3->Cells[j+1][i+1]=Form1->x2AmostraEntrada.arrvalor[i][j];
            for(j=0;j<Form1->x2NosDeSaida;j++)
                StringGrid3->Cells[Form1->x2NosDeEntrada+j+1][i+1]=Form1->x2AmostraSaida.arrvalor[i][j];
        }
     }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Sair1Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

